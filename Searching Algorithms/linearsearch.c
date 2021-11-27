#include <stdio.h>

int linearsearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {12, 35, 54, 65, 654, 98, 96, 70};
    int size = sizeof(arr) / sizeof(int);
    int element = 12;
    int index = linearsearch(arr, size, element);

    printf("The element %d was present at index %d\n", element, index);

    return 0;
}