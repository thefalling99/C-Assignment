#include <stdio.h>
#include<stdlib.h>
#include<string.h>
const int SIZE = 100;
char preOrder[SIZE], inOrder[SIZE];
struct Node
{
    char data;
    Node *lson;
    Node *rson;
};
void CreatTree(Node *&tree, int preNo, int inNo, int len)
{
    int i;
    if(len <= 0)
    {
        tree = NULL;
        return;
    }
    tree = new Node;
    tree->data = preOrder[preNo];
    for(i=0;i<len;i++)
        if(preOrder[preNo] == inOrder[inNo+i])
            break;
    CreatTree(tree->lson, preNo+1, inNo, i);
    CreatTree(tree->rson, preNo+i+1, inNo+i+1, len-i-1);
}
void PrintPostOrder(Node *&tree)
{
    if(NULL == tree)
        return;
    PrintPostOrder(tree->lson);
    PrintPostOrder(tree->rson);
    printf("%c", tree->data);
    if(tree->data != preOrder[0])
        printf(" ");
}
void Delete(Node *&p)
{
    if(p != NULL)
    {
        Delete(p->lson);
        Delete(p->rson);
        delete p;
    }
}
//struct TreeNode
//{
//    struct TreeNode* left;
//    struct TreeNode* right;
//    char  elem;
//};
//
//
//TreeNode* BinaryTreeFromOrderings(char* inorder, char* aftorder, int length)
//{
//    if(length == 0)
//    {
//        return NULL;
//    }
//    TreeNode* node = new TreeNode;//Noice that [new] should be written out.
//    node->elem = *(aftorder+length-1);
//    std::cout<<node->elem<<std::endl;
//    int rootIndex = 0;
//    for(;rootIndex < length; rootIndex++)//a variation of the loop
//    {
//        if(inorder[rootIndex] ==  *(aftorder+length-1))
//            break;
//    }
//    node->left = BinaryTreeFromOrderings(inorder, aftorder , rootIndex);
//    node->right = BinaryTreeFromOrderings(inorder + rootIndex + 1, aftorder + rootIndex , length - (rootIndex + 1));
//
//    return node;
//}


int main()
{
    int n, i;
    Node *root;
    char buffer;
    printf("請輸入前序遍歷:\n");
    scanf("%s", preOrder);
    printf("請輸入中序遍歷:\n");
    scanf("%s", inOrder);
    n=strlen(preOrder);
    CreatTree(root, 0, 0, n);
    printf("後序遍歷是:\n");
    PrintPostOrder(root);
    printf("\n");
    Delete(root);
    system("pause");
    return 0;
}

