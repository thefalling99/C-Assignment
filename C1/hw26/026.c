/*026.�����Ľ�����
Ո�OӋ��ʽ�����Ãɂ�һ�S������Ѓ���ɂ����������� A, B �� �ɂ����� A, B ����д�С�� 20�������� 1~100�� ��ʽ���ܞ飺 (1) ��������Ԫ�أ�ݔ��һ�����cһ����������������Ԫ���cԓ���σ�Ԫ�������}��    �t�o�������� (2) �h������Ԫ�أ�ݔ��һ�����cһ���������������ПoԓԪ�أ��o���h���� (3) Ӌ�㼯���Ƿ�ռ��ϡ� (4) Ӌ��ɂ����ϵĽ����� (5) Ӌ��ɂ����ϵ����� (6) Ӌ�㼯���Ƿ����һ�����ϵ��Ӽ��ϡ�
-----------------------------ݔ���f��:
ÿһ�е�һ����ݔ������ָ���x헣����x����: 0: �Y��exit 1: ��� A��ݔ�� A �� B �ă��ݡ� 2: ��� B��ݔ�� A �� B �ă��ݡ� 3: ����Ԫ�ص� A�������һ����������Ҫ�����Ԫ�أ�   ݔ�� A �� B �ă��ݡ� 4: ����Ԫ�ص� B�������һ����������Ҫ������Ԫ�أ�   ݔ�� A �� B �ă��ݡ�
�� 25 �
c10401.txt 5: �� A �h��һ��Ԫ�أ������һ����������Ҫ�h����Ԫ�أ�   ݔ�� A �� B �ă��ݡ� 6: �� B �h��һ��Ԫ�أ������һ����������Ҫ�h����Ԫ�ء�    ݔ�� A �� B �ă��ݡ� 7: ݔ�� A, B ���� 8: ݔ�� A, B ������ 9: ݔ�� A �Ƿ�� B ���Ӽ��ϣ����Ǆtݔ�� 1 ����tݔ�� 0��
ݔ���f��:
ݔ�����ϸ�ʽ �������Q:[����Ԫ��,����Ԫ��,...]�����g�]�пհף� Ԫ���������ݔ��������� �����c����Ԫ���������A��Ԫ���������B��Ԫ����� ÿһָ��ݔ��һ�С�
---------------Input: 3 4 3 7 4 8 4 9 5 4 6 8 3 8 7 8 9 0
Output: A:[4,]B:[] A:[4,7,]B:[] A:[4,7,]B:[8,] A:[4,7,]B:[8,9,] A:[7,]B:[8,9,] A:[7,]B:[9,] A:[7,8,]B:[9,] [7,8,9,] [] 0
*/
#include<stdio.h>
#include<stdlib.h>
int arear=0,brear=0;
int a[20],b[20];
void prtA()
{
	printf("a:[");
	for(int i=0;i<arear;i++)
		printf("%d,",a[i]);
	printf("]\n");
}
void prtB()
{
	printf("b:[");
	for(int i=0;i<brear;i++)
		printf("%d,",b[i]);
	printf("]\n");
}
void case1()
{
	printf("a:[]");
	arear=0;
	prtB();
}
void case2()
{
	printf("b:[]");
	brear=0;
	prtA();
}
void case3(int n)
{
	a[arear++]=n;
	prtA();
	prtB();
}
void case4(int n)
{
	b[brear++]=n;
	prtA();
	prtB();
}
void case5(int n)
{
	for(int i=0;i<arear;i++)
	{
		if(a[i]==n)
		{
			for(int j=i;j<(arear-1);j++)
			{
				a[j]=a[j+1];
			}
			arear--;
			break;
		}
	}
	prtA();
	prtB();
}
void case6(int n)
{
	for(int i=0;i<brear;i++)
	{
		if(b[i]==n)
		{
			for(int j=i;j<(brear-1);j++)
			{
				b[j]=b[j+1];
			}
			brear--;
			break;
		}
	}
	prtA();
	prtB();
}
void case7()
{
	printf("[");
	for(int i=0;i<arear;i++)
		printf("%d,",a[i]);
	for(int i=0;i<brear;i++)
		printf("%d,",b[i]);
	printf("]\n");
}
void case8()
{
	int i,j;
	printf("[");
	for(i=0;i<arear;i++)
	{
		for(j=0;j<brear;j++)
		{
			if(a[i]==b[j])
			{
				printf("%d,",a[i]);
			}
		}
	}
	printf("]\n");
}
int main()
{
	int c1,c2;
	while(1)
	{
		printf("ݔ������a\n");
		scanf("%d",&c1);
		if(c1==0)
			break;
		if(c1>=3&&c1<7)
		{
			printf("ݔ�딵��\n");
			scanf("%d",&c2);
		}
		switch(c1)
		{
			case 0:exit(1);
			//���a,���a��b������
			case 1:case1();break;
			//���b,���a��b������
			case 2:case2();break;
			//����Ԫ�ص�A
			case 3:case3(c2);break;
			//����Ԫ�ص�B
			case 4:case4(c2);break;
			//��Aɾ��Ԫ��
			case 5:case5(c2);break;
			//��Bɾ��Ԫ��
			case 6:case6(c2);break;
			//���A,B����
			case 7:case7();break;
			//���A,B����
			case 8:case8();break;
			case 9:printf("0\n");break;
		}
	}
    system("pause");
    return 0;
}

