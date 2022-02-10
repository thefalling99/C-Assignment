/*025.
(���}��ʹ����У����ʹ��ָ��)
��ʽ�a���ʹ������ function ���x��Ӌ��ɂ��֔�����ӡ�
void add(int n1, int d1, int n2, int d2, int *numerator, int *denominator);
�� 23 �
c10401.txt
n1:           ��һ�����ķ��� n1:           ��һ�����ķ�ĸ n1:           �ڶ������ķ��� n1:           �ڶ������ķ�ĸ *numerator:   ��ӽY���ķ��� *deniminator: ��ӽY���ķ�ĸ
��ʽ�a���ʹ������ function ���x��Ӌ��ɂ��֔�����ˡ�
void mul();
int multiply(int n1, int d1, int n2, int d2, int *numerator, int *denominator);
n1:           ��һ�����ķ��� n1:           ��һ�����ķ�ĸ n1:           �ڶ������ķ��� n1:           �ڶ������ķ�ĸ *numerator:   ��˽Y���ķ��� *deniminator: ��˽Y���ķ�ĸ
-------------------
ݔ���f��:
ݔ����У�ÿһ�д���һ���֔�
---------------ݔ���f��:
ݔ���֔���ӽY�� ݔ���֔���˽Y��
����ݔ��֔��ķ�ĸ����Ӟ�0���tݔ��ERROR�� ���֔����1���t�֔�����Ҫ����̖�� ����ؓ����̖ؓ����ǰ�档
---------------Input
1/2 2/3
Output
1(1/6) 1/3
-----------Input
0/2 4/5
�� 24 �
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
	//��˽���ķ��ӣ���˽���ķ�ĸ
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

