#include<stdio.h>
#define NO 20
void getData(int cost[][NO],int N)
{
	int i=0,j=0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%d",&cost[i][j]);
		}
	}
}
int ok(int d[],int N)
{
	int i=0,j=0;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if((i!=j)&&(d[i]==d[j]))
				return 0;
		}
	}
	return 1;
}
void inc(int d[],int N)
{
	int c=0,i=0,ans=0;
	d[0]=d[0]+1;
	for(i=0;i<N+1;i++)
	{
		ans=(d[i]+c)%N;
		c=(d[i]+c)/N;
		d[i]=ans;
	}
}
int eval(int cost[][NO],int d[],int N)
{
	int i=0,value=0;
	for(i=0;i<N-1;i++)
	{
		value=value+cost[d[i]][d[i+1]];
	}
	return value;
}
void process()
{
	int N=0,min=9999,costValue=0;
	int data[NO]={0};
//	int cost[NO][NO]={
//					{0,4,2,3,6},
//					{4,0,3,1,4},
//					{2,3,0,2,5},
//					{3,1,2,0,3},
//					{6,4,5,3,0}
//					};
	int cost[NO][NO]={0};
	printf("Input N:\n");
	scanf("%d",&N);
	printf("Input graph:\n");
	getData(cost,N);
	while(data[N]!=1)
	{
		inc(data,N);
		if(ok(data,N)==1)
		{
			costValue=eval(cost,data,N);
			if(costValue<min)
			{
				min=costValue;
			}
		}
	}
	printf("最短路径长度是%d",min);
}
int main()
{
	process();
}
