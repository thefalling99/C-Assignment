#include<stdio.h>
#include<stdlib.h>
void check(int *yi,int *x)
{
	int a=0,b=0,i,j;
	for(i=0;i<4;i++)
	{
		if(yi[i]==x[i])
			a++;
		for(j=0;j<4;j++)
		{
			if(yi[i]==x[j])
				b++;
		} 
	}
	if(a>0)
		b-=a; 
	printf("%d A %d B\n",a,b);
}
int main()
{
	int i,j,yi[4];
	int x[4]={4,2,3,7}; 
	for(i=0;i<10;i++)
	{
		printf("猜数字(数字中间输入空格键)\n");
		for(j=0;j<4;j++)
		{
			scanf("%d",&yi[j]);
		}
		if(yi[0]==x[0]&&yi[1]==x[1]&&yi[2]==x[2]&&yi[3]==x[3])
		{
			printf("猜对了！\n");
			break;
		}
		else
			check(yi,x);
	}
    system("pause");
    return 0;
}

