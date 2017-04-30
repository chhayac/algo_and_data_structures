/*  Program to implement Insertion Sort
 *  The insertion sort algorithm is a simple sorting algorithm which sorts the array by shifting elements one by one.
 * 
 *  Example:
 *  Enter 4 elements of the array: 12 11 13 5
 *  Sorted array:
 *  5 11 12 13
 *  
 *  Enter the number of elements in the array: 120
 *  Please enter value less than 50
 *  Enter the number of elements in the array:
 */

#include <stdio.h>
#define MAX_SIZE 100

void insertion_sort(int arr[], int);
void printArray(int arr[], int);

int main(void)
{
    int arr[MAX_SIZE];
    int size_array;
    do
    {
        printf("Enter the number of elements in the array: ");
        scanf("%d", &size_array);
        if(size_array > MAX_SIZE)
        {
            printf("Please enter value less than 100\n");
        }
    } while(size_array > MAX_SIZE);

    printf("Enter %d elements of the array: ", size_array);
    for(int i = 0; i < size_array; i++)
    {
        scanf("%d", &arr[i]);
    }
    insertion_sort(arr, size_array);
    printf("Sorted array:\n");
    printArray(arr, size_array);
    return 0;
}

void insertion_sort(int arr[], int n)
{
    int i, j, key;
    for(i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
