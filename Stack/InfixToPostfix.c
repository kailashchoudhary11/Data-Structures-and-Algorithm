#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack
{
    int size;
    int top;
    char *arr;
} Stack;

void push(Stack *s, char data)
{
    s->arr[++s->top] = data;
}

char pop(Stack *s)
{
    char data = s->arr[s->top];
    s->top--;
    return data;
}

int isEmpty(Stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

char stackTop(Stack *s)
{
    return s->arr[s->top];
}

int getPrecedence(char a)
{
    if (a == '*' || a == '/')
    {
        return 2;
    }
    return 1;
}

char *inToPost(char *exp)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));

    s->top = -1;
    s->size = strlen(exp);
    s->arr = (char *)malloc(s->size * sizeof(char));

    char *postFix = (char *)malloc((strlen(exp) + 1) * sizeof(char));

    int i = 0;
    int j = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] == '*' || exp[i] == '/' || exp[i] == '+' || exp[i] == '-')
        {
            if (isEmpty(s) || getPrecedence(exp[i]) > getPrecedence(stackTop(s)))
            {
                push(s, exp[i]);
                i++;
            }
            else
            {
                postFix[j] = pop(s);
                j++;
            }
        }
        else
        {
            postFix[j] = exp[i];
            j++;
            i++;
        }
        
    }
    while (!isEmpty(s))
    {
        postFix[j] = pop(s);
        j++;
    }
    postFix[j] = '\0';

    return postFix;
}

int main()
{
    char exp[] = "x-y/z-k*d";
    char *s = inToPost(exp);
    printf("%s\n", s);

    return 0;
}