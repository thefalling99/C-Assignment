/*028. Ӌ�� N ߅����e (Ո�����n�� chapter 7, ���}��)
n ���c�B�� n ߅�Σ�n<=20�� �c�����˞� (x_(0), y_(0)), (x_(1), y_(1)),....,(x_(n), y_(n))��
Area = fabs(sum)/2
sum =   (x_(1)+x_(0))*(y_(1)-y_(0))+ ...       + (x_(i+1)+x_(i))*(y_(i+1)-y_(i))+ ...      + (x_(n)+x_(n-1))*(y_(n)-y_(n-1))
-------------------ݔ���f��: ÿ�ɂ����֞�һ�����ˣ�������-999�Y���� �������g�Զ�̖���_��
�� 28 �
c10401.txt
ݔ���f��: Ӌ���߅����e��С����һλ��
---------------------------------input: 4,0,4,7.5,7,7.5,7,3,9,0,7,0,-999
--------------------------------output: 25.5*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	float x[20],y[20];
	int i=0,sum=0;
	float area=0;
	printf("ݔ��n����c����(n<=20)\n");
	while(1)
	{
		scanf("%f,",&x[i]);
		if(x[i]==-999)
			break;
		scanf("%f,",&y[i]);
		i++;
	}
	for(int j=0;j<(i-1);j++)
	{
		sum+=(x[j+1]+x[j])*(y[j+1]-y[j]);
	}
	area=fabs(sum)/2;
	printf("%.1f\n",area);
    system("pause");
    return 0;
}

