#include <stdio.h>

void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int highest(int *arr, int size)
{
    int high = arr[0];
    for (int i = 1; i < size - 1; i++)
    {
        if (arr[i] > high)
        {
            high = arr[i];
        }
    }

    return high;
}

void countSort(int *arr, int size)
{
    int tempSize = highest(arr, size) + 1;
    int temp[tempSize];
    int j = 0;
    int k = 0;

    for (int i = 0; i < tempSize; i++)
    {
        temp[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        temp[arr[i]]++;
    }

    while (j != tempSize)
    {
        if (temp[j] != 0)
        {
            arr[k] = j;
            k++;
            temp[j]--;
        }
        if (temp[j] == 0)
        {
            j++;
        }
    }
}

int main()
{
    int arr[] = {9, 1, 5, 6, 1, 8, 14, 28};
    int size = sizeof(arr) / sizeof(int);

    display(arr, size);
    countSort(arr, size);
    display(arr, size);

    return 0;
}