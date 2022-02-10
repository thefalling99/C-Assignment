#include<stdio.h>
#include<stdlib.h>
int check(int p1[3][3],int p2[3][3],int num[])
{
	int w1=0,w2=0;
	int n=0,i,j;
	//ºá
	for(i=0;i<3;i++)
	{
		n=0;
		for(j=0;j<3;j++)
		{
			if(num[j]==p1[i][0]||num[j]==p1[i][1]||num[j]==p1[i][2])
				n++;
		}
		if(n==3)
		{
			w1=1;
			break;
		}
	}
	for(i=0;i<3;i++)
	{
		n=0;
		for(j=0;j<3;j++)
		{
			if(num[j]==p2[i][0]||num[j]==p2[i][1]||num[j]==p2[i][2])
				n++;
		}
		if(n==3)
		{
			w2=1;
			break;
		}
	}
	//Êú
	for(i=0;i<3;i++)
	{
		n=0;
		for(j=0;j<3;j++)
		{
			if(num[j]==p1[0][i]||num[j]==p1[1][i]||num[j]==p1[2][i])
				n++;
		}
		if(n==3)
		{
			w1=1;
			break;
		}
	}
	for(i=0;i<3;i++)
	{
		n=0;
		for(j=0;j<3;j++)
		{
			if(num[j]==p2[0][i]||num[j]==p2[1][i]||num[j]==p2[2][i])
				n++;
		}
		if(n==3)
		{
			w2=1;
			break;
		}
	}
	//Ğ±
	n=0;
	for(i=0;i<3;i++)
	{
		if(num[i]==p1[0][0]||num[i]==p1[1][1]||num[i]==p1[2][2])
			n++;
	} 
	if(n==3)
	{
		w1=1;
	}
	n=0;
	for(i=0;i<3;i++)
	{
		if(num[i]==p1[0][2]||num[i]==p1[1][1]||num[i]==p1[2][0])
			n++;
	}
	if(n==3)
	{
		w1=1;
	}
	n=0;
	for(i=0;i<3;i++)
	{
		if(num[i]==p2[0][0]||num[i]==p2[1][1]||num[i]==p2[2][2])
			n++;
	} 
	if(n==3)
	{
		w2=1;
	}
	n=0;
	for(i=0;i<3;i++)
	{
		if(num[i]==p2[0][2]||num[i]==p2[1][1]||num[i]==p2[2][0])
			n++;
	}
	if(n==3)
	{
		w2=1;
	}
	if(w1==w2)
		return 0;
	else if(w1>w2)
		return 1;
	else 
		return 2; 
}
int main()
{
	int p1[3][3],p2[3][3],num[3];
	int i,j,k=0,c=0;
	int result[3];
	while(c!=-1)
	{
		printf("Input p1:\n");
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				scanf("%d",&p1[i][j]);
			}
		}
		printf("Input p2:\n"); 
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				scanf("%d",&p2[i][j]);
			}
		} 
		printf("Input three numbers:\n");
		for(i=0;i<3;i++)
		{
			scanf("%d",&num[i]);
		}
		scanf("%d",&c);
		result[k++]=check(p1,p2,num);
	}
	for(i=0;i<3;i++)
	{
		if(result[i]==0)
			printf("draw\n");
		if(result[i]==1)
			printf("p1 win\n");
		if(result[i]==2)
			printf("p2 win\n");
	} 
    system("pause");
    return 0;
}

