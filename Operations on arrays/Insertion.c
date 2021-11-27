#include<stdio.h>

void display (int arr [], int size) 
{
    printf("Elements in the array are: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr [i]);
    }
    printf("\n");
}

void insertIndex (int arr[], int* size, int tSize, int index, int element) {
    if (index >=  tSize) 
    {
        printf("Unable to add the element at specified index.\n");
    }
    else 
    {
        for (int i = *size - 1; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        
        arr[index] = element;
        *size += 1;
        printf("Element added successfully\n");
        display(arr, *size);
    }
}

int main()
{
    int arr[100] = {11, 22, 46, 67, 75};
    int size = 5;
    int element = 32;
    int index = 0;
    int tSize = 100;

    display(arr, size);

    insertIndex(arr, &size, tSize, index, element);
    
    return 0;
}