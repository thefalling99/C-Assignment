#include<stdio.h>
#include<stdlib.h>
typedef struct node_s
{
	int data;
	struct node_s *left;
	struct node_s *right;
}node_t,*root,*nodep_t;
void insert(nodep_t *node,int data)
{
	nodep_t temp=*node;
	struct node_s* aNode=(struct node_s*)malloc(sizeof(struct node_s));
	aNode->data=data;
	aNode->left=NULL;
	aNode->right=NULL;
	if(*node==NULL)
	{
		*node=aNode;
	}
	else
	{
		while(temp!=NULL)
		{
			if(aNode->data<=temp->data)
			{
				if(temp->left==NULL)
				{
					temp->left=aNode;
					break;
				}
				else
					temp=temp->left;
			}
			else
			{
				if(temp->right==NULL)
				{
					temp->right=aNode;
					break;
				}
				else
					temp=temp->right;
			}
		}
	}
}
void inorder(nodep_t node)
{
	printf("");
	if(node!=NULL)
	{

		inorder(node->left);
		printf("%d ",node->data);
		inorder(node->right);
	}
}
int main()
{
	int c,data;
	root r=NULL;
	while(1)
	{
		printf("Input(0:exit 1:print 2:insert)\n");
		scanf("%d",&c);
		if(c==0)
			break;
		if(c==1)
		{
		    if(r==NULL)
                printf("null\n");
            else
            {
                inorder(r);
			    printf("\n");
            }
		}
		if(c==2)
		{
			printf("Input insert number\n");
			scanf("%d",&data);
			insert(&r,data);
		}
	}
    system("pause");
    return 0;
}

