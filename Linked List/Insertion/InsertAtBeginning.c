#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
    int data;
    struct Node * next;
}Node;

void linkedListTraversal(Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }
    printf("\n");
}

Node * insertAtBeginning (Node *head , int data)
{
    Node *ptr;
    ptr = (Node *) malloc(sizeof(Node));
    ptr -> data = data;
    ptr -> next = head;
    return ptr;
   
}

int main()
{
    Node *head;
    Node *second;
    Node *third;
    Node *fourth;

    int element = 286;

    head = (Node *) malloc(sizeof(Node));
    second = (Node *) malloc(sizeof(Node));
    third = (Node *) malloc(sizeof(Node));
    fourth = (Node *) malloc(sizeof(Node));

    head -> data = 46;
    head -> next = second;

    second -> data = 156;
    second -> next = third;

    third -> data = 426;
    third -> next = fourth;

    fourth -> data = 34;
    fourth -> next = NULL;

    linkedListTraversal(head);
    
    head = insertAtBeginning(head, element);

    linkedListTraversal(head);

    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}