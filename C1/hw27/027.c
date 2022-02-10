#include<stdio.h>
#include<stdlib.h>
void judge(int data[],int *r)
{
	int type[4]={0},num[13]={0};
	int t,s,p=0,h=0;
	int a2=0,a3=0;
	for(int i=0;i<5;i++)
	{
		s=data[i]%10;
		t=data[i]/10;
		type[s]++;
		num[t-1]++;
	}
	for(int i=0;i<13;i++)
	{
		if(num[i]!=0&&num[(i+1)%13]!=0&&num[(i+2)%13]!=0&&num[(i+3)%13]!=0&&num[(i+4)%13]!=0)
        {
            for(int j=0;j<4;j++)
            {
                if(type[j]==5)
                {
                    *r=7;
                    return;
                }
            }
            *r=6;
            return;
        }
		if(num[i]==4)
		{
			*r=5;
			return;
		}
		if(num[i]==3)
			a3++;
		if(num[i]==2)
			a2++;
	}
	if(a3==1&&a2==0)
		*r=3;
	else if(a3==1&&a2==1)
		*r=4;
	else if(a2==1&&a3==0)
		*r=1;
	else if(a2==2)
		*r=2;
}
int main()
{
	int data[5];
	int r;
	printf("输入五张扑克牌（第一个数字表示牌号，第二个数字表示花色）\n");
	scanf("%d %d %d %d %d",&data[0],&data[1],&data[2],&data[3],&data[4]);
	judge(data,&r);
	printf("%d\n",r);
    system("pause");
    return 0;
}

