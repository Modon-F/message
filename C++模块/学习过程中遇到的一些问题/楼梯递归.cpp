//С��������¥�ݣ�¥����n��̨�ף�С��һ�ο�����1�ף�2�׻���3��̨�ף�ʵ��һ������������С���ж���������¥�ݵķ�ʽ��

//����һ
//#include <stdio.h>
//
//int f(int n) {
//    if (n < 0)return 0;
//    if (n == 0 || n == 1)return 1;//ע��nΪ0ʱҲΪһ�ַ�ʽ
//    if (n == 2)return 2;
//    return f(n - 1) + f(n - 2) + f(n - 3);
//}
//int main() {
//    int n;
//    scanf_s("%d", &n);
//    printf("%d\n", f(n));
//    return 0;
//}


//������
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