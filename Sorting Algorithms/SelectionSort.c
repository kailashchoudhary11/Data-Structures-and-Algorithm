#include <stdio.h>

void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int *arr, int size)
{
    int small;
    int index;

    for (int i = 0; i < size - 1; i++)
    {
        index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[index])
            {
                index = j;
            }
        }
        small = arr[index];
        arr[index] = arr[i];
        arr[i] = small;
    }
}

int main()
{
    int arr[] = {12, 54, 65, 7, 23, 9};
    int size = sizeof(arr) / sizeof(int);

    selectionSort(arr, size);
    display(arr, size);
    return 0;
}