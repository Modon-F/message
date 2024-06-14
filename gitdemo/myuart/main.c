#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "uartTool.h"
#include "garbage.h"
#include "pwm.h"
#include "ole.h"

#define WGET_CMD "sudo wget http://127.0.0.1:8080/?action=snapshot -O /tmp/garbage.jpg"

void* function1(void* arg);
void* function2(void* arg);
void* function3(void* arg);
void* function4(void* arg);
void* function5(void* arg);
//互斥锁
pthread_mutex_t mutex;
//条件变量
pthread_cond_t cond;
//用于存放信号
unsigned char flag[6] = { 0xAA, 0X55, 0x00, 0x00, 0x55, 0xAA };
//存放管道标识符
int fd;
//能使用吗

int isProcessRunning(char *processName) {
    //运行正常将1返回,运行不正常将0返回,并将打印内容存放在buffer中
    char command[256];
    sprintf(command, "ps -ef | grep %s | grep -v grep", processName);

    FILE *fp = popen(command, "r");
    if (fp == NULL) 
    {
        perror("popen failed");
        return 1;
    }
    char buffer[256];
    fgets(buffer, sizeof(buffer), fp);
    //能读取到信息,而且是乱码,所以只能通过正确的信息,来判断是否执行成功
    if(buffer[0] != 'o')
    {
        pclose(fp);
        return 1;
    }
    else
    {
        pclose(fp);
        return 0;
    }
}

// int main (int argc, char** argv)
// {
//    //编译gcc -o test *c *.h -I /usr/include/python3.10/ -lpython3.10 -lwiringPi
//    /*
//    1.检测mjpg有没有运行
//    1.初始化阿里云接口
//    2.初始化串口
//    3.接收串口消息
//        (1)先传入启动语音模块的信息
//        (2)然后使用摄像头拍照
//        (3)拍完照识别垃圾类型
//        (4)返回信息,使用串口接收
//        (5)根据接收的信息,往串口发送指定数据,进行语音播报
//    */
//    //用于存放语音模块返回值
//    unsigned char flag[6] = {0xAA, 0X55, 0x00, 0x00, 0x55, 0xAA};
//    //int i;
//    //存放调用阿里云垃圾的返回值
//    char* category = NULL;
//    //初始化wiringpi库函数
//    wiringPiSetup();
//    //1.检测mjpg有没有运行
//    if(isProcessRunning("mjpg.sh"))
//    {
//        printf("mjpg.sh没有成功运行\n");
//        exit(-1);        
//    }
//    else
//        puts("mjpg.sh成功运行");
//    int fd = myserialOpen("/dev/ttyS5", 115200);
//    garbage_init();
//    while(1)
//    {
//        serialGetstring (fd, flag);
//        //1.判断有没有接收到开启信息
//        puts("i  coning");
//        if(flag[2] == 0x46)
//        {
//            //2.拍照
//            system(WGET_CMD);
//            //3.调用阿里云识别
//            category = garbage_category(category);
           
//            //4.接收识别结果
//            //5.发送标识实现语音播报 
//            if(strstr(category,"干垃圾"))
//                flag[2] = 0x41;
//            else if(strstr(category,"湿垃圾"))
//                flag[2] = 0x42;
//            else if(strstr(category,"可回收垃圾"))
//                flag[2] = 0x43;
//            else if(strstr(category,"有害垃圾"))
//                flag[2] = 0x44;
//            else
//                flag[2] = 0x45;
//            serialSendstring(fd, flag, 6);
//            pwm_wirte(7);
//            printf("i hehe\n");
//            pwm_stop(7);
//            flag[2] = 0x00;
//            remove("/tmp/garbage.jpg");
//            category = NULL;
//        }
//    }
//    garbage_final();
//    if(category)
//        free (category);
//    return 0;
// }

