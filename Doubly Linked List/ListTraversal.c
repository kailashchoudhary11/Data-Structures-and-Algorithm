#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *previous;
    struct Node *next;
} Node;

void displayList(Node *head)
{
    Node *p;
    do
    {
        printf("%d ", head->data);
        
        if (head->next == NULL)
        {
            p = head;
        }

        head = head->next;
    } while (head != NULL);

    printf("\n");

    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->previous;
    }
}

int main()
{
    Node *head = (Node *)malloc(sizeof(Node));
    Node *second = (Node *)malloc(sizeof(Node));
    Node *third = (Node *)malloc(sizeof(Node));
    Node *fourth = (Node *)malloc(sizeof(Node));

    head->data = 1;
    head->previous = NULL;
    head->next = second;

    second->data = 2;
    second->previous = head;
    second->next = third;

    third->data = 3;
    third->previous = second;
    third->next = fourth;

    fourth->data = 4;
    fourth->previous = third;
    fourth->next = NULL;

    displayList(head);

    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}