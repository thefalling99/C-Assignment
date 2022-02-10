#include<stdio.h>
#include<stdlib.h>
int priority(char op)
{
	int p;
	switch(op)
	{
		case '+':case '-':
			p=1;
			break;
		case '*':case '/':
			p=2;
			break;
		default:
			p=0;
			break;
	}
	return p;
}
int postfix(char *infix)
{
	int i=0,top=0;
	char stack[512]={'\0'};
	char op;
	while(1)
	{
		op=infix[i];
		switch(op)
		{
			case '\0':
				while(top>0)
				{
					printf("%c",stack[top]);
					top--;
				}
				printf("\n");
				return 0;
			case '(':
				if(top<(sizeof(stack)/sizeof(char)))
				{
					top++;
					stack[top]=op;
				}
				break;
			case '+':case '-':case '*':case '/':
				while(priority(stack[top])>=priority(op))
				{
					printf("%c",stack[top]);
					top--;
				}
				if(top<(sizeof(stack)/sizeof(char)))
				{
					top++;
					stack[top]=op;
				}
				break;
			case ')':
				while(stack[top]!='(')
				{
					printf("%c",stack[top]);
					top--;
				}
				top--;//不输出‘(’
				break;
			//运算元直接输出
			default:
				printf("%c",op);
				break; 
		}
		i++;
	}
}
int main()
{
	char num[512];
	printf("输入运算式\n");
	scanf("%s",num);
	postfix(num);
}
