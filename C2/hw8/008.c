#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 500
void scanWord(char *art,char *words[],int *no)
{
	int i=0,len=strlen(art);
	(*no=0);
	words[(*no)++]=&art[i];
	for(i=0;i<len;i++)
	{
		if(art[i]==' ')
		{
			art[i++]='\0';
			words[(*no)++]=&art[i];
		}
	}
}
void replace(char *art,char *word1,char *word2)
{
	int i=0,count=0;
	char *words[SIZE],text[SIZE];
	strcpy(text,art);
	strcpy(art,"");
	scanWord(text,words,&count);
	for(i=0;i<count;i++)
	{
		if(strcmp(words[i],word1)==0)
		{
			strcat(art,word2);
			strcat(art," ");
		}
		else
		{
			strcat(art,words[i]);
			strcat(art," ");
		}
	}
}
void deleteWord(char *art,char *word1)
{
	int i=0,count=0;
	char *words[SIZE],text[SIZE];
	strcpy(text,art);
	strcpy(art,"");
	scanWord(text,words,&count);
	for(i=0;i<count;i++)
	{
		if(strcmp(words[i],word1)!=0)
		{
			strcat(art,words[i]);
			strcat(art," ");
		}
	}
}
void insertWord(char *art,char *word1,char *word2)
{
	int i=0,count=0;
	char *words[SIZE],text[SIZE];
	strcpy(text,art);
	strcpy(art,"");
	scanWord(text,words,&count);
	for(i=0;i<count;i++)
	{
		if(strcmp(words[i],word1)==0)
		{
			strcat(art,word2);
			strcat(art," ");
			strcat(art,word1);
			strcat(art," ");
		}
		else
		{
			strcat(art,words[i]);
			strcat(art," ");
		}
	}
}
void countNum(char *art)
{
	int i=0,j,count=0,n=0;
	char buffer[20];
	char *words[SIZE],text[SIZE];
	strcpy(text,art);
	strcpy(art,"");
	scanWord(text,words,&count);
	for(i=0;i<count;i++)
	{
		n=0;
		strcpy(buffer,words[i]);
		for(j=0;j<count;j++)
		{
			if(strcmp(words[j],buffer)==0)
			{
				n++;
			}
		}
		printf("%s %d\n",buffer,n);
	}
}
void process()
{
	char *words[SIZE],article[SIZE],text[SIZE];
	char word1[10],word2[10];
	int no=0,count[SIZE]={0};
	gets(article);
	gets(word1);
	gets(word2);
	strcpy(text,article);
	replace(text,word1,word2);
	printf("%s\n",text);
	strcpy(text,article);
	insertWord(text,word1,word2);
	printf("%s\n",text);
	strcpy(text,article);
	deleteWord(text,word1);
	printf("%s\n",text);
	strcpy(text,article);
	countNum(text);
} 
int main()
{
	process();
    system("pause");
    return 0;
}

