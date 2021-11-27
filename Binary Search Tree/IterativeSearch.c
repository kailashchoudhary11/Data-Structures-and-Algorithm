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
    n->right = NULL;
    n->left = NULL;

    return n;
}

Node *search(Node *root, int key)
{
    Node *n = root;
    while (n != NULL)
    {
        if (n->data == key)
        {
            return n;
        }
        else if (n->data < key)
        {
            n = n->right;
        }
        else
        {
            n = n->left;
        }
    }

    return n;
}

int main()
{
     Node *root = createNode(22);
    Node *l = createNode(11);
    Node *r = createNode(33);
    Node *l2 = createNode(8);
    Node *r2 = createNode(14);
    Node *l3 = createNode(25);
    Node *r3 = createNode(44);

    root->left = l;
    root->right = r;

    l->left = l2;
    l->right = r2;

    r->left = l3;
    r->right = r3;

    Node *searching = search(root, 25);
    printf("%d\n", searching->data);

    free(root);
    free(l);
    free(r);
    free(l2);
    free(r2);
    free(l3);
    free(r3);
    return 0;
}