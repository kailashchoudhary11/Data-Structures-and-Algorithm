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

void deleteAtIndex(Node *head, int index)
{
    int i = 0;
    while (i != index - 1)
    {
        head = head -> next;
        i++;
    }

    Node *ptr = head -> next;
    head -> next = ptr -> next;
    free(ptr);
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

    head -> data =  11;
    head -> next = second;

    second -> data =  48;
    second -> next = third;

    third -> data =  54;
    third -> next = fourth;

    fourth -> data =  72;
    fourth -> next = NULL;

    displayList(head);

    int index = 1;
    deleteAtIndex(head, index);

    displayList(head);

    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}