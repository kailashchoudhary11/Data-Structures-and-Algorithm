#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

int isEmpty(Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;    
}

int isFull()
{
    Node *ptr = (Node *) malloc(sizeof(Node));
    if (ptr == NULL)
    {
        return 1;
    }
    return 0;
}

// Push Operation

Node *push(Node *top, int data)
{
    Node *ptr = (Node *) malloc(sizeof(Node));
    if (ptr == NULL)
    {
        printf("Stack Overflow\n");
        return top;
    }
    else
    {
        ptr->data = data;
        ptr->next = top;
        top = ptr;
    }
    return top;
}

// Pop operation

int pop(Node **top)
{
    Node *ptr = *top;
    if (*top == NULL)
    {
        printf("Stack Underflow\n");
        return 0;
    }
    *top = ptr->next;
    int data = ptr->data;
    free(ptr);
    
    return data;
}

// Peek operation

int peek(Node *top, int position)
{
    int i = 1;
    
    while (i != position && top != NULL)
    {
        top = top->next;
        i++;
    }
    if (top != NULL)
    {
        return top->data;        
    }    
    return -1;
}

// Stack Top operation

int stackTop(Node *top)
{
    return top->data;
}

// Stack Bottom opreation

int stackBottom(Node *top)
{
    while (top->next != NULL)
    {
        top = top->next;
    }
    return top->data;
    
}

int main()
{
    Node *top = NULL;

    top = push(top, 44);
    top = push(top, 54);
    top = push(top, 64);
    top = push(top, 74);
    top = push(top, 84);

    // printf("Popped element: %d\n", pop(&top));
    // printf("Popped element: %d\n", pop(&top));

    printf("Peeked element: %d\n", peek(top, 3));
    printf("Stack Top: %d\n", stackTop(top));
    printf("Stack Bottom: %d\n", stackBottom(top));

    return 0;
}