/*Ո�z��ݔ������T�n���Ƿ��n�� ����ݔ���n�̾�̖(����)�����nС�r��(1-2С�r)�����n�r�g(��С�r��ݔ�����n�r�g, ���� 1-5, ��1-9��)
--------------------------------ݔ���f�� --------------------------------1001 (�n�̾�̖)
�� 5 �
c10401.txt
2    (2С�r) 11   (����1 ��1���n) 59   (����5 ��9���n) ...  (�ڶ��T�n) ...  (�����T�n)
--------------------------------ݔ���f�� --------------------------------�n�̾�̖,�n�̾�̖,�nͻ�r�g (�n�̾�̖ݔ������cݔ�������ͬ����12,13,23) (ÿ���г��ɂ��nͻ�n�̾�̖��һ���nͻ�r�g) (���]���nͻ�tݔ�� correct)
--------------------------------�yԇ�Y�ϣ� --------------------------------
input
1001 2 12 13 1002 2 13 21 1003 2 25 21 --------output
1001,1002,13 1002,1003,21
--------------------------------input
1001 1 21 1002 2 33 32 1003 2 45 46 --------output
correct*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int classId[3];
	int classTime[3];
	int time[6];
	int i,j,isClash=0;
	int t=0;
	for(i=0;i<3;i++)
	{
		printf("what's the class%d ID?\n",i+1);
		scanf("%d",&classId[i]);
		printf("How long a lesson%d?\n",i+1);
		scanf("%d",&classTime[i]);
		for(int k=0;k<classTime[i];k++)
        {
            printf("what's the class time?\n");
            scanf("%d",&time[t++]);
        }
	}
	for(i=0;i<t;i++)
	{
		for(j=0;j<t;j++)
		{
			if(i!=j&&time[i]==time[j])
			{
                if(isClash%2==0)
				{
					printf("%d ",classId[i/2]);
					printf("%d ",classId[j/2]);
					printf("%d\n",time[i]);
				}
				isClash++;
			}
		}
	}
	if(isClash==0)
		printf("corrcet\n");
	system("pause");
	return 0;
}
