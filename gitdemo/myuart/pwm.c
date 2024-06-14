#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
//#define PWM_GARBAGE 0
//根据公式：PWMfreq = 1 x 10^6 / (100 x range) ，要得到PWM频率为50Hz，则range为200，即周期分为200步，控制精度相比硬件PWM较低。
void pwm_wirte(int pwm_pin)
{
    //让pwm_pin这个引脚可以输出电平信号
    pinMode(pwm_pin, OUTPUT);
    //设置频率为50hz,周期为20ms,每10代表1ms
    softPwmCreate(pwm_pin, 0, 200);
    //1ms的高定平,也就是45°
    softPwmWrite(pwm_pin, 20);
    delay(500);
    softPwmStop(pwm_pin);
    return;    
}
void pwm_stop(int pwm_pin)
{
    //让pwm_pin这个引脚可以输出电平信号
    pinMode(pwm_pin, OUTPUT);
    //设置频率为50hz,周期为20ms,每10代表1ms
    softPwmCreate(pwm_pin, 0, 200);
    //1ms的高定平,也就是0°
    softPwmWrite(pwm_pin, 5);
    delay(500);
    softPwmStop(pwm_pin);
    return;    
}