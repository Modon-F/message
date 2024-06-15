//小白正在上楼梯，楼梯有n阶台阶，小白一次可以上1阶，2阶或者3阶台阶，实现一个方法，计算小白有多少种走完楼梯的方式。

//方法一
//#include <stdio.h>
//
//int f(int n) {
//    if (n < 0)return 0;
//    if (n == 0 || n == 1)return 1;//注意n为0时也为一种方式
//    if (n == 2)return 2;
//    return f(n - 1) + f(n - 2) + f(n - 3);
//}
//int main() {
//    int n;
//    scanf_s("%d", &n);
//    printf("%d\n", f(n));
//    return 0;
//}


//方法二
//#include <stdio.h>
//int f(int i)
//{
//	if (i == 1) return 1;
//	if (i == 2) return 2;
//	if (i == 3) return 3;
//	int dp[100] = {'\0'};
//	dp[1] = 1;
//	dp[2] = 2;
//	dp[3] = 4;
//	for (int j = 4; j <= i; j++)
//	{
//		dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
//	}
//	return dp[i];
//}
//
//int main(void)
//{
//	int i;
//	scanf_s("%d", &i);
//	int num = f(i);
//	printf("%d", num);
//	return 0;
//}