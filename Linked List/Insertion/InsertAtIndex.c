#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}
Node;

void displayList(Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr ->data);
        ptr = ptr -> next;
    }
    printf("\n");
}

void insertAtIndex(Node * head, int data, int index)
{
    Node *ptr = (Node *) malloc(sizeof(Node));

    ptr -> data = data;

    int i = 0;

    while (i != index - 1)
    {
        head = head -> next;
        i++;
    }
    ptr -> next = head -> next;
    head -> next = ptr;

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

    head -> data = 22;
    head -> next = second;

    second -> data = 34;
    second -> next = third;

    third -> data = 40;
    third -> next = fourth;

    fourth -> data = 58;
    fourth -> next = NULL;

    displayList(head);

    int data = 98;
    int index = 2;

    insertAtIndex(head,data,index);
    displayList(head);

    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}