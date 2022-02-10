#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
typedef struct node_t
{
	int data;
	struct node_t * next;
}node,*h;
struct queue_t
{
	char name[10];
	h head;
	int front;
	int rear; 
};
struct queue_t q[10];
int qNum=0;
char name[10];
void createQueue()
{
	printf("Input queue name\n");
	gets(name);
	strcpy(q[qNum].name,name);
	q[qNum].front=0;
	q[qNum].rear=0;
	q[qNum].head=NULL;
	qNum++;
}
void enQueue()
{
	int data,ok=-1;
	printf("Insert queue name\n");
	gets(name);
	for(int i=0;i<qNum;i++)
	{
		if(strcmp(q[i].name,name)==0)
		{
			ok=i;
			break;
		}
	}
	if(ok==-1)
	{
		printf("queue %s isn't exist\n",name);
		return;
	}
	
	printf("Input insert number\n");
	scanf("%d",&data);
	h *p=&q[ok].head;
	h temp=*p;
	struct node_t *aNode=(struct node_t*)malloc(sizeof(struct node_t));
	aNode->data=data;
	aNode->next=NULL;
	if(*p==NULL)
	{
		*p=aNode;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=aNode;
	}
	q[ok].rear++;
}
void deQueue()
{
	int data,ok=-1;
	printf("delete queue name\n");
	gets(name);
	for(int i=0;i<qNum;i++)
	{
		if(strcmp(q[i].name,name)==0)
		{
			ok=i;
			break;
		}
	}
	if(ok==-1)
	{
		printf("queue %s isn't exist\n",name);
		return;
	}
	
	h *p=&q[ok].head;
	h temp=*p;
	if(*p==NULL)
	{
		printf("queue is empty\n");
		return;
	} 
	else
	{
		*p=(*p)->next;
		free(temp);
	}
	q[ok].rear--;
}
void mergeQueue()
{
	int data,ok=-1,ok2=-1;
	printf("merge front queue name\n");
	gets(name);
	for(int i=0;i<qNum;i++)
	{
		if(strcmp(q[i].name,name)==0)
		{
			ok=i;
			break;
		}
	}
	if(ok==-1)
	{
		printf("queue %s isn't exist\n",name);
		return;
	}
	printf("merge rear queue name\n");
	gets(name);
	for(int i=0;i<qNum;i++)
	{
		if(strcmp(q[i].name,name)==0)
		{
			ok2=i;
			break;
		}
	}
	if(ok2==-1)
	{
		printf("queue %s isn't exist\n",name);
		return;
	}
	h *p=&q[ok].head;
	h temp=*p;
	h *p2=&q[ok2].head;
	h temp2=*p2;
	if((*p2)==NULL)
	{
		return;
	}
	if((*p)==NULL)
	{
		*p=*p2;
		*p2=NULL;
		q[ok].rear=q[ok2].rear;
		q[ok2].rear=0;
		return;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=(*p2);
		*p2=NULL;
		q[ok].rear+=q[ok2].rear;
		q[ok2].rear=0;
	} 
}
void printAllQueue()
{
	h *p;
	h temp;
	printf("*************************************************\n");
	if(qNum==0)
	{
		printf("Isn't have any queue\n");
	}
	for(int i=0;i<qNum;i++)
	{
		p=&q[i].head;
		temp=*p;
		printf("Queue Name:%s\tQueue size:%d\tQueue Element:",q[i].name,q[i].rear);
		if(temp==NULL)
			printf("null\n");
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
	printf("*************************************************\n");
}
int main()
{
	int c,name[5],nname=0;
	char buffer;
	while(1)
	{
		printf("6:exit 1:creat queue 2:enqueue 3:dequeue 4:merge queue 5:print all queue\n");
		scanf("%d",&c);
		scanf("%c",&buffer);
		if(c==6)
			break;
		switch(c)
		{
			case 1:
				createQueue();
				break;
			case 2:
				enQueue();
				break;
			case 3:
				deQueue();
				break;
			case 4:
				mergeQueue();
				break;
			case 5:
				printAllQueue();
				break; 
		} 
	}
    system("pause");
    return 0;
}


