/*  Program to implement Selection Sort
 *  The selection sort algorithm sorts an array by repeatedly 
 *  finding the minimum element (considering ascending order) from 
 *  unsorted part and putting it at the beginning. 
 * 
 *  Example:
 *  Enter 4 elements of the array: 3 2 1 6
 *  Sorted array:
 *  1 2 3 6
 *  
 *  Enter the number of elements in the array: 101
 *  Please enter value less than 100
 *  Enter the number of elements in the array:
 */

#include <stdio.h>
#define MAX_SIZE 100

void swap(int *a, int *b);
void selection_sort(int arr[], int);
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
    selection_sort(arr, size_array);
    printf("Sorted array:\n");
    printArray(arr, size_array);
    return 0;
}

void selection_sort(int arr[], int n)
{
    int i,j , min_index;
    for(i = 0; i < n-1; i++)
    {
        min_index = i;
        for(j = i+1; j < n; j++)
        {
            if(arr[j] < arr[min_index])
            {
                min_index = j;
            }
        } 
        swap(&arr[min_index], &arr[i]);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
