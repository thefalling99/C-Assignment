#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void g(int n,int k)
{
	if(n==1)
	{
		printf("%d",k);	
		return;
	}
	else if(k<pow(2,(n-1)))
	{
		printf("0");
		g(n-1,k);
		return;
	}
	else if(k>=pow(2,(n-1)))
	{
		printf("1");
		g(n-1,pow(2,n)-1-k);
		return;
	}
}
int main()
{
	int n[10];
	int k[10];
	int i=0;
	while(1)
	{
		printf("Input n k\n");
		scanf("%d",&n[i]);
		if(n[i]==-1)
			break;
		scanf("%d",&k[i++]);
	}
	for(int j=0;j<i;j++)
	{
		g(n[j],k[j]);
		printf("\n");
	}
    system("pause");
    return 0;
}

