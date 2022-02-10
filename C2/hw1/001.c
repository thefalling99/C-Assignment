#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j=0,k,o,m=0;
	int sMostlike[4];
	int tMostlike[4];
	int sCurrent[4];
	int tCurrent[4];
	int sBool[4]={0};
	int tBool[4]={0};
	int sPerference[4][4];
	int tPerference[4][4];
	printf("intput student(1:表示W 2:表示X 3:表示Y 4：表示Z)\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%d",&sPerference[i][j]);
		}
	}
	printf("intput teacher(1:表示A 2:表示B 3:表示C 4：表示D)\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%d",&tPerference[i][j]);
		}
	}
	//int sPerference[4][4]={{1,2,3,4},{1,3,2,4},{4,2,3,1},{2,3,1,4}};
	//老师对学生的选择
	//int tPerference[4][4]={{2,1,3,4},{2,1,3,4},{3,4,1,2},{2,1,4,3}};
	//学生最爱的老师

	while(m!=4)
	{
		for(i=0;i<4;i++)
		{
			sMostlike[i]=sPerference[i][j];
		}
		for(i=0;i<4;i++)
		{
			//根据学生和老师的选择进行配对
			if(tBool[sMostlike[i]]==0&&sBool[i]==0)
			{
				//如果学生选择的老师没有配对，则将他们配对
				sCurrent[i]=sMostlike[i];
				tCurrent[sMostlike[i]]=i;
				tBool[sMostlike[i]]=1;
				sBool[i]=1;
				m++;
			}
			//如果该老师已经配对，则需要比较老实更喜欢哪个学生
			else if(tBool[sMostlike[i]]==1&&sBool[i]==0)
			{
				//if(tPerference[sMostlike[i])
				for(k=0;k<4;k++)
				{
					if(tPerference[sMostlike[i]][k]==i)
						break;
				}
				for(o=0;o<4;o++)
				{
					if(tPerference[sMostlike[i]][o]==tCurrent[sMostlike[i]])
						break;
				}
				if(k<o)
				{
					sBool[tCurrent[sMostlike[i]]]=0;
					sCurrent[i]=sMostlike[i];
					tCurrent[sMostlike[i]]=i;
					tBool[sMostlike[i]]=1;
					sBool[i]=1;
				}
			}
		}
		j++;
		sCurrent[0]=3;
		m++;
	}
	for(i=0;i<4;i++)
	{
		printf("%d->%d\n",i+1,sCurrent[i]);
	}
    system("pause");
    return 0;
}

