#include<stdio.h>

void display(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int getMax(int arr[], int n){
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        
    }
    return max;
}

void countSort(int arr[], int n){
    // Find Max element
    int max = getMax(arr, n);

    // Make count/freq array of size (max+1) and initialize all element by 0
    int count[max+1];
    for (int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    // Store the frequency in count array
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    
    // Make cumulative count
    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i-1];
    }

    // Loop through the arr from last to first and then decrement the cumulative count and store new value
    int output[n];
    for (int i = n-1; i >= 0; i--)
    {
        output[--count[arr[i]]] = arr[i];
    }

    // Store the sorted value in original array
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
    
}

int main()
{
    int arr[] = {3, 2, 5, 2, 1};
    int n = 5;
    display(arr, n);
    countSort(arr, n);
    display(arr, n);
    return 0;
}