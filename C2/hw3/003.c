#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,data;
	int goods[10]={0};
	int max,maxnum;
	printf("輸入購買資料筆數\n");
	scanf("%d",&n);
	printf("输入购买的商品编号（输入-1结束）\n");
	while(1)
	{
		scanf("%d,",&data);
		if(data==-1)
			break;
		else
			goods[data]++;
	}
	max=0;
	maxnum=0;
	for(int i=0;i<10;i++)
	{
		if(goods[i]>maxnum)
		{
			maxnum=goods[i];
			max=i;
		}
	}
	goods[max]=0;
	printf("%d,%d,",max,maxnum);
	max=0;
	maxnum=0;
	for(int i=0;i<10;i++)
	{
		if(goods[i]>maxnum)
		{
			maxnum=goods[i];
			max=i;
		}
	}
	printf("%d,%d\n",max,maxnum);
    system("pause");
    return 0;
}

