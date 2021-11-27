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
    n->right = NULL;
    return n;
}

int main()
{
    // Creating the nodes of the binary tree
    Node *root = createNode(11);
    Node *second = createNode(22);
    Node *third = createNode(33);

    // Linking the children nodes to the root
    root->left = second;
    root->right = third;

    // printing the data at the left child of root
    printf("%d\n", root->left->data);

    // freeing the dynamic memory
    free(root);
    free(second);
    free(third);


    return 0;
}