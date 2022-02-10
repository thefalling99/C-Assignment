#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node_s
{
	int coef;
	int exp;
	struct node_s *next;
} *node_t;
void add(node_t *head,int coef,int exp)
{
	node_t current=(*head);
	node_t prev=current;
	struct node_s* aNode=(struct node_s*)malloc(sizeof(struct node_s));
	aNode->coef=coef;
	aNode->exp=exp;
	aNode->next=NULL;

	if((*head==NULL))
	{
		(*head)=aNode;
		return;
	}
	//更大
	if(current->exp<aNode->exp)
	{
		aNode->next=(*head);
		*head=aNode;
		return;
	}
	while(current!=NULL)
	{
		//相同相加
		if(current->exp==aNode->exp)
		{
			current->coef=current->coef+aNode->coef;
			free(aNode);
			return;
		}
		if(current->exp>aNode->exp)
		{
			prev=current;
			current=current->next;
		}
		else
			break;
	}
	prev->next=aNode;
	aNode->next=current;
}
void prt(node_t head)
{
	while(head!=NULL)
	{
		printf("%d^%d ",head->coef,head->exp);
		head=head->next;
	}
	printf("\n");
}
int main()
{
	int n=1;
	int c,e;
	node_t head=NULL;
	printf("輸入多項式%d的係數和次方(輸入-999結束輸入)\n",n);
	while(1)
	{
		scanf("%d^",&c);
		if(c==-999)
            break;
		scanf("%d",&e);
		add(&head,c,e);
	}
	n++;
	printf("輸入多項式%d的係數和次方(輸入-999結束輸入)\n",n);
	while(1)
	{
		scanf("%d^",&c);
		if(c==-999)
            break;
		scanf("%d",&e);
		add(&head,c,e);
	}
	prt(head);
    system("pause");
    return 0;
}

