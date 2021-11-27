#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int front;
    int rear;
    int size;
    int *arr;
} Queue;

int isFull(Queue *q)
{
    if (q->rear == q->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(Queue *q)
{
    if (q->rear == q->front)
    {
        return 1;
    }
    return 0;
}

void enqueue(Queue *q, int data)
{
    if (isFull(q))
    {
        printf("Queue overflow\n");
    }
    else
    {
        q->arr[++q->rear] = data;
    }
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue underflow cannot remove element\n");
        return -1;
    }
    else
    {
        q->front++;
        return q->arr[q->front];
    }
}

int main()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));

    q->size = 5;
    q->front = -1;
    q->rear = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    printf("isEmpty returns: %d\n", isEmpty(q));
    printf("isFull returns: %d\n", isFull(q));

    enqueue(q, 3);
    enqueue(q, 9);
    enqueue(q, 13);
    enqueue(q, 28);

    printf("isEmpty returns: %d\n", isEmpty(q));
    printf("isFull returns: %d\n", isFull(q));

    for (int i = 0; i < q->size; i++)
    {
        printf("%d\n", dequeue(q));
    }

    printf("isEmpty returns: %d\n", isEmpty(q));
    printf("isFull returns: %d\n", isFull(q));

    return 0;
}