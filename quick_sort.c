/* Program to implement Quick Sort.
 * QuickSort is a Divide and Conquer algorithm. It picks an 
 * element as pivot and partitions the given array around the picked pivot.
 * We have taken laste element as pivot in the function partition.
 * The key process in quickSort is partition(). Target of partitions is, 
 * given an array and an element x of array as pivot, put x at its correct position in sorted array 
 * and put all smaller elements (smaller than x) before x, and put all greater elements (greater than x) after x.
 * 
 * Example:
 * Enter 5 elements of the array: 10 30 80 20 70
 * Sorted array:
 * 10 20 30 70 80
 */

#include<stdio.h>
#define MAX_SIZE 100

int partition(int arr[], int, int);
void QuickSort(int arr[], int, int);
void swap(int *, int *);
void printArray(int arr[], int);

int main(void)
{
    int arr[MAX_SIZE];
    int size_array;
    do
    {
        printf("Enter the number of elements: ");
        scanf("%d", &size_array);
        if(size_array > MAX_SIZE)
        {
            printf("Please enter value less than %d\n", MAX_SIZE);
        }
    }while(size_array > MAX_SIZE);
    printf("Enter %d elements of the array: ", size_array);
    for(int i = 0; i < size_array; i++)
    {
        scanf("%d",&arr[i]);
    }
    QuickSort(arr, 0, size_array - 1);
    printf("Sorted array:\n");
    printArray(arr, size_array);
    return 0;
}

void QuickSort(int arr[], int left_index, int right_index)
{
    int pi;
    if(right_index > left_index)
    {
        // pi is partitioning index
        pi = partition(arr, left_index, right_index);
        QuickSort(arr, left_index, pi-1);              // before pi
        QuickSort(arr, pi+1, right_index);             // After pi
    }
}

/* This function takes last element as pivot, places the pivot element at its correct position in sorted
   array, and places all elements smaller than pivot to the left of pivot and all elements greater than 
   pivot to the right of pivot */
int partition(int arr[], int low, int high)
{
    int i,j;
    int pivot = arr[high];
    i = low-1;    // index of smaller element
    for(j = low; j <= high-1; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;                  // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

// function to swap two values
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
