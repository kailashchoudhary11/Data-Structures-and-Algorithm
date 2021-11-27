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

void insertAtEnd(Node *head, int data)
{
    Node *ptr = (Node *) malloc(sizeof(Node));
    ptr -> data = data;
    while(head -> next != NULL)
    {
        head = head -> next;
    }

    head -> next = ptr;
    ptr -> next = NULL;

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

    second -> data = 42;
    second -> next = third;

    third -> data = 58;
    third -> next = fourth;

    fourth -> data = 95;
    fourth -> next = NULL;

    displayList(head);

    int data = 63;
    insertAtEnd(head, data);

    displayList(head);

    free(head);
    free(second);
    free(third);
    free(fourth);


    return 0;
}