#include<stdio.h>

void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int *arr, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int temp[high + 1];

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int p = low; p <= high; p++)
    {
        arr[p] = temp[p];
    }  
}

void mergeSort(int *arr, int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
    
}

int main()
{
    int arr[] = {9, 1, 5, 6, 1, 8, 14, 28};
    int size = sizeof(arr) / sizeof(int);

    display(arr, size);
    mergeSort(arr, 0, size - 1);
    display(arr, size);
    return 0;
}