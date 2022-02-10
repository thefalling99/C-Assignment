/*此题不会*/
#include<stdio.h>
int main()
{
	int m,n;
	int i,j;
	char buffer;
	printf("Input n:\n");
	scanf("%d",&n);
	scanf("%c",&buffer);
	char str[n][30];
	for(i=0;i<n;i++)
	{
		gets(str[i]);
	}
	
	printf("Input m:\n");
	scanf("%d",&m);
	scanf("%c",&buffer);
	char str2[m][30];
	for(i=0;i<n;i++)
	{
		gets(str2[i]);
	}
} 
