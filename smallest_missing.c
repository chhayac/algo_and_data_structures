/* Program to find smallest missing element in a sorted array of distinct non-negative integers.
 * Example
 * Enter number of elements: 5
 * Enter 5 elements of the array: 0 1 2 3 6
 * Smallest missing element in the sorted array: 4
 */

#include <stdio.h>
#define MAX_SIZE 20

int smallestMissing(int arr[], int, int);

int main(void)
{
    int arr[MAX_SIZE];
    int n, low, high;
    do
    {
        printf("Enter number of elements: ");
        scanf("%d", &n);
        if(n > MAX_SIZE)
        {
            printf("Please enter value less than %d\n", MAX_SIZE);
        }
    }while(n > MAX_SIZE);
    printf("Enter %d elements of the array: ", n);
    for(int i = 0; i < n-1; i++)
    {
        scanf("%d", &arr[i]);
    }
    low = 0;
    high = n-1;
    int missing_element = smallestMissing(arr, low, high);
    printf("Smallest missing element in the sorted array: %d\n", missing_element);
    return 0;
}

// Function to find smallest missing element in sorted array
int smallestMissing(int arr[], int low, int high)
{
    // low is for leftmost index and high is for rightmost index
    if(low > high)
    {
        return low;
    }
    int mid = low + (high - low)/2;

    // if mid index matches the mid element, then mismatch lies on the right half of the array
    if(arr[mid] == mid)
    {
        return smallestMissing(arr, mid+1, high);
    }
    else
    {
        // mismatch lies on the left half
        return smallestMissing(arr, low, mid-1);
    }
}
