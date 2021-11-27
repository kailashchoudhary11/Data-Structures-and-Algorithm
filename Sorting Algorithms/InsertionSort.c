#include <stdio.h>

void display(int *arr, int size) 
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int *arr, int size)
{
    int temp;
    int j;
    
    for (int i = 1; i <= size - 1; i++)
    {
        temp = arr[i];

        j = i - 1;

        while (temp < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    } 
}

int main()
{
    int arr[] = {7, 12, 3, 4, 1};
    int size = sizeof(arr) / sizeof(int);

    display(arr,size);
    insertionSort(arr, size);
    display(arr,size);

    return 0;
}