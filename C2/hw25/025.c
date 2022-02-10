#include<stdio.h>
#include<malloc.h>
typedef struct
{
	int id;//学号
	int score;//分数
}student_t;
typedef struct node
{
	student_t data;
	struct node *next;
}node_t;
typedef node_t *nodep_t;
void printList(nodep_t p)
{
    if(p==NULL)
    {
        printf("null");
    }
	while(p!=NULL)
	{
		printf("%d,%d ",p->data.id,p->data.score);
		p=p->next;
	}
	printf("\n");
}
void insertInOrder(nodep_t *p,student_t data)
{
	nodep_t temp=(*p);
	nodep_t prev=temp;
	struct node* aNode=(struct node*)malloc(sizeof(struct node));
	aNode->data.id=data.id;
	aNode->data.score=data.score;
	aNode->next=NULL;
	if(temp==NULL)
	{
		*p=aNode;
		return;
	}
	if((temp->data.score)>(aNode->data.score))
	{
		aNode->next=(*p);
		*p=aNode;
		return;
	}
	while(temp!=NULL)
	{
		if((temp->data.score)==(aNode->data.score))
		{
			if((temp->data.id)<(aNode->data.id))
			{
				aNode->next=temp->next;
				temp->next=aNode;
				return;
			}
			else
			{
				aNode->next=temp;
				prev->next=aNode;
				return;
			}
		}
		if((temp->data.score)<(aNode->data.score))
		{
			prev=temp;
			temp=temp->next;
		}
		else
			break;
	}
	prev->next=aNode;
	aNode->next=temp;
}
int main()
{
	int c;
	//char buffer;
	nodep_t head=NULL;
	student_t data;
	while(1)
	{
		printf("輸入操作(0:結束程式 1：列印 2：插入)\n");
		scanf("%d",&c);
		if(c==0)
			break;
		else if(c==1)
			printList(head);
		else if(c==2)
		{
			printf("輸入學號，分數\n");
			scanf("%d,%d",&data.id,&data.score);
			insertInOrder(&head,data);
		}

	}
}
