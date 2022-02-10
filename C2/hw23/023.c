#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node_t
{
	int data;
	struct node_t *link;
}node,*h;
int isEmpty(h *head)
{
	if(*head==NULL)
		return 1;
	else
		return 0;
}
void push(h *head,int data)
{
	h temp=*head;
	struct node_t *aNode =(struct node_t*)malloc(sizeof(struct node_t));
	aNode->data=data;
	aNode->link=NULL;
	if(temp==NULL)
	{
		*head=aNode;
	}
	else
	{
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		temp->link=aNode;
	}
}
void pop(h *head)
{
	h temp=*head;
	h p=*head;
	if(isEmpty(&temp))
	{
		printf("The stack is empty\n");
		return;
	}
	if(temp->link==NULL)
	{
		printf("The data %d is pop\n",temp->data);
		free(temp);
		*head=NULL;
	}
	else
	{
		while(temp->link!=NULL)
		{
			p=temp;
			temp=temp->link;
		}
		printf("The data %d is pop\n",temp->data);
		free(temp);
		p->link=NULL;
	}
}
int main()
{
	int c,data;
	h head=NULL;
	while(1)
	{
		printf("輸入操作\n");
		scanf("%d",&c);
		if(c==3)
			break;
		else if(c==1)
		{
			printf("輸入插入的數字\n");
			scanf("%d",&data);
			push(&head,data);
		}
		else if(c==2)
		{
			pop(&head);
		}
	}
    system("pause");
    return 0;
}

