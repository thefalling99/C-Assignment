#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char s[90];
	int length=0,l=0;
	gets(s);
	length=strlen(s);
	int n,p=1;
	int i,j,k;
	printf("Input n(n<10)\n");
	scanf("%d",&n);
	int num[n][n];
	int temp[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			num[i][j]=p++;
		}
	} 
	while(l<length)
	{
		if(s[l]=='R')
		{
			for(i=0,j=n-1;j>=0;i++,j--)
			{
				for(k=0;k<n;k++)
				{
					temp[k][j]=num[i][k];
				} 
			}
		}
		else if(s[l]=='L')
		{
			for(i=0;i<n;i++)
			{
				for(k=0,j=n-1;k<n;j--,k++)
				{
					temp[j][i]=num[i][k];
				} 
			}
		}
		else if(s[l]=='N')
		{
			for(i=0,k=n-1;i<n;i++,k--)
			{
				for(j=0;j<n;j++)
				{
					temp[i][j]=num[k][j];
				}
			} 
		}
		l++;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				num[i][j]=temp[i][j];
			}
		} 
	}
	
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",num[i][j]);
		}
		printf("\n");
	} 
    system("pause");
    return 0;
}

