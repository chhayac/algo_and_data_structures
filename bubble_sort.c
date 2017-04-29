/*  Program to implement Bubble Sort
 *  Bubble Sort is a sorting algorithm that works by repeatedly 
 *  swapping the adjacent elements if they are in wrong order.
 *
 *  Example:
 *  Enter the size of the array:4
 *  Enter 4 elements in the array: 10 2 1 4
 *  Sorted array is: 1 2 4 10
 *
 *  Enter the size of the array: 1000
 *  Max size of array is 100. Please enter value less than 100
 *  Enter the size of the array: 
 */

#include <stdio.h>
#define MAX_SIZE 100  // maximum size of the array

#define bool int
#define true 1
#define false 0

void bubble_sort(int arr[], int);
void swap(int *a, int *b);
void printArray(int arr[], int);

int main(void)
{
    int arr[MAX_SIZE];
    int size_array;
    do
    {
        printf("Enter the size of the array: ");
        scanf("%d",&size_array);
        if(size_array > MAX_SIZE)
        {
            printf("Max size of array is 100. Please enter value less than 100.\n");
        }
    }while(size_array > MAX_SIZE);
    printf("Enter %d elements in the array: ", size_array);
    for(int i = 0; i < size_array; i++)
    {
        scanf("%d",&arr[i]);
    }

    bubble_sort(arr, size_array);
    printf("Sorted array is: ");
    printArray(arr, size_array);
    return 0;
}

/* Function to sort the array using bubble sort */
void bubble_sort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n-1 ; i++)
    {
        swapped = false;
        for(j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
                swapped = true;
            }
        }
        // If no two elements are swapped by inner loop, then break 
        if(swapped == false)
        break;
    }
}

/* Function to swap 2 values */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Function to print the sorted array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
