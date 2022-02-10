#include<stdio.h>
#include<stdlib.h>
void printLQ(double LQ[10][10],int size)
{
	int i=0,j=0;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size+1;j++)
		{
			printf("%4.3f ",LQ[i][j]);
			if(j<size-1)
				printf("X%d+",j+1);
			else if(j<size)
				printf("X%d=",j+1);
		}
		printf("\n");
	}
	printf("\n");
}
void Gauss(double LQ[10][10],int size)
{
	int i=0,j=0,k=0;
	for(k=0;k<=size-1;k++)
	{
		for(i=size;i>=0;i--)
		{
			if(k!=i)
			{
				LQ[k][i]=LQ[k][i]/LQ[k][k];
			}
		}
		LQ[k][k]=1.0;
		for(i=k+1;i<=size-1;i++)
		{
			for(j=size;j>=k;j--)
			{
				LQ[i][j]=LQ[i][j]+(-1.0*LQ[i][k]*LQ[k][j]);
			}
		}
	}
		//printLQ(LQ,size);
	for(int i=0;i<size;i++)
	{
		printf("%4.3f\n",LQ[i][size]);
	}
}
int main()
{
	int size=4;
	double LQ[][10]={{1,1.5,2.5,3.5,1},{0.375,1,0.25,1,1},{0.5,2,1,1,1},{1,2,2,1,1}};
	printLQ(LQ,size);
	Gauss(LQ,size);
	//printLQ(LQ,size);
	for(int i=0;i<size;i++)
	{
		printf("%4.3f\n",LQ[i][size]);
	}
    system("pause");
    return 0;
}

