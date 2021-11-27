#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}
Node;

void linkedListTraversal (Node *ptr ) 
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr ->data);
        ptr = ptr -> next;
    }
    
}

int main()
{
    Node *head;    
    Node *second;
    Node *third;
    Node *fourth;

    head = (Node *) malloc(sizeof(Node));
    second = (Node *) malloc(sizeof(Node));
    third = (Node *) malloc(sizeof(Node));
    fourth = (Node *) malloc(sizeof(Node));
    head = (Node *) malloc(sizeof(Node));

    head -> data = 26;
    head -> next = second;

    second -> data = 48;
    second -> next = third;

    third -> data = 56;
    third -> next = fourth;

    fourth -> data = 98;
    fourth -> next = NULL;

    linkedListTraversal(head);

    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}