#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void displayList(Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void deleteWithKey(Node *head, int key)
{
    Node *ptr = head -> next;
   
    while (ptr->data != key  && ptr -> next != NULL)
    {
        head = head -> next;
        ptr = ptr -> next;
    }
    if (ptr -> data == key)
    {
        head->next = ptr -> next;
        free(ptr);
    }
    else
    {
        printf("Element does not exist in the list\n");
    }
}

int main()
{
    Node *head;
    Node *second;
    Node *third;
    Node *fourth;

    head = (Node *)malloc(sizeof(Node));
    second = (Node *)malloc(sizeof(Node));
    third = (Node *)malloc(sizeof(Node));
    fourth = (Node *)malloc(sizeof(Node));

    head->data = 11;
    head->next = second;

    second->data = 48;
    second->next = third;

    third->data = 54;
    third->next = fourth;

    fourth->data = 72;
    fourth->next = NULL;

    displayList(head);

    int key = 72;

    deleteWithKey(head, key);

    displayList(head);

    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}