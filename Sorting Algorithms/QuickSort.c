#include <stdio.h>

void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int doPartition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (j > i)
        {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    } while (i < j);

    arr[low] = arr[j];
    arr[j] = pivot;
    return j;
}

void quickSort(int *arr, int low, int high)
{
    int partition;

    if (low < high)
    {
        partition = doPartition(arr, low, high);
        quickSort(arr, low, partition - 1);
        quickSort(arr, partition + 1, high);
    }
}

int main()
{
    int arr[] = {3, 5, 2, 13, 12, 8, 2, 1, 88};
    int size = sizeof(arr) / sizeof(int);

    display(arr, size);
    quickSort(arr, 0, size - 1);
    display(arr, size);

    return 0;
}