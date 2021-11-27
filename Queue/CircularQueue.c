#include <stdio.h>
#include <stdlib.h>

typedef struct CircularQueue
{
    int front;
    int rear;
    int size;
    int *arr;
} CircularQueue;

int isEmpty(CircularQueue *cq)
{
    if (cq->front == cq->rear)
    {
        return 1;
    }
    return 0;
}

int isFull(CircularQueue *cq)
{
    if ((cq->rear + 1) % cq->size == cq->front)
    {
        return 1;
    }
    return 0;
}

void enqueue(CircularQueue *cq, int data)
{
    if (isFull(cq))
    {
        printf("The queue is full!\n");
    }
    else
    {
        cq->rear = (cq->rear + 1) % cq->size;
        cq->arr[cq->rear] = data;
        printf("Enqueued element: %d\n", data);
    }
}

int dequeue(CircularQueue *cq)
{
    if (isEmpty(cq))
    {
        printf("The queue is empty\n");
        return -1;
    }
    else
    {
        cq->front = (cq->front + 1) % cq->size;
        return cq->arr[cq->front];
    }
}

int main()
{
    CircularQueue *cq = (CircularQueue *)malloc(sizeof(CircularQueue));

    cq->size = 4;
    cq->front = 0;
    cq->rear = 0;
    cq->arr = (int *)malloc(cq->size * sizeof(int));

    // printf("isEmpty returns %d\n", isEmpty(cq));
    // printf("isFull returns %d\n", isFull(cq));

    enqueue(cq, 11);
    enqueue(cq, 21);
    enqueue(cq, 81);

    printf("Dequeued element: %d\n", dequeue(cq));
    printf("Dequeued element: %d\n", dequeue(cq));
    printf("Dequeued element: %d\n", dequeue(cq));

    enqueue(cq, 99);
    enqueue(cq, 99);
    enqueue(cq, 99);

    // printf("isEmpty returns %d\n", isEmpty(cq));
    // printf("isFull returns %d\n", isFull(cq));

    return 0;
}