/* Program to find the number Occurring Odd Number of Times in O(n) time & constant space.
 * Given an array of positive integers. All numbers occur even number of times 
 * except one number which occurs odd number of times.
 * 
 * Example:
 * Enter the number of elements: 11
 * Enter 11 elements of the array: 2 3 5 4 2 4 3 5 2 4 4
 * Number occuring odd number of times = 2
 */

#include <stdio.h>
#include <string.h>
#define MAX_SIZE 30

int odd_times(int arr[], int);

int main(void)
{
    int arr[MAX_SIZE];
    int size_array, odd_number_times;
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
    odd_number_times = odd_times(arr,size_array);
    printf("Number occuring odd number of times = %d\n", odd_number_times);
    return 0;
}

int odd_times(int arr[], int len)
{
    int i;
    int result = 0;
    for(i = 0; i < len; i++)
    {
        result = result ^ arr[i];
    }
    return result;
}
