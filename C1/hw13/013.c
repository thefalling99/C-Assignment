/*013. ͣ܇�MӋ��
���Oĳ��ͣ܇�����M����ͣ܇2С�r�ԃȣ�ÿ��С�r30Ԫ��δ�M��С�r�����԰�С�rӋ�M�� ���^2С�r����δ�M4С�r��ÿ��С�r40Ԫ��δ�M��С�r�԰�С�rӋ�M�� ���^4С�r���ϵĲ��ݣ�ÿ��С�r60Ԫ��δ�M��С�r�����԰�С�rӋ�M��
Ո׫����ʽӋ��ݔ�딵�P�Y�ϣ������U����ͣ܇�M�� ����ʽ�����]��ҹ��r��
ݔ���f���� ݔ���M�r�g��ÿ�M�քe���_ʼ�c�x�_�r�g��24С�r�ơ� ݔ�� -1 ֹͣݔ�룬��ݔ���ʽ�e�`���t�@ʾ�e�`ӍϢ��
ݔ���f���� ݔ����ͣ܇�M��
input:
10:23 15:20 25:25 10:70 -1
output:
340 error
�� 11 �
c10401.txt
input:
10:23 13:20 21:25 25:70 -1
output:
200 error*/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int h,m,h1,m1,p=0,cost,e=0;
	int t[10];
	while(1)
	{
		printf("���뿪ʼͣ��ʱ��\n");
		scanf("%d:",&h);
		if(h==-1)
			break;
        if(h<0||h>24)
            e=1;
		scanf("%d",&m);
		if(m<0||m>60)
            e=1;
		printf("�������ͣ��ʱ��\n");
		scanf("%d:",&h1);
		if(h1<0||h1>24)
            e=1;
		scanf("%d",&m1);
		if(m1<0||m1>60)
            e=1;
        if(e==1)
        {
            t[p++]=-1;
            e=0;
        }
        else
            t[p++]=(h1*60+m1)-(h*60+m);
	}
	for(int i=0;i<p;i++)
	{
	    if(t[i]==-1)
        {
            printf("error");
        }
		if(t[i]<120)
		{
			cost=(t[i]/30+1)*30;
		}
		else if(t[i]>=120&&t[i]<=240)
		{
			cost=120+((t[i]-120)/30+1)*40;
		}
		else
		{
			cost=280+((t[i]-240)/30+1)*60;
		}
		if(t[i]==-1)
            printf("\n");
        else
            printf("%d\n",cost);
	}
	system("pause");
	return 0;
}
