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

Node * deleteAtFirst(Node *head)
{
    Node *ptr = head;
    head = head -> next;
    free(ptr);
    return head;
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

    head -> data = 45;
    head -> next = second;

    second -> data = 3;
    second -> next = third;

    third -> data = 68;
    third -> next = fourth;

    fourth -> data = 11;
    fourth -> next = NULL;

    displayList(head);
    
    head = deleteAtFirst(head);
    displayList(head);

    free(head);
    free(second);
    free(third);
    free(fourth);


    return 0;
}