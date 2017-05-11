/* Program to find the minimum length subarray arr[s..e] such that sorting this subarray makes the whole array sorted.
 * Example:
 * Enter the number of elements: 11
 * Enter 11 elements of the array: 10 12 20 30 25 40 32 31 35 50 60
 * The unsorted subarray which makes the given array sorted lies between the indices 3 and 8
 */

#include <stdio.h>
#define MAX_SIZE 20

void unsorted_subarray(int arr[], int);

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
            printf("Please enter values less than %d", MAX_SIZE);
        }
    }while(size_array > MAX_SIZE);
    printf("Enter %d elements of the array: ", size_array);
    for(int i = 0; i < size_array; i++)
    {
        scanf("%d", &arr[i]);
    }
    unsorted_subarray(arr, size_array);
    return 0;
}

void unsorted_subarray(int arr[], int n)
{
    int s = 0;
    int e = n-1;
    int i , max, min;

    // find the first element which is greater than the next element by scanning from left to right order.
    for (s = 0; s < n - 1; s++)
    {
        if(arr[s] > arr[s+1])
        {
            break;
        }
    }
    if(s == n - 1)
    {
        printf("The complete array is sorted\n");
        return;
    }
    
    // find the first element which is smaller than the next element by scanning from right to left order.
    for(e = n-1; e > 0; e--)
    {
        if(arr[e] < arr[e-1])
        {
            break;
        }
    }

    max = arr[s];
    min = arr[s];

    // find out the maximum and minimum element in the array arr[s..e]
    for (i = s + 1; i <= e; i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
        }
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }

    // find the first element in array [0...s-1] which is greater than min, if found change s to index of this element
    for(i = 0; i < s; i++)
    {
        if(arr[i] > min)
        {
            s = i;
            break;
        }
    }

    // find the last element in array [e+1..n-1] which is smaller than the max, if found change e to index of this element
    for(i = e+1; i < n; i++)
    {
        if(arr[i] < max)
        {
            e = i;
            break;
        }
    }

    // prints the index of the unsorted subarray 
    printf("The unsorted subarray which makes the given array "
         " sorted lies between the indices %d and %d\n", s, e);
}
