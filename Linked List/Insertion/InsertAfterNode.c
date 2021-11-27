#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data; 
    struct Node *next;
}
Node;

void displayList(Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head -> data);
        head = head -> next;
    }
    printf("\n");
}

void insertAfterNode (Node *ptr, int data)
{
    Node *p = (Node *) malloc(sizeof(Node));
    p -> data = data;

    p -> next = ptr -> next;
    ptr -> next = p;
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
    
    head -> data = 33;
    head -> next = second;

    second -> data = 46;
    second -> next = third;

    third -> data = 58;
    third -> next = fourth;

    fourth -> data = 93;
    fourth -> next = NULL;

    displayList(head);

    int data = 73;
    insertAfterNode(fourth, data);
    displayList(head);

    free(second);
    free(head);
    free(third);
    free(fourth);

    return 0;
}