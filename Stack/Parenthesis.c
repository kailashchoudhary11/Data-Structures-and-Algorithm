#include<stdio.h>
#include<stdlib.h>

typedef struct Stack
{
    int top;
    int size;
    char *arr;
}Stack;

int isEmpty(Stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

void push(Stack *s, char element)
{   
    s->arr[++s->top] = element;
}

int pop(Stack *s)
{
    if (s->top != -1)
    {
        s->top --;
        return 1;
    }
    return 0;
}

int matchParenthesis(char * exp, int size)
{
    
    Stack *s = (Stack *) malloc(sizeof(Stack));

    s->size = size;
    s->top = -1;
    s->arr = (char *) malloc(s->size * sizeof(char));

    int i = 0;
   
    while (exp[i] != '\0')
    {
        if (exp[i] == '(')
        {
            push(s,exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (!pop(s))
            {
                return 0;
            }
        }
        i++;
    }
    if (isEmpty(s))
    {
        return 1;
    }
    return 0;
    
}
int main()
{
    char exp[] = "()";
    int key = matchParenthesis(exp, sizeof(exp)); 
    if (key)
    {
        printf("Parenthesis matched\n");
    }
    else
    {
        printf("Parenthesis does not match\n");
    }

    return 0;
}