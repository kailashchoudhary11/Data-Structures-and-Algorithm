#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node *createNode(int data)
{
    Node *n = (Node *) malloc(sizeof(Node));

    n->data = data;
    n->left = NULL;
    n->right= NULL;

    return n;
}

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main()
{
    Node *root = createNode(4);
    Node *l1 = createNode(1);
    Node *r1 = createNode(6);
    Node *l2 = createNode(5);
    Node *r2 = createNode(2);

    root->left = l1;
    root->right = r1;

    l1->left = l2;
    l1->right = r2;

    inOrder(root);

    return 0;
}