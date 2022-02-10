/*五子棋*/ 
#include<stdio.h>
#include<stdlib.h>
#define M 10
#define N 10
void print(int a[M][N])
{
	int i,j;
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
int check(int a[M][N])
{
	int i,j;
	for(i=0;i<M-4;i++)
	{
		//竖向 
		for(j=0;j<N;j++)
		{
			if((a[i][j]==1)&&(a[i+1][j]==1)&&(a[i+2][j]==1)&&(a[i+3][j]==1)&&(a[i+4][j]==1))
			{
				printf("p1 win\n");
				return 0;
			}
			else if((a[i][j]==2)&&(a[i+1][j]==2)&&(a[i+2][j]==2)&&(a[i+3][j]==2)&&(a[i+4][j]==2))
			{
				printf("p2 win\n");
				return 0;
			}
			//横向
			if((a[j][i]==1)&&(a[j][i+1]==1)&&(a[j][i+2]==1)&&(a[j][i+3]==1)&&(a[j][i+4]==1))	
			{
				printf("p1 win\n");
				return 0;
			}
			else if((a[j][i]==2)&&(a[j][i+1]==2)&&(a[j][i+2]==2)&&(a[j][i+3]==2)&&(a[j][i+4]==2))	
			{
				printf("p2 win\n");
				return 0;
			}
		}
		//斜向
		for(j=0;j<N-4;j++)
		{
			//向下斜 
			if((a[i][j]==1)&&(a[i+1][j+1]==1)&&(a[i+2][j+2]==1)&&(a[i+3][j+3]==1)&&(a[i+4][j+4]==1))
			{
				printf("p1 win\n");
				return 0;
			} 
			else if((a[i][j]==2)&&(a[i+1][j+1]==2)&&(a[i+2][j+2]==2)&&(a[i+3][j+3]==2)&&(a[i+4][j+4]==2))
			{
				printf("p2 win\n");
				return 0;
			} 
			//向上斜
			if((a[M-i][j]==1)&&(a[M-i-1][j+1]==1)&&(a[M-i-2][j+2]==1)&&(a[M-i-3][j+3]==1)&&(a[M-i-4][j+4]==1))
			{
				printf("p1 win\n");
				return 0;
			} 
			else if((a[M-i][j]==2)&&(a[M-i-1][j+1]==2)&&(a[M-i-2][j+2]==2)&&(a[M-i-3][j+3]==2)&&(a[M-i-4][j+4]==2))
			{
				printf("p2 win\n");
				return 0;
			} 
		} 
	} 
	return 1;
} 
int main()
{
	int a[M][N]={0},b[M][N]={0};
	print(a);
	int i,j;
	int count=1,num=0;
	while(count)
	{
		num++;
		if(num%2==1)
		{
			printf("p1 input:\n");
			scanf("%d %d",&i,&j);
			a[i][j]=1;
			print(a);
			count=check(a);
		}
		else if(num%2==0)
		{
			printf("p2 input:\n");
			scanf("%d %d",&i,&j);
			a[i][j]=2;
			print(a);
			count=check(a);
		}
	} 
    system("pause");
    return 0;
}