int main(void)
{   
    //2.串口初始化
    fd = myserialOpen("/dev/ttyS5", 115200);
    //初始化orangepi
    wiringPiSetup();
    //1.Python接口初始化
    garbage_init();
    //互斥锁初始化
    if(pthread_mutex_init(&mutex, NULL))
    {
        printf("pthread_mutex_init failed");
        return 1;
    }
    //三个线程
    int repthread1, repthread2, repthread3;
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
    repthread1 = pthread_create(&thread1, NULL, function1, NULL);
    if(0 != repthread1)
    {
        printf("pthread_create1 failed");
        exit(-1);
    }
    repthread2 = pthread_create(&thread2, NULL, function2, NULL);
    if (0 != repthread2)
    {
        printf("pthread_create2 failed");
        exit(-1);
    }
    repthread3 = pthread_create(&thread3, NULL, function3, NULL);
    if(0 != repthread3)
    {
        printf("pthread_create3 failed");
        exit(-1);
    }
    //初始化条件变量
    int repthread_cond_init =  pthread_cond_init(&cond, NULL);
    if(0 != repthread_cond_init)
    {
        puts("repthread_cond_init failed");
        exit(-1);
    }
    printf("主线程跑起来了\n");
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    //解锁互斥锁,为了销毁互斥锁做准备
    
    pthread_mutex_unlock(&mutex);
    //销毁互斥锁
    if(pthread_mutex_destroy(&mutex))
    {
        puts("pthread_mutex_destroy failed");
        exit(-1);
    }
    //销毁条件变量
    if(pthread_cond_destroy(&cond))
    {
        puts("pthread_cond_destroy failed");
        exit(-1);
    }
}
//线程1要执行的函数,语音模块数据线程
void* function1(void* arg)
{
    //在这里接收外部信号,如果接收到语音模块启动信号,则发送signal,让主线程操作
    while (1)
    {
        serialGetstring (fd, flag);
        if (0x46 == flag[2])
        {
            //发送信号
            if(pthread_cond_signal(&cond))
            {
                puts("pthread_cond_signal failed");
                exit(-1);
            }
            //解锁互斥锁,让主线程跑起来
            flag[2] = 0x00;
        }
    }
    //终结当前进程
    pthread_exit(NULL);
}
//线程2要执行的函数,为后续网络线程做准备
void* function2(void* arg)
{
    //创建一个套接字 返回一个整数，表示新的套接字描述符
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == sock)
    {
        puts("socket failed");
        exit(-1);
    }
    
    //将套接字（socket）与一个本地地址（IP 地址和端口）绑定的系统调用
    struct sockaddr_in addrsock;    //指向 `struct sockaddr` 结构的指针，该结构包含了要绑定的地址。
    //清空变量内容
    memset(&addrsock,0,sizeof(addrsock));
    addrsock.sin_family = AF_INET;
    //套接字所绑定的ip 端口
    addrsock.sin_port = htons(9999);
    inet_aton("192.168.31.58",&addrsock.sin_addr);
    socklen_t addrlen = sizeof(addrsock);  //`addr` 指向的结构的长度，以字节为单位。
    int rebind = bind(sock, (const struct sockaddr*)&addrsock, addrlen);
    if (-1 == rebind)
    {
        puts("bind failed");
        exit(-1);
    }

    //在服务器端告知内核准备好接受来自客户端的连接请求。
    int relisten = listen(sock, 10);
    if (-1 == relisten)
    {
        puts("listen failed");
        exit(-1);
    }

    //`accept` 函数会阻塞等待直到有客户端的连接请求到达。
    //当有新的连接请求时，`accept` 函数将创建一个新的套接字用于与客户端通信，
    //而原始的监听套接字仍然保持开放，继续接受其他客户端的连接请求。
    struct sockaddr_in Caddr;
    socklen_t Caddrlen = (socklen_t)sizeof(Caddr);
    int ac_sockfd = accept(sock, (struct sockaddr*)&Caddr, &Caddrlen);
    if (-1 == ac_sockfd)
    {
        puts("accept failed");
        exit(-1);
    }

    //
    char buff[128] = {'\0'};
    while(1)
    {
        //接收信息 返回收到的字节数
        ssize_t received = recv(ac_sockfd, &buff, sizeof(buff), 0);
        printf("%s", buff);
        //如果在这里得到的字符是open,就给xx发送信号 发一个字符收一个字符操了
        if(strstr(buff,"open"))
        {
            if(pthread_cond_signal(&cond))
            {
                puts("pthread_cond_signal failed");
                exit(-1);
            }
            //解锁互斥锁,让主线程跑起来
            flag[2] = 0x00;
        }
        memset(buff, 0, sizeof(buff));
        //发送信息
        //send(ac_sockfd, const void *buf, size_t len, int flags);
        
    }
    close(ac_sockfd);
    // 关闭监听套接字
    close(sock); 
    pthread_exit(NULL);
}

//用来跑原来主程序的内容
void* function3(void* arg)
{
    //存放语音调用返回值
    char* category = NULL;
    //锁住主线程,为了使用wait的前置条件
    while(1)
    {
        pthread_mutex_lock(&mutex);
        //解锁了主线程,但是阻塞在这里等待条件变量
        pthread_cond_wait(&cond, &mutex);
        pthread_mutex_unlock(&mutex);
        //gcc -o test main.c garbage.c uartTool.c pwm.c garbage.h uartTool.h pwm.h -I /usr/include/python3.10/ -lpython3.10 -lwiringPi      
        //1.检测mjpg有没有运行 ps -ef | grep mjpg.sh | grep -v grep
        if(isProcessRunning("mjpg.sh"))
        {
            printf("mjpg.sh没有成功运行\n");
            exit(-1);        
        }
        else
            puts("mjpg.sh成功运行");

        puts("拍照");
        system(WGET_CMD);
        puts("执行阿里云垃圾识别接口");
        category = garbage_category(category);
        //4.接收识别结果

        //5.发送标识实现语音播报 
        puts("语音播报类别线程");
        printf("%s", category);
        if(strstr(category,"干垃圾"))
        {
            flag[2] = 0x41;
            garbage_flag = 1; 
        }
        else if(strstr(category,"湿垃圾"))
        {
            flag[2] = 0x42;
            garbage_flag = 2; 
        }
        else if(strstr(category,"可回收垃圾"))
        {
            flag[2] = 0x43;
            garbage_flag = 3; 
        }
        else if(strstr(category,"有害垃圾"))
        {
            flag[2] = 0x44;
            garbage_flag = 4; 
        }
        else
        {
            flag[2] = 0x45;
            garbage_flag = 5; 
        }
        serialSendstring(fd, flag, 6);
        flag[2] = 0x00;
        remove("/tmp/garbage.jpg");
        category = NULL;
        int repthread4, repthread5;
        pthread_t thread4;
        pthread_t thread5;
        repthread4 = pthread_create(&thread4, NULL, function4, NULL);
        if(0 != repthread4)
        {
            printf("pthread_create4 failed");
            exit(-1);
        }
        repthread5 = pthread_create(&thread5, NULL, function5, NULL);
        if(0 != repthread5)
        {
            printf("pthread_create5 failed");
            exit(-1);
        }
       // pthread_join(thread4, NULL);
        //pthread_join(thread5, NULL);
    }
}
//舵机
void* function4(void* arg)
{
    pthread_detach(pthread_self());
    puts("舵机函数");
    pwm_wirte(5);
    pwm_stop(5);
    //pthread_exit(NULL);
}
//oled
void* function5(void* arg)
{
    pthread_detach(pthread_self());
    puts("oled函数");
    oled();
    //pthread_exit(NULL);
}