/* Program to search element of an array using linear search.
 * Example:
 * Enter the size of the array: 4
 * Enter 4 elements of the array: 2 4 1 8
 * Enter the element to search: 8
 * Element is found at index 3
 */

#include <stdio.h>
#define MAX_SIZE 50

#define bool int
#define true 1
#define false 0

int linear_search(int arr[], int, int);

int main(void)
{
    int arr[MAX_SIZE];
    int n, element;
    int index;
    do 
    {
        printf("Enter the size of the array: ");
        scanf("%d", &n);
        if(n > MAX_SIZE)
        {
            printf("Please enter value less than 50\n");
        }
    }while(n > MAX_SIZE);
    printf("Enter %d elements of the array: ", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d",&element);
    index = linear_search(arr, n, element);
    if(index == -1)
    {   
        printf("Element not found\n");
    }
    else
    {
        printf("Element is found at index %d\n", index);
    }
    return 0;
}

int linear_search(int arr[], int n, int element)
{
    int i;
    for(i = 0; i < n ; i++)
    {
        if(element == arr[i])
        {
            return i;
        }
    }
    return -1;
}
