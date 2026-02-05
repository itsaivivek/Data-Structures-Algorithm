#include<stdio.h>

void printArray(int *A, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}


void insetionSort(int *A, int n){
    int key, j;
    for (int i = 1; i <= n-1; i++) // Loop for n-1 passes
    { 
        key = A[i];
        j = i-1;
        while (j>= 0 && A[j] > key) // Loop for each pass
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
    
}

int main()
{ 
    int A[] = {12, 54, 65, 7, 23, 9}; // unsorted array
    int n = 6;
    printArray(A, n);
    insetionSort(A, n);
    printf("After sorting\n");
    printArray(A, n);
    return 0;
}