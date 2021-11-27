#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}
Node;

void linkedListTraversal (Node *ptr ) 
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr ->data);
        ptr = ptr -> next;
    }
    
}

int main()
{
    Node head;    
    Node second;
    Node third;
    Node fourth;
    Node fifth;

    head.data = 26;
    head.next = &second;

    second.data = 48;
    second.next = &third;

    third.data = 56;
    third.next = &fourth;

    fourth.data = 98;
    fourth.next = &fifth;

    fifth.data = 156;
    fifth.next = NULL;

    linkedListTraversal(&head);

    return 0;
}