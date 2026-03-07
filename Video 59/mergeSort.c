#include <stdio.h>

void printArray(int *A, int n) {
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int A[], int mid, int low, int high) {
    int i, j, k, B[high - low + 1];
    i = low;
    j = mid + 1;
    k = 0; // Initialize k to 0 for the temporary array B

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i<=mid)
    {
        B[k] = A[i];
        i++; k++;
    }
    while (j<=high)
    {
        B[k] = A[j];
        j++; k++;
    }

    for (i = low, k = 0; i <= high; i++, k++)
    {
        A[i] = B[k];
    }
}

void mergeSort(int A[], int low, int high){
    int mid;
    if (low<high)
    {
        // Using integer division to find the middle
        mid = low + (high - low) / 2; 
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, mid, low, high);
    }
}

int main() {
    int A[] = {9, 14, 4, 8, 7, 5, 1};
    int n = 7;
    printf("Original array: ");
    printArray(A, n);
    mergeSort(A, 0, n - 1); // Pass n - 1 as the initial high index
    printf("Sorted array: ");
    printArray(A, n);
    return 0;
}
