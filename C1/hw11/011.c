/*011.�Д�ηN������
������߅�L�܉򘋳������Εr�����Д�ԓ�����Ξ���������(Regular Triangle)�� ����������(Isoscceles Triangle )���g�ǡ��J�ǻ���ֱ�������Σ� ���Єe�������£�
�����Д��Ƿ���������Ρ�ֱ�������Ρ����������Ρ� �����]�з��ϣ����Д��Ƿ���J�ǻ��g�ǡ�
1. ֱ�������Σ���߅��ƽ���͵�����L߅��ƽ���� 2. �g�������Σ���߅��ƽ����С����L߅��ƽ����������һ���Ǵ��90�ȡ� 3. �J�������Σ���߅��ƽ���ʹ�����L߅��ƽ�������ЃȽǾ����J�ǣ�С�90�ȡ�
ݔ���f��
ݔ�딵������������߅��ֱ�� -1 ֹͣݔ�롣 ����߅������������
scanf �÷�Ո���� http://www.cplusplus.com/reference/cstdio/scanf/
ݔ���f��
ӡ�� ֱ��������(Right Triangle)�� ��������(Regular Triangle)�� ����������(Isoscceles Triangle)�� �g��������(Obtuse Triangle)�� �J��������(Acute Triangle)�� ��o������������(Not a Triangle)��
input
�� 9 �
c10401.txt
4 12 13 5 12 13 1 2 3 3 4 5 2 2 2 2 2 3 -1
output
Obtuse Triangle Right Triangle Not a Triangle Right Triangle Regular Triangle Isoscceles Triangle
input:
80 90 160 5 5 5 7 7 6 30 50 40 1 8 7 30 31 29 -1
Output:
Obtuse Triangle Regular Triangle Isoscceles Triangle Right Triangle Not a Triangle Acute Triangle*/
#include<stdio.h>
#include<stdlib.h>
void f(int a,int b,int c)
{
	if(!(a+b>c&&a+c>b&&b+c>a))
    {
        printf("Not a Triangl\n");
        return;
    }
	if(a==b&&a==c&&b==c)
    {
        printf("Regular Triangl\n");
        return;
    }
	if(a==b||a==c||b==c)
    {
        printf("Isoscceles Triangl\n");
        return;
    }
	if(a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a)
    {
        printf("Right Triangl\n");
        return;
    }
	if(a*a+b*b<c*c || a*a+c*c<b*b || b*b+c*c<a*a)
    {
        printf("Obtuse Triangle\n");
        return;
    }
	if(a*a+b*b>c*c && a*a+c*c>b*b && b*b+c*c>a*a)
    {
        printf("Acute Triangl\n");
        return;
    }
}
int main()
{
	int a[10],b[10],c[10],t=0,n=1,in=0;
	while(in!=-1)
	{
		printf("Input number\n");
		scanf("%d",&in);
		if(n%3==1)
			a[t]=in;
		else if(n%3==2)
			b[t]=in;
		else if(n%3==0)
		{
			c[t]=in;
			t++;
		}
		n++;
	}
	for(int i=0;i<t;i++)
	{
		f(a[i],b[i],c[i]);
	}
	system("pause");
	return 0;
}
