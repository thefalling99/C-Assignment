/*018.
ݔ���һ���������Q��ݔ���D�ηN� ݔ��ڶ����������Q��ݔ�����Д��� �հ���. ݔ����
..1 .121 12321 .121 ..1
7531357 .53135 ..313 ...1
ݔ���f����
ÿһ�M�ɂ����֣�ݔ��-1�Y������ݔ�롣 ��һ����������1�����Δ��֣�2�������Δ��֣����Nݔ����鲻�Ϸ��� �ڶ������������Д� N�� ��һ�N�D�κϷ�ݔ�� N ���攵��1<=N<=18�� �ڶ��N�D�κϷ�ݔ�룬1<=N<=5�����Nݔ����鲻�Ϸ��� ���Ϸ�ݔ�룬�tݔ�� E��
ݔ���f���� Ո��������ݔ����
Sample Input1:
1,9 1,13 -1
Sample Output:
....1
�� 15 �
c10401.txt
...121 ..12321 .1234321 123454321 .1234321 ..12321 ...121 ....1
......1 .....121 ....12321 ...1234321 ..123454321 .12345654321 1234567654321 .12345654321 ..123454321 ...1234321 ....12321 .....121 ......1
Sample Input2:
1,22 1,5 -1
Sample Output:
E
..1 .121 12321 .121 ..1
Sample Input3:
2,5 2,4 2,2 2,12 -1
Sample Output:
975313579 .7531357 ..53135 ...313 ....1
�� 16 �
c10401.txt
7531357 .53135 ..313 ...1
313 .1
E*/
#include<stdio.h>
#include<stdlib.h>
void output1(int n)
{
	int i,j,temp;
	for(i=1;i<=n/2+1;i++)
	{
		temp=n/2+1-i;
		while(temp--)printf(".");
		for(j=1;j<=i;j++)printf("%d",j);
		for(j=i-1;j>=1;j--)printf("%d",j);
		printf("\n");
	}
	for(i=n/2;i>=1;i--)
	{
		temp=(n/2)-(i-1);
		while(temp--)printf(".");
		for(j=1;j<=i;j++)printf("%d",j);
		for(j=i-1;j>=1;j--)printf("%d",j);
		printf("\n");
	}
} 
void output2(int n)
{
	int i,j,temp,k=n-1;
	for(i=n;i>=1;i--)
	{
		temp=n-i;
		while(temp--)
			printf(".");
		for(j=i+k;j>=1;j-=2)
			printf("%d",j);
		for(j=3;j<=i+k;j+=2)
			printf("%d",j);
		k--;
		printf("\n"); 
	} 
} 
int main()
{
	int c[10],l[10];
	int i=0,p=0;
	printf("Input type\n");
	scanf("%d",&c);
	while(c[i]!=-1)
	{
		if(p)
		{
			printf("Input type\n");
			scanf("%d",&c[i]);
		}
		else if(!p)
		{
			printf("Input line\n");
			scanf("%d",&l[i]); 
			i++;
		}
		p=1-p;
	}
	for(int j=0;j<i;j++)
	{
		if(c[j]!=1&&c[j]!=2)
		{
			printf("E\n");
		}
		else
		{
			if(c[j]==1)
			{
				if(l[j]>=1&&l[j]<=18&&l[j]%2==1)
				{
					output1(l[j]);
				}
				else
				{
					printf("E\n");
				}
			}
			else if(c[j]==2)
			{
				if(l[j]>=1&&l[j]<=5)
				{
					output2(l[j]);
				}
				else
				{
					printf("E\n");
				}
			}
		}
		
	}
	system("pause");
	return 0;
}
