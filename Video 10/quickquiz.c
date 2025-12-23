// Modify the program insertion.c such that you have to display array only when insertion is successful otherwise not(when insertion failed)

#include<stdio.h>

void display(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int indInsertion(int arr[], int size, int element, int capacity, int index){
    if (size>=capacity)
    {
        return -1;
    }
    for (int i = size-1; i >= index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1;
    
}

int main()
{
    int arr[100] = {7,8,12,27,88};
    int size = 5, capacity= 100, element = 45, index = 1;
    display(arr, size);
    int insertion_status;
    insertion_status = indInsertion(arr, size, element, capacity, index);
    size+=1;

    if (insertion_status == 1)
    {
        printf("Insertion successful\n");
        display(arr, size);
    }
    else{
        printf("Insertion failed");
    }
    
    return 0;
}