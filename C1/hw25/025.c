/*025.
(此題不使用陣列，必須使用指標)
程式碼必須使用以下 function 定義，計算兩個分數的相加。
void add(int n1, int d1, int n2, int d2, int *numerator, int *denominator);
第 23 頁
c10401.txt
n1:           第一個數的分子 n1:           第一個數的分母 n1:           第二個數的分子 n1:           第二個數的分母 *numerator:   相加結果的分子 *deniminator: 相加結果的分母
程式碼必須使用以下 function 定義，計算兩個分數的相乘。
void mul();
int multiply(int n1, int d1, int n2, int d2, int *numerator, int *denominator);
n1:           第一個數的分子 n1:           第一個數的分母 n1:           第二個數的分子 n1:           第二個數的分母 *numerator:   相乘結果的分子 *deniminator: 相乘結果的分母
-------------------
輸入說明:
輸入二行，每一行代表一個分數
---------------輸出說明:
輸出分數相加結果 輸出分數相乘結果
若有輸入分數的分母或分子為0，則輸出ERROR。 若分數大於1，則分數部分要加括號。 若為負數，負號在最前面。
---------------Input
1/2 2/3
Output
1(1/6) 1/3
-----------Input
0/2 4/5
第 24 頁
c10401.txt
Output
ERROR ERROR
-------------Input -1/2 4/5
Output 3/10 -2/5
--------Input -1/2 -4/5
Output -1(3/10) 2/5*/
#include<stdio.h>
#include<stdlib.h>
void f(int* a,int *b)
{
    int j=0;
    int aa=0,bb=0;
    if(*a<0)
    {
        *a=-*a;
        aa=1;
    }
    if(*b<0)
    {
        *b=-*b;
        bb=1;
    }
    for (j= 2;j<= *a; j++)
    {
        if (*a % j== 0 && *b % j == 0)
        {
            *a/= j;
            *b /= j;
            j--;
            continue;
        }
    }
    if(aa==1)
    {
        *a=-*a;
    }
    if(bb==1)
    {
        *b=-*b;
    }
}
void add(int n1, int d1, int n2, int d2, int *numerator, int *denominator)
{
	int carry;
	if(n1==0||n2==0||d1==0||d2==0)
	{
		printf("ERROR\n");
		return;
	}
	*numerator=n1*d2+d1*n2;
	*denominator=d1*d2;
	if(*numerator>*denominator)
	{
		carry=*numerator/ *denominator;
		*numerator=*numerator%*denominator;
		f(numerator,denominator);
		printf("%d(%d/%d)\n",carry,*numerator,*denominator);
	}
	else
    {
        f(numerator,denominator);
        printf("%d/%d\n",*numerator,*denominator);
    }
}
void multiply(int n1, int d1, int n2, int d2, int *numerator, int *denominator)
{
	int carry;
	if(n1==0||n2==0||d1==0||d2==0)
	{
		printf("ERROR\n");
		return;
	}
	*numerator=n1*n2;
	*denominator=d1*d2;
	if(*numerator>*denominator)
	{
		carry=*numerator/ *denominator;
		*numerator=*numerator%*denominator;
		f(numerator,denominator);
		printf("%d(%d/%d)\n",carry,*numerator,*denominator);
	}
	else
    {
        f(numerator,denominator);
        printf("%d/%d\n",*numerator,*denominator);
    }
}
int main()
{
	int n1,d1,n2,d2;
	//相乘结果的分子，相乘结果的分母
	int numerator,denominator;
	printf("Input n1/d1\n");
	scanf("%d/%d",&n1,&d1);
	printf("Input n2/d2\n");
	scanf("%d/%d",&n2,&d2);
	add(n1,d1,n2,d2,&numerator,&denominator);
	multiply(n1,d1,n2,d2,&numerator,&denominator);
    system("pause");
    return 0;
}

