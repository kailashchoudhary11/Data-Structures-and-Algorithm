#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *ptr;
    int used_size;
    int total_size;
} Myarray;

void createArray(Myarray *a, int Usize, int Tsize)
{

    a->used_size = Usize;
    a->total_size = Tsize;
    a->ptr = (int *)malloc(Tsize * sizeof(int));
}

void addElements(Myarray *a)
{
    int n;

    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter the element %d ", i + 1);
        scanf("%d", &n);
        a->ptr[i] = n;
    }
}

void displayElements(Myarray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n", a->ptr[i]);
    }
}

void add (Myarray *a , int n, int index) 
{
    if (index < a->used_size) {
        int temp = a->ptr[index];
        a->ptr[index] = n;
        a->ptr[a->used_size] = temp;
    }
    else {
        a->ptr[a->used_size] = n;
    }

    a->used_size++;
}

void removeElement (Myarray* a, int index) 
{
    for (int i = index; i < a->used_size - 1; i++) 
    {
        a->ptr[i] = a->ptr[i + 1];
    }
    a->used_size--;
}

int main()
{
    Myarray marks;

    createArray(&marks, 4, 100);

    addElements(&marks);

    add(&marks, 33, 1);

    removeElement(&marks, 2);

    displayElements(&marks);

    return 0;
}