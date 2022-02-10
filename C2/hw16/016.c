#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int ip[10][4],n=0,e=0;
	char name[10][10];
	char name2[10][10];
	char error[10][10];
	while(1)
	{
		printf("Input IP\n");
		scanf("%d.%d.%d.%d,%s",&ip[n][0],&ip[n][1],&ip[n][2],&ip[n][3],name[n]);
		if((ip[n][0]==0)&&(ip[n][1]==0)&&(ip[n][2]==0)&&ip[n][3]==0)
			break;
		for(int i=0;i<4;i++)
		{
			if(ip[n][i]<0||ip[n][i]>255)
				strcpy(error[e++],name[n]);
		}
		n++;
	}
	for(int i=0;i<n;i++)
	{
		int k=0,p=0;
		strcpy(name2[k],name[i]);
		k++;
		for(int j=0;j<n;j++)
		{
			if(i==j)
				continue;
			if(ip[i][0]==ip[j][0]&&ip[i][1]==ip[j][1])
			{
				p=1;
				strcpy(name2[k],name[j]);
				k++;
				for(int x=0;x<2;x++)
				{
					ip[j][x]=j;
				}
			}
		}
		if(p==1)
		{
			for(int y=0;y<k;y++)
			{
				printf("%s ",name2[y]);
			}
			printf("are on the same local network\n");
		}
	}
	for(int i=0;i<e;i++)
	{
		printf("%s is error ip\n",error[i]);
	}
    system("pause");
    return 0;
}

