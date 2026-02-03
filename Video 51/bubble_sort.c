#include<stdio.h>

void printArray(int A[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}

// If the array is unsorted then timecomplexity = O(n^2)
// If the array is already sorted then timecomplexity = O(n)
void bubbleSort(int A[], int n){ // This is Adaptive bubble sort
    int temp;
    int isSorted = 0; // Making a variable to check if array is already sorted or not. For now isSorted = 0 means array not sorted already
    for (int i = 0; i < n-1; i++) // loop for number of pass that is n-1 passes
    {
        printf("Working on pass number %d\n", i+1); // shows the number of passes.
        isSorted = 1; // Making isSorted = 1(true) before entering into comparison
        for (int j = 0; j < n-1-i; j++) // loop for comparison in each pass
        {
            if (A[j] > A[j+1])
            {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                isSorted = 0; // if first element is greater than second than it comes inside this block and isSorted becomes false
            }
            
        }
        // checking if isSorted is true before going to another pass
        if (isSorted) // is array isSorted than return the function
        {
            return;
        }
        
        
    }
    
}

int main()
{
    // int A[] = {12, 54, 65, 7, 23, 9}; // unsorted array
    int A[] = {1, 2, 3, 4, 5, 6}; // sorted array
    int n = 6;
    printf("Array before sorting:\n");
    printArray(A, n);
    bubbleSort(A, n); // function to sort the array
    printf("Array after sorting:\n");
    printArray(A, n);
    return 0;
}