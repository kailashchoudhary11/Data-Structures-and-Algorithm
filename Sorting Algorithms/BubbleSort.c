#include<stdio.h>

void printArray(int *arr, int size) {
    for (int  i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int *arr, int size)
{
    int temp = 0;
    int key = 1;

    for (int i = 0; i < size - 1; i++)
    {
        key = 1;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                key = 0;
            }   
        }
        if (key)
        {
            printf("Breaking after pass number %d\n", i+1);
            return;
        }
    }
}

int main()
{
    int arr[] = {2, 4, 7, 9, 11, 17 };
    // int arr[] = {12, 54, 65, 7, 23, 9};
    int size = sizeof(arr) / sizeof(int);

    bubbleSort(arr, size);
    printArray(arr, size);
    
    return 0;
}