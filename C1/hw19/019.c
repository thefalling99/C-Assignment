/*Ӌ����θ��w����e
ݔ��ɂ����εČ��ǃ��cx��y���� Ӌ��ɂ������دB����e����� ����ݔ�� 1 5 9 7 2 5 10 11 ��ʾ һ�����ε������Ќ��ǃ��c��(1,5)�c(9,7) ��һ�����ε������Ќ��ǃ��c��(2,5)�c(10,11)
���دB��e��(2,5)�c(9,7)���ɵľ��� ������e��(9-2)*7(-5)=14 input: 1 5 9 7 2 5 10 11
output: 14*/
#include<stdio.h>
#include<stdlib.h>
int min(int a,int b)
{
	return a<b?a:b;
} 
int max(int a,int b)
{
	return a>b?a:b;
} 
int square(int x1,int x2,int x3,int x4,int y1,int y2,int y3,int y4)
{
	if((min(x2,x4)-max(x1,x3)>0)&&(min(y2,y4)-max(y1,y3)>0))
	{
		return ((min(x2,x4)-max(x1,x3))*(min(y2,y4)-max(y1,y3)));
	}
	else
		return 0;
}
int main()
{
	int x1,x2,x3,x4,y1,y2,y3,y4,r;
	printf("Input ��һ�����ε�һ������\n");
	scanf("%d %d",&x1,&y1);
	printf("Input ��һ�����εڶ�������\n");
	scanf("%d %d",&x2,&y2);
	printf("Input �ڶ������ε�һ������\n");
	scanf("%d %d",&x3,&y3);
	printf("Input �ڶ������εڶ�������\n");
	scanf("%d %d",&x4,&y4);
	r=square(x1,x2,x3,x4,y1,y2,y3,y4);
	if(r)
		printf("%d\n",r);
	else
		printf("���ص�!\n"); 
	system("pause");
	return 0;
}
