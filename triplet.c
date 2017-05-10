/* Program to find if triplet exist for a given unsorted array with given sum
 * Example:
 * Enter the number of elements: 4
 * Enter 4 elements of the array: 2 7 4 0
 * Enter the sum to find for the triplet: 6
 * Triplet Exists
 */

#include <stdio.h>
#define MAX_SIZE 50

#define bool int
#define true 1
#define false 0

bool tripletExists(int arr[], int, int , int);

int main(void)
{
    int arr[MAX_SIZE];
    int size_array, sum;
    int count = 0;
    do
    {
        printf("Enter the number of elements: ");
        scanf("%d", &size_array);
        if(size_array > MAX_SIZE)
        {
            printf("Please enter value less than %d", MAX_SIZE);
        }
    }while(size_array > MAX_SIZE);
    printf("Enter %d elements of the array: ", size_array);
    for(int i = 0; i < size_array; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the sum to find for the triplet: ");
    scanf("%d", &sum);
    tripletExists(arr, size_array, sum, count)? printf("Triplet Exists\n") : printf("Triplet Don't Exist\n");
    return 0;
}

// Recursive function to check if triplet exists in array with given sum
bool tripletExists(int arr[], int n, int sum, int count)
{
    // return true if triplet has provided sum
    if(count == 3 && sum == 0)
    {   
        return true;
    }
    
    // return false if sum is not possible with current configuration
    if(count == 3 || n == 0 || sum < 0)
    {
        return false;
    }

    // Recursion with
    //1. Including current element
    //2. Excluding current element
    return tripletExists(arr, n - 1, sum - arr[n - 1], count + 1) ||
           tripletExists(arr, n - 1, sum, count);
}
