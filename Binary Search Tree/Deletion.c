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
    Node *ptr = (Node *)malloc(sizeof(Node));

    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;

    return ptr;
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

int getIPre(Node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}

Node *delete (Node *root, int data)
{
    int iPre;

    // deleting the leaf node

    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == data && root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    // Searching for the node

    if (root->data > data)
    {
        root->left = delete (root->left, data);
    }
    else if (root->data < data)
    {
        root->right = delete (root->right, data);
    }

    // Deletion strategy

    else
    {
        iPre = getIPre(root);
        root->data = iPre;
        root->left = delete(root->left, iPre);
    }
    return root;
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

    printf("Traversal before deletion\n");
    inOrder(root);
    delete (root, 18);
    printf("\nTraversal after deletion\n");
    inOrder(root);

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