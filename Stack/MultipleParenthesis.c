#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    char data;
    struct Stack *next;
} Stack;

int isEmpty(Stack *top)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

Stack *push(Stack *top, char data)
{
    Stack *ptr = (Stack *)malloc(sizeof(Stack));
    ptr->data = data;
    ptr->next = top;
    return ptr;
}

char pop(Stack **top)
{
    Stack *ptr = *top;
    *top = ptr->next;
    char c = ptr->data;
    free(ptr);
    return c;
}

int matched(char a, char b)
{
    if ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}'))
    {
        return 1;
    }
    return 0;
}

int matchMultipleParenthesis(char *exp)
{
    Stack *top = NULL;

    int i = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            top = push(top, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (!matched(pop(&top), exp[i]))
            {
                return 0;
            }
        }
        i++;
    }

    if (isEmpty(top))
    {
        return 1;
    }

    return 0;
}

int main()
{
    char exp[] = "{{[(7 / 4) * (3 + 8)]() + 99}}";

    if (matchMultipleParenthesis(exp))
    {
        printf("Parenthesis matches\n");
    }
    else
    {
        printf("Parenthesis does not match\n");
    }

    return 0;
}