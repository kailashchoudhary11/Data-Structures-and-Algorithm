#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data)
{
    Node *n = (Node *)malloc(sizeof(Node));

    n->data = data;
    n->right = NULL;
    n->left = NULL;

    return n;
}

int isBST(Node *root)
{
    static Node *prev = NULL;

    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && prev->data >= root->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    return 1;
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

void insert(Node *root, int key)
{
    Node *prev;
    Node *ptr = createNode(key);

    while (root != NULL)
    {
        prev = root;
        if (root->data == key)
        {
            printf("Cannot add duplicate element in BST\n");

            return;
        }
        if (root->data < key)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }

    if (prev->data > key)
    {
        prev->left = ptr;
    }
    else
    {
        prev->right = ptr;
    }
    return;
}

int main()
{
    Node *root = createNode(22);
    Node *l = createNode(11);
    Node *r = createNode(33);
    Node *l2 = createNode(8);
    Node *r2 = createNode(18);
    Node *l3 = createNode(28);
    Node *r3 = createNode(44);

    // Linking the nodes
    root->left = l;
    root->right = r;

    l->left = l2;
    l->right = r2;

    r->left = l3;
    r->right = r3;

    if (isBST(root))
    {
        printf("This is a binary tree\n");
    }
    else
    {
        printf("It is not a binary tree\n");
    }
    
    printf("Traversal before insertion\n");
    inOrderTraversal(root);
    insert(root, 9);
    printf("\nTraversal after insertion \n");
    inOrderTraversal(root);

    printf("\n%d\n", root->data);

    free(root);
    free(r);
    free(l);
    free(l2);
    free(r2);
    free(l3);
    free(r3);

    return 0;
}