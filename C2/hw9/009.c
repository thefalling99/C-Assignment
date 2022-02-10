#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 200
void getNum(char *art)
{
	int sum=0,n=0;
	char num[10]={0},num1[10];
	int len=strlen(art);
	for(int i=0;i<len;i++)
	{
		if(art[i]==' ')
		{
			if(num[0]!=0)
			{
				int k=0;
				for(int j=n-1;j>=0;j--)
				{
					num1[k++]=num[j];
				}
				num1[k]='\0';
				sum+=atoi(num1);
				for(int x=0;x<10;x++)
					num[x]=0;
				n=0;
			}
		}
		if(art[i]>=48&&art[i]<=57)
		{
			num[n++]=art[i];
		}
	}
	printf("%d",sum);
}
void getLineTwoNum(char *art)
{
    int password[50]={0};
    int psw=0;
    int same=0;
    int len=strlen(art);
    int ps=0;
    char isget[52]={'A'};
    for(int i=1;i<len;i++)//i=1跳開首字母O
    {
        for(int j=0;j<52;j++)
        {
            if(isget[j]==art[i])//防止相同字母再做一次
            {
                same=1;
                break;
            }
        }
        if(same==0)
        {
            char *p=(art+i);
            while((*p)!='\0')
            {
                if((*p)==art[i])
                {
                    ps++;
                }
                p++;
            }
            password[psw++]=ps;
            ps=0;
        }
        same=0;
    }
    for(int i=0;i<4;i++)
    {
        printf("%d",password[i]);
    }
}
void passWord(char *art)
{
	char *words[SIZE];
	int i=0,count=0,len=strlen(art);
	words[count++]=&art[i];
	for(i=0;i<len;i++)
	{
		if(art[i]=='.')
		{
			art[i++]='\0';
			words[count++]=&art[++i];
		}
	}
	getNum(words[0]);
	getLineTwoNum(words[1]);
}
int main()
{
    char article[SIZE]="Today is my 45 birthday,There are 65 guest coming for the 1000 party,I got 789 gifts to open.\nObject-oriented programming is a programming paradigm based on the concept of objects,a app,XXXXXXXXXX.";
    char text[SIZE];
    printf("Input article\n");
    strcpy(text,article);
    passWord(text);
}

