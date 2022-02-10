#include<stdio.h>
#include<stdlib.h>
int migong[8][8]= //设置迷宫，最外围1为墙 里边0为可走路径 1为障碍
{
	{1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,1},
    {1,1,1,0,1,1,1,1},
	{1,0,0,0,0,0,0,1},
	{1,1,0,1,0,1,1,1},
	{1,1,0,1,0,0,0,1},
	{1,1,0,1,1,1,0,1},
	{1,1,1,1,1,1,1,1}
};
char temp[8][8];
int num;
struct
{
 	int x,y,d;
}lj[100];//x,y分别为垂直和水平方向

void start()
{
	int top=0,x,y,d,find;//d为设置方向，上下左右。find为设置找不找得到路
	lj[top].x=1;
	lj[top].y=1;
	migong[1][1]=-1;
	find=0;d=-1;

	while(top>-1)
	{
		if(lj[top].x==6&&lj[top].y==6)
		{
			for(int i=0;i<8;i++)
			{
				for(int j=0;j<8;j++)
				{
					if(migong[i][j]==1)
						temp[i][j]='1';
					if(migong[i][j]==0)
						temp[i][j]='0';
					for(int k=0;k<=top;k++)
					{
						if(i==lj[k].x&&j==lj[k].y)
							temp[i][j]='#';
					}
				}
			}
			for(int i=0;i<8;i++)
			{
				for(int j=0;j<8;j++)
				{
					printf("%c ",temp[i][j]);
				}
				printf("\n");
			}
		}

		while(d<4&&find==0)
		{
			d++;
			switch(d)
			{
				case 0:x=lj[top].x-1; y=lj[top].y;  break;//方向为上
				case 1:x=lj[top].x;   y=lj[top].y+1;break;//方向为右
				case 2:x=lj[top].x+1; y=lj[top].y;  break;//方向为下
				case 3:x=lj[top].x;   y=lj[top].y-1;
			}//方向为左
				if(migong[x][y]==0)
				find=1;
		}

		if(find==1)
		{     //判断是否找得到
			lj[top].d=d;
			top++;
			lj[top].x=x;
			lj[top].y=y;
			d=-1;
			find=0;     //重新调整方向
			migong[x][y]=-1;
		}
		else
		{
			migong[lj[top].x][lj[top].y]=0;
			top--;
			d=lj[top].d; //找不到的话退栈
		}
	}
}

int main()
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			printf("%d ",migong[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
 	start();
 	system("pause");
}
