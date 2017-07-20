/* Program to sort numbers using Counting sort
 * Example:
 * Input array: 9 4 10 8 2 4
 * Output:
 * Sorted Array is: 2 4 4 8 9 10
 */

#include <stdio.h>
#include <string.h>
#define RANGE 255

void countingSort(int arr[]);
void printArray(int arr[], int);

int main()
{
    int arr[] = {9, 4, 10, 8, 2, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    countingSort(arr);
    printf("Sorted array is: ");
    printArray(arr, n);
    return 0;
}

void countingSort(int arr[])
{
    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));
    int Output[RANGE + 1];

    for(i = 0; arr[i]; i++)
    {
        count[arr[i]]++;
        printf("Array = %d, count= %d\n", arr[i], count[arr[i]]);
    }
    printf("range= %d", RANGE);
    for(i = 1; i <= RANGE; i++)
    {
        count[i] += count[i-1];  
        printf("Changed count = %d\n", count[i]);
    }

    for (int i = 0; arr[i]; i++)
    {
        Output[count[arr[i]]] = arr[i];
        count[arr[i]] -= 1;
        printf("Output = %d", Output[i]);
    }
    
    for(i = 0; arr[i]; i++)
    {
        arr[i] = Output[i];
    }
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
