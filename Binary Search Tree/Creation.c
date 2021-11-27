#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

int arr[9];
int count = 0;

Node *createNode(int data)
{
    Node *n = (Node *)malloc(sizeof(Node));

    n->data = data;
    n->right = NULL;
    n->left = NULL;

    return n;
}

void inOrderTraversal(Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

static Node *previous = NULL;

int isBinaryTree(Node *root)
{
   
    if (root != NULL)
    {
        if(!isBinaryTree(root->left))
        {
            return 0;
        }

        if (previous != NULL && previous->data >= root->data)
        {
            return 0;
        }

        previous = root;

        if (!isBinaryTree(root->right))
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    Node *root = createNode(9);
    Node *l1 = createNode(4);
    Node *r1 = createNode(11);
    Node *l2 = createNode(2);
    Node *r2 = createNode(7);
    Node *r3 = createNode(15);
    Node *l3 = createNode(5);
    Node *r4 = createNode(8);
    Node *l4 = createNode(14);

    root->left = l1;
    root->right = r1;

    l1->left = l2;
    l1->right = r2;

    r1->right = r3;

    r2->left = l3;
    r2->right = r4;

    r3->left = l4;

    if (isBinaryTree(root))
    {
        printf("It is a binary tree\n");
    }
    else
    {
        printf("It is not a binary tree\n");
    }

    return 0;
}