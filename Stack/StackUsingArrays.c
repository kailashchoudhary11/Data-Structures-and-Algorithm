#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int size;
    int top;
    int *arr;
} stack;

int isEmpty(stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void stackTraversal(stack *ptr)
{
    for (int i = 0; i < ptr->top + 1; i++)
    {
        printf("%d ", ptr->arr[i]);
    }
    printf("\n");
    
}

int isFull(stack *ptr)
{
    if (ptr->top == (ptr->size - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(stack *ptr, int element)
{
    if (!isFull(ptr))
    {
        ptr->arr[++ptr->top] = element;    
    }
    else
    {
        printf("Stack overflow\n");
    }    
}

int pop(stack *ptr)
{
    if (!isEmpty(ptr))
    {
        ptr->top --;
    }
    else
    {
        printf("Stack underflow\n");
    }
}

int peek(stack *ptr, int i)
{
    if (i > ptr->top + 1 || i < 1)
    {
        printf("Please provide a valid position\n");
        return 0;
    }
    return ptr->arr[ptr->top - i + 1];
}

int stackTop(stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is empty\n");
        return 0;
    }
    
    return ptr->arr[ptr->top];
}

int stackBottom(stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is empty\n");
        return 0;
    }
    
    return ptr->arr[0];
}

int main()
{
    stack *stack1;
    
    stack1 = (stack *) malloc(sizeof(stack));

    stack1->size = 5;
    stack1->top = -1;
    stack1->arr = (int *)malloc(stack1->size * sizeof(int));

    stack1->arr[++stack1->top] = 4;
    stack1->arr[++stack1->top] = 9;
    stack1->arr[++stack1->top] = 13;
    stack1->arr[++stack1->top] = 22; 

    int element = 48;

    stackTraversal(stack1);
    
    push(stack1, element);

    stackTraversal(stack1);

    pop(stack1);
    pop(stack1);
    pop(stack1);

    push(stack1, element);
    push(stack1, element);
    
    stackTraversal(stack1);

    printf("%d\n", peek(stack1, 3));

    printf("stackTop = %d\n", stackBottom(stack1));
    printf("stackBottom = %d\n", stackTop(stack1));

    return 0;
}