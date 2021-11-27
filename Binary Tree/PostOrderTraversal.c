#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

void postOrder(Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

Node *createNode(int data)
{
    Node *n = (Node *)malloc(sizeof(Node));

    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
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

    postOrder(root);

    return 0;
}