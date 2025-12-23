#include <stdio.h>

int binarySearch(int arr[], int size, int element)
{
    int low = 0, mid, high = size-1;

    // Keep searching until low is lessthan equal to high
    while (low<=high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    
    return -1;
}

int main()
{
    // Sorted array
    int arr[] = {1, 2, 5, 56, 64, 73, 123, 225, 444};
    int element = 1;
    int size = sizeof(arr) / sizeof(int);
    int searchIndex = binarySearch(arr, size, element);
    printf("The element %d was found at index %d \n", element, searchIndex);
    return 0;
}