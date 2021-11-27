#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

int isEmpty(Node *front)
{
    if (front == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    if (ptr == NULL)
    {
        return 1;
    }
    return 0;
}

void enqueue(Node **front, Node **rear, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    if (ptr == NULL)
    {
        printf("Queue is full\n");
    }
    else
    {
        ptr->data = data;
        ptr->next = NULL;
        if (*front == NULL)
        {
            *front = *rear = ptr;
            printf("Enqueued element: %d\n", (*rear)->data);
        }
        else
        {
            (*rear)->next = ptr;
            *rear = ptr;
            printf("Enqueued element: %d\n", (*rear)->data);
        }
    }
}

int dequeue(Node **front)
{
    Node *ptr = *front;
    if (isEmpty(*front))
    {
        printf("Queue is empty\n");
        return -1;
    }

    *front = ptr->next;
    int data = ptr->data;
    free(ptr);
    return data;
}

int main()
{
    Node *front, *rear;
    front = rear = NULL;

    printf("isEmpty returns: %d\n", isEmpty(front));

    enqueue(&front, &rear, 21);
    enqueue(&front, &rear, 11);
    enqueue(&front, &rear, 31);
    enqueue(&front, &rear, 41);
    enqueue(&front, &rear, 51);

    printf("isEmpty returns: %d\n", isEmpty(front));

    printf("Dequeued element: %d\n", dequeue(&front));
    printf("Dequeued element: %d\n", dequeue(&front));
    printf("Dequeued element: %d\n", dequeue(&front));
    printf("Dequeued element: %d\n", dequeue(&front));
    printf("Dequeued element: %d\n", dequeue(&front));

    printf("isEmpty returns: %d\n", isEmpty(front));
    return 0;
}