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

void deleteIndex (int arr[], int* size, int tSize, int index) {
    if (index >=  tSize || index < 0) 
    {
        printf("Please provide a valid index\n");
    }
    else 
    {
        for (int i = index; i < *size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        
        *size -= 1;
        printf("Element at index %d removed successfully\n", index);
        display(arr, *size);
    }
}

int main()
{
    int arr[100] = {11, 22, 46, 67, 75};
    int size = 5;
    int index = 4;
    int tSize = 100;

    display(arr, size);

    deleteIndex(arr, &size, tSize, index);
    
    return 0;
}