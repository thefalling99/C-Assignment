
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//候选人
typedef struct candidate_t
{
	int num;
	int vote=0;
	char name[10];
}candidate_s;
//使用者
typedef struct user_t
{
	char name[10];
	char password[10];
	char mail[20];
}user_s;
user_s user[10];
candidate_s candidate[10];
int candidateNum=0,userNum=0,number;
char name[10],password[10],mail[20];
int add_user()
{
	int len;
	printf("Input administer name or user name\n");
	gets(name);
	len=strlen(name);
	if(len>8)
	{
		printf("username error\n");
		printf("Add user error\n");
		return 0;
	}
	printf("Input password\n");
	gets(password);
	len=strlen(password);
	if(len>8||(strcmp(name,password)==0))
	{
		printf("password error\n");
		printf("Add user error\n");
		return 0;
	}
	//是否有重名
	for(int i=0;i<userNum;i++)
	{
		if(strcmp(user[i].name,name)==0)
		{
			printf("username error\n");
			printf("Add user error\n");
			return 0;
		}
	}
	printf("Input mail\n");
	gets(mail);
	strcpy(user[userNum].name,name);
	strcpy(user[userNum].password,password);
	strcpy(user[userNum].mail,mail);
//	printf("%d.%s ",userNum,user[userNum].name);
//	printf("%d.%s ",userNum,user[userNum].password);
//	printf("%d.%s\n",userNum,user[userNum].mail);
	return 1;
}
void add_candidate()
{
	int o=0;
	printf("Input administer name\n");
	gets(name);
	printf("Input administer password\n");
	gets(password);
	if((strcmp(user[0].name,name)==0)&&(strcmp(user[0].password,password)==0))
	{
		o=1;
	}
	if(!o)
	{
		printf("Login error\n");
		return;
	}
	printf("Input candidate name\n");
	gets(name);
	printf("Input candidate number\n");
	scanf("%d",&number);
	char b;
	scanf("%c",&b);
	for(int i=0;i<candidateNum;i++)
	{
		if(strcmp(candidate[i].name,name)==0||candidate[i].num==number)
		{
			printf("candidate data error\n");
			return;
		}
	}
	strcpy(candidate[candidateNum].name,name);
	candidate[candidateNum].num=number;

	candidateNum++;
	for(int i=0;i<candidateNum;i++)
	{
		printf("\n\n\n%s %d\n\n\n",candidate[i].name,candidate[i].num);
	}
	printf("Add candidate sucessful\n");
}
void vote()
{
	int o=0;
	printf("Input user name\n");
	gets(name);
	printf("Input user password\n");
	gets(password);
	for(int i=1;i<=userNum;i++)
	{
		if((strcmp(user[i].name,name)==0)&&(strcmp(user[i].password,password)==0))
		{
			o=1;
			break;
		}
	}
	if(!o)
	{
		printf("Login error\n");
		return;
	}
	printf("Input vote number\n");
	scanf("%d",&number);
	o=-1;
	for(int i=0;i<=candidateNum;i++)
	{
		if(candidate[i].num==number)
		{
			o=i;
			break;
		}
	}
	if(o==-1)
	{
		printf("candidate error\n");
		return;
	}
	candidate[o].vote+=1;
	char b;
	scanf("%c",&b);
	printf("voting sucessful\n");
}
void search()
{
	int o=0;
	printf("Input user name\n");
	gets(name);
	printf("Input user password\n");
	gets(password);
	for(int i=1;i<userNum;i++)
	{
		if((strcmp(user[i].name,name)==0)&&(strcmp(user[i].password,password)==0))
		{
			o=1;
			break;
		}
	}
	if(!o)
	{
		printf("Login error\n");
		return;
	}
	for(int i=0;i<candidateNum;i++)
	{
		printf("(%d,%s,%d)\n",candidate[i].num,candidate[i].name,candidate[i].vote);
	}
}
int main()
{
    char c,buffer;
    int ok;
	while((c=getchar())!='E')
	{
		scanf("%c",&buffer);
		switch(c)
		{
			//注册管理者和使用者
			case 'A':
				ok=add_user();
				if(ok)
				{
					printf("Add user successful\n");
					userNum++;
				}
				break;
			case 'M':
				add_candidate();
				break;
			case 'V':
				vote();
				break;
			case 'Q':
				search();
				break;
		}
	}
}

