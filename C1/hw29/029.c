/*029. 以陣列實做長整數的運算
將長整數儲存於一維陣列，長度為60位。 計算兩數的相加、相減、相乘。
輸入說明: 兩個小於60位數的數字
輸出說明 兩數的相加、相減、相乘結果
input: 186978448 484312244
output: 671290692 -297333796 90555951730517312*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 60
void add(char s1[],char s2[])
{
	int i,j,len1,len2;
	int num1[M]={0},num2[M]={0};
	len1=strlen(s1);
	len2=strlen(s2);
	//把数字倒过来，num1[0]保存最低位
	for(i=len1-1,j=0;i>=0;i--)
		num1[j++]=s1[i]-'0';
	for(i=len2-1,j=0;i>=0;i--)
		num2[j++]=s2[i]-'0';
	for(i=0;i<M;i++)
	{
		num1[i]+=num2[i];
		if(num1[i]>9)
		{
			num1[i]-=10;
			num1[i+1]++;
		}
	} 
	//找到第一个不是0的数的位置
	for(i=M-1;(i>=0)&&(num1[i]==0);i--)
		;
	if(i>=0)
	{
		for(;i>=0;i--)
			printf("%d",num1[i]);
		printf("\n");
	}
	else
		printf("0\n"); 
}
void sub(char s1[],char s2[])
{
	int i,j,len1,len2;
	int num1[M]={0},num2[M]={0};
	len1=strlen(s1);
	len2=strlen(s2);
	//把数字倒过来，num1[0]保存最低位
	for(i=len1-1,j=0;i>=0;i--)
		num1[j++]=s1[i]-'0';
	for(i=len2-1,j=0;i>=0;i--)
		num2[j++]=s2[i]-'0';
	for(i=0;i<M;i++)
	{
		if(num1[i]<num2[i])
		{
			num1[i]=num1[i]+10-num2[i];
			num1[i+1]--;
		}
		else
		{
			num1[i]=num1[i]-num2[i];
		}
	} 
	//找到第一个不是0的数的位置
	for(i=M-1;(i>=0)&&(num1[i]==0);i--)
		;
	if(i>=0)
	{
		for(;i>=0;i--)
			printf("%d",num1[i]);
		printf("\n");
	}
	else
		printf("0\n"); 
}
void mul(char s1[],char s2[])
{
	int i,j,len1,len2;
	int a[M+10]={0},b[M+10]={0},c[M*2+10]={0};
	len1=strlen(s1);
	len2=strlen(s2);
	//把数字倒过来，num1[0]保存最低位
	for(i=len1-1,j=0;i>=0;i--)
		a[j++]=s1[i]-'0';
	for(i=len2-1,j=0;i>=0;i--)
		b[j++]=s2[i]-'0';
	for(i=0; i<len2; i++)//用第二个数乘以第一个数,每次一位
        for(j=0;j<len1; j++)
            c[i+j]+= b[i]*a[j]; //先乘起来,后面统一进位
	for(i=0;i<M*2; i++)//循环统一处理进位问题
        if(c[i]>=10)
        {
            c[i+1]+=c[i]/10;
            c[i]%=10;
        }
  
    for(i=M*2; (c[i]==0)&&(i>=0);i--);//跳过高位的0
    if(i>=0)
	{
		for(;i>=0;i--)
			printf("%d",c[i]);
		printf("\n");
	}
	else
		printf("0\n"); 
}
int main()
{
	char s1[M],s2[M];
	printf("输入两组数字（少于60位）\n");
	scanf("%s %s",s1,s2);
	add(s1,s2);
	sub(s1,s2);
	mul(s1,s2);
    system("pause");
    return 0;
}

