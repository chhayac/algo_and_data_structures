/*  Program to search an element using binary search.
 *  Binary Search: An algorithm which search a sorted array by repeatedly dividing the search
 *  interval in half. Begin with an interval covering the whole array. 
 *  If the value of the search key is less than the item in the middle of the 
 *  interval, narrow the interval to the lower half. Otherwise narrow it to the
 *  upper half. Repeatedly check until the value is found or the interval is empty.
 *
 *  Example: 
 *  Enter the size of the array: 7
 *  Enter 7 elements of the array: 1 2 3 4 5 6 7
 *  Enter the element to search: 10
 *  Element is not present in the array
 *
 *  Example: Enter the size of the array: 2000
 *  Please enter value less than 1000
 *  Enter the size of the array:
 */

#include <stdio.h>
#define MAX_SIZE 1000

int binary_search(int arr[], int , int, int);

int main(void)
{
    int arr[MAX_SIZE];
    int size_array;
    int index;
    int element;
    do
    {
        printf("Enter the size of the array: ");
        scanf("%d", &size_array);
        if(size_array > MAX_SIZE)
        {
            printf("Please enter value less than 1000\n");
        }
     } while(size_array > MAX_SIZE);
    printf("Enter %d elements of the array: ", size_array);
    for(int i = 0; i < size_array; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d",&element);
    index = binary_search(arr, 0, size_array - 1, element);
    (index == -1)? printf("Element is not present in the array\n"):
                   printf("Element is present at index %d\n", index);
    return 0;
}


int binary_search(int arr[], int l, int r, int element)
{
    while(r >= l)
    {
        int mid = l + (r-l)/2;

        // check if element is present at mid position
        if(element == arr[mid])
        {
            return mid;
        }

        // check if element is greater than the mid element, ignore left half 
        if(element > arr[mid])
        {
            l = mid + 1;
        }

        // if element is less than the mid element, ignore right half 
        else
        {
            r = mid - 1;
        }
    }
    // if we reach here, element is not present
    return -1;
}
