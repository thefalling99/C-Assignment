/*009 �Д�ηN������
������߅�L�܉򘋳������Εr�����Д�ԓ�����Ξ��g�ǡ��J�ǻ���ֱ�������Σ����Єe���� ���£� 1. ֱ�������Σ������Ѓɂ�߅��ƽ���͵�춵���߅��ƽ���� 2. �g�������Σ������Ѓɂ�߅��ƽ����С춵���߅��ƽ���� 3. �J�������Σ��΃�߅��ƽ���ʹ�춵���߅��ƽ���� ݔ����������
ݔ�����@ʾֱ��������(Right Triangle)���g��������(Obtuse Triangle)�� �J��������(Acute Triangle)��o������������(Not Triangle)��
���}��회�һ���\���function
int compute(int a, int b, int c); a, b, b ������������߅ �؂�ֵ 0:Not Triangle 1:Right Triangle 2:Obtuse Triangle 3:Acute Triangle
�yԇ�Y�ϣ�
input 5 12 13
output Right Triangle
input 3 4 5
output Right Triangle
input 1 2 3
output Not Triangle*/
#include<stdio.h>
#include<stdlib.h>
int compute(int a,int b,int c)
{
	if(!(a+b>c&&a+c>b&&b+c>a))
		return 0;
	if(a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a)
		return 1;
	if(a*a+b*b<c*c || a*a+c*c<b*b || b*b+c*c<a*a)
		return 2;
	if(a*a+b*b>c*c && a*a+c*c>b*b && b*b+c*c>a*a)
		return 3;
}
int main()
{
	int a,b,c,t;
	printf("Input a,b,c\n");
	scanf("%d %d %d",&a,&b,&c);
	t=compute(a,b,c);
	if(t==0)
		printf("Not Triangle\n");
	if(t==1)
		printf("Right Triangle\n");
	if(t==2)
		printf("Obtuse Triangle\n");
	if(t==3)
		printf("Acute Triangle\n");
    system("pause");
}
