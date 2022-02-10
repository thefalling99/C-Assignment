#include<stdio.h>
#include<stdlib.h>
int chess[3][3];
int cx[9],cy[9];
int px[9],py[9];
int check_null(int px,int py)
{
	if(chess[px][py]==0)
		return 1;
	else 
		return 0;
}
int notwin()
{
	int i;
	//横向判断 
	for(i=0;i<3;i++)
	{
		if(chess[i][0]==chess[i][1]&&chess[i][1]==chess[i][2])
		{
			if(chess[i][0]==1)
			{
				printf("computer win\n");
				return 0;
			}
			else if(chess[i][0]==-1)
			{
				printf("player win\n");
				return 0;
			}
		}
	} 
	//纵向判断
	for(i=0;i<3;i++)
	{
		if(chess[0][i]==chess[1][i]&&chess[1][i]==chess[2][i])
		{
			if(chess[0][i]==1)
			{
				printf("computer win\n");
				return 0;
			}
			else if(chess[0][i]==-1)
			{
				printf("player win\n");
				return 0;
			}
		}
	} 
	//斜
	if(chess[0][0]==chess[1][1]&&chess[1][1]==chess[2][2])
	{
		if(chess[1][1]==1)
		{
			printf("computer win\n");
			return 0;
		}
		else if(chess[1][1]==-1)
		{
			printf("player win\n");
			return 0;
		}
	} 
	if(chess[0][2]==chess[1][1]&&chess[1][1]==chess[2][0])
	{
		if(chess[1][1]==1)
		{
			printf("computer win\n");
			return 0;
		}
		else if(chess[1][1]==-1)
		{
			printf("player win\n");
			return 0;
		}
	} 
	return 1; 
}
void orderd()
{
	int i,c=0,p=0;
	int pk=0,ck=0;
	//横 
	for(i=0;i<3;i++)
	{
		if(chess[i][0]==chess[i][1])
		{
			if(chess[i][1]==1)
			{
				c++;
				cx[ck]=i;
				cy[ck]=2;
				ck++;
			}
			else if(chess[i][1]==-1)
			{
				p++;
				px[pk]=i;
				py[pk]=2;
				pk++;
			}
		} 
	} 
	for(i=0;i<3;i++)
	{
		if(chess[i][1]==chess[i][2])
		{
			if(chess[i][1]==1)
			{
				c++;
				cx[ck]=i;
				cy[ck]=0;
				ck++;
			}
			else if(chess[i][1]==-1)
			{
				p++;
				px[pk]=i;
				py[pk]=0;
				pk++;
			}
		} 
	} 
	for(i=0;i<3;i++)
	{
		if(chess[i][0]==chess[i][2])
		{
			if(chess[i][2]==1)
			{
				c++;
				cx[ck]=i;
				cy[ck]=1;
				ck++;
			}
			else if(chess[i][2]==-1)
			{
				p++;
				px[pk]=i;
				py[pk]=1;
				pk++;
			}
		} 
	} 
	//纵
	for(i=0;i<3;i++)
	{
		if(chess[0][i]==chess[1][i])
		{
			if(chess[1][i]==1)
			{
				c++;
				cx[ck]=2;
				cy[ck]=i;
				ck++;
			}
			else if(chess[1][i]==-1)
			{
				p++;
				px[pk]=2;
				py[pk]=i;
				pk++;
			}
		} 
	}  
	for(i=0;i<3;i++)
	{
		if(chess[1][i]==chess[2][i])
		{
			if(chess[1][i]==1)
			{
				c++;
				cx[ck]=0;
				cy[ck]=i;
				ck++;
			}
			else if(chess[1][i]==-1)
			{
				p++;
				px[pk]=2;
				py[pk]=i;
				pk++;
			}
		} 
	} 
	for(i=0;i<3;i++)
	{
		if(chess[0][i]==chess[2][i])
		{
			if(chess[2][i]==1)
			{
				c++;
				cx[ck]=1;
				cy[ck]=i;
				ck++;
			}
			else if(chess[2][i]==-1)
			{
				p++;
				px[pk]=1;
				py[pk]=i;
				pk++;
			}
		} 
	} 
	//斜
	if(chess[0][0]==chess[1][1])
	{
		if(chess[1][1]==1)
		{
			c++;
			cx[ck]=2;
			cy[ck]=2;
			ck++;
		}
		else if(chess[1][1]==-1)
		{
			p++;
			px[pk]=2;
			py[pk]=2;
			pk++;
		}
	} 
	if(chess[2][2]==chess[1][1])
	{
		if(chess[1][1]==1)
		{
			c++;
			cx[ck]=0;
			cy[ck]=0;
			ck++;
		}
		else if(chess[1][1]==-1)
		{
			p++;
			px[pk]=0;
			py[pk]=0;
			pk++;
		}
	} 
	if(chess[0][2]==chess[1][1])
	{
		if(chess[1][1]==1)
		{
			c++;
			cx[ck]=2;
			cy[ck]=0;
			ck++;
		}
		else if(chess[1][1]==-1)
		{
			p++;
			px[pk]=2;
			py[pk]=0;
			pk++;
		}
	} 
	if(chess[2][0]==chess[1][1])
	{
		if(chess[1][1]==1)
		{
			c++;
			cx[ck]=0;
			cy[ck]=2;
			ck++;
		}
		else if(chess[1][1]==-1)
		{
			p++;
			px[pk]=0;
			py[pk]=2;
			pk++;
		}
	} 
	if(c>p)
	{
		printf("computer可能赢\n");
		for(i=0;i<ck;i++)
		{
			printf("computer will win with %d%d\n",cx[i],cy[i]);
		}
	}
	else
	{
		printf("player可能赢\n");
		for(i=0;i<pk;i++)
		{
			printf("player will win with %d%d\n",px[i],py[i]);
		}
	}
}
int main()
{ 
	int who,x,y,buffer;
	char order;
	printf("输入1代表电脑先下，输入0代表玩家先下\n");
	scanf("%d",&who);
	while(notwin())
	{
		printf("输入坐标\n");
		scanf("%d %d",&x,&y);
		if(check_null(x,y))
		{
			if(who)
				chess[x][y]=1;
			else
				chess[x][y]=-1;
			who=1-who;
		}
		else
		{
			printf("input error\n");
		}
		
		printf("输入d或w或0\n");
		scanf("%d",&buffer);
		scanf("%c",&order);
		if(order=='d')
		{
			orderd();
		}
		if(order=='w')
		{
			orderd();
		}
	}
    system("pause");
    return 0;
}

