/*012. Ոʹ�� while loop, ����ʹ�� array, for loop
��һ��ݔ����x����N�D��: 1 �����η��ⷽ������߅ 2 �����η��ⷽ������߅
�ڶ���ݔ�����x�鮋����
input 1 (��һ�N�D�Σ������μⷽ������߅) 5 (�� 5 ��)
�]: ��̖�� * �� .
�� 10 �
c10401.txt
output *.... **... ***.. ****. *****
---------------------------input 2 (�ڶ��N�D�Σ������μⷽ������߅) 3 (�� 5 ��)
output ..* .** ***
*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int choose,line,line2,i=0,j,temp;
	printf("ѡ�������Σ�1�����ⷽ������ 2�����ⷽ������\n");
	scanf("%d",&choose);
	printf("�������У�\n");
	scanf("%d",&line);
	temp=line;
	if(choose==1)
	{
		while(i!=line)
		{
			i++;
			line2=temp;
			j=0;
			while(line2)
			{
				if(j<i)
					printf("*");
				else
					printf(".");
				line2--;
				j++;
			}
			printf("\n");
		}
	}
	else if(choose==2)
	{
		while(line)
		{
			line2=temp;
			i=line2-(line2-(line-1));
			j=0;
			while(line2)
			{
				if(j<i)
					printf(".");
				else
					printf("*");
				j++;
				line2--;
			}
			line--;
			printf("\n");
		}
	}
}
