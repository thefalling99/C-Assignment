/*010. Ոʹ��һ�� while loop �� function call
�o��һЩ���Σ����@Щ���������w���L�ȣ�ע�⣬�دB�Ĳ���ֻ����һ�Ρ�
ݔ���f�� ��
��һ����һ�������� n: ������ n �M�yԇ������
����ÿһ�M�yԇ�����ĵ�һ����һ������ m ��ʾ�˜yԇ������m�����Σ�
������m��ÿһ����һ�����εăɶ��c��
ÿһ�����c��һ���������0~60000֮�g�� ���c֮�g��һ���ո�^�������΂��������^ 5000��
��ʼ���cС����ݔ�롣 ���}��ʹ����С�
ݔ���f�� ��
ᘌ�ÿһ�M�yԇ������ݔ���串�w���L�ȣ�ÿ�M�yԇ����ݔ��һ�С�
Input:
2     (����2�M���ǰ���) 2     (�˽M�yԇ������2������) 0 1 2 3 3      (�˽M�yԇ������3������) 0 20 10 30 40 50
Output: 2 40
Input:
3 3 10 111 150 3450 160 180 2 100 180 150 3333 1 150 150
�� 8 �
c10401.txt
Output:
3401 3233 0
-------------Input: 1 2 150 320 160 190
Output: 170
*/
#include<stdio.h>
#include<stdlib.h>
int fhead=0,fnail=0,sum=0;
void f(int head,int nail)
{
	if(head<fnail)
		head=fnail;
	fnail=nail;
	if((nail-head)<0)
        return;
	sum+=(nail-head);
}
int main()
{
	int n,m,head,nail;
	printf("Input n\n");
	scanf("%d",&n);
	while(n)
	{
		printf("Input m\n");
		scanf("%d",&m);
		while(m)
		{
			printf("Input head and nail\n");
			scanf("%d %d",&head,&nail);
			f(head,nail);
			m--;
		}
		printf("\n\nanswer is:%d\n\n",sum);
		fnail=0;
		sum=0;
		n--;
	}
	system("pause");
	return 0;
}
