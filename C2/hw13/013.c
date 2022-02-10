#include<stdio.h>
int main()
{
	unsigned long long int x[71]={0,1,2,4,0};
	int n;
	printf("Input n:\n");
	scanf("%d",&n);
	for(int i=4;i<=n;i++)
	{
		x[i]=x[i-1]+x[i-2]+x[i-3];
	}
	printf("%lld\n",x[n]);
}
