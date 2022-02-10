#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void insertionSort(int num[],int n,int decrease)
{
	int i,j,temp,times=0;
	for(int i=1;i<n;i++)
	{
		temp=num[i];
		j=i-1;
		//��С
		if(decrease)
		{
			while((j>=0)&&(num[j]<temp))
			{
				num[j+1]=num[j];
				times++;
				j--;
			}
			if(j!=i-1)
            {
                num[j+1]=temp;
            }
		}
		//С����
		else if(!decrease)
		{
			while((j>=0)&&(num[j]>temp))
			{
				num[j+1]=num[j];
				times++;
				j--;
			}
			if(j!=i-1)
            {
                num[j+1]=temp;
            }
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",num[i]);
	}
	printf("\ninsertion change times=%d\n",times);
}
void bubbleSort(int num[],int n,int decrease)
{
	int i,j,temp,times=0;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			//��С
			if(decrease==1)
			{
				if(num[j]<num[j+1])
				{
					temp=num[j];
					num[j]=num[j+1];
					num[j+1]=temp;
                    times++;
				}
			}
			//С����
			else if(decrease==0)
			{
				if(num[j]>num[j+1])
				{
					temp=num[j];
					num[j]=num[j+1];
					num[j+1]=temp;
                    times++;
				}
			}

		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",num[i]);
	}
	printf("\nbubble change times=%d\n",times);
}
void selectionSort(int num[],int n,int decrease)
{
	int i,j,p,temp,times=0;
	for(i=0;i<n;i++)
	{
		p=i;
		for(j=i+1;j<n;j++)
		{
			//��С
			if(decrease)
			{
				if(num[p]<num[j])
				{
					p=j;
				}
			}
			//
			else if(!decrease)
			{
				if(num[p]>num[j])
				{
					p=j;
				}
			}
		}
		if(p!=i)
		{
			temp=num[i];
			num[i]=num[p];
			num[p]=temp;
			times++;
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",num[i]);
	}
	printf("\nselection change times=%d\n",times);
}
int main()
{
	int num[20]={0};
	int temp[20];
	int n=0,decrease;
	printf("����ʽ��С��������0����С����1��\n");
	scanf("%d",&decrease);
	printf("����һ�����֣�����20����\n");
	while(1)
	{
		scanf("%d",&num[n]);
		if(num[n]==-999)
			break;
		n++;
	}
	for(int i=0;i<20;i++)
    {
        temp[i]=num[i];
    }
	bubbleSort(num,n,decrease);
	for(int i=0;i<20;i++)
    {
        num[i]=temp[i];
    }
	insertionSort(num,n,decrease);
	for(int i=0;i<20;i++)
    {
        num[i]=temp[i];
    }
	selectionSort(num,n,decrease);
    system("pause");
    return 0;
}

