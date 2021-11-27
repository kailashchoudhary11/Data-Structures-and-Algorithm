#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}
Node;

void listTraversal(Node *head)
{
    Node *ptr = head;
    
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
    
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

    head->data = 8;
    head->next = second;

    second->data = 4;
    second->next = third;

    third->data = 2;
    third->next = fourth;

    fourth->data = 1;
    fourth->next = head;

    int data = 16;
    listTraversal(head);

    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}