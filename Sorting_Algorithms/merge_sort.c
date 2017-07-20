/* Program to implement merge sort.
 * Merge Sort is a Divide and Conquer algorithm. It divides input array in two halves, 
 * calls itself for the two halves and then merges the two sorted halves. 
 * The merge() function is used for merging two halves. 
 * 
 * Example: 
 * Enter the number of elements: 5
 * Enter 5 elements of the array: 3 2 1 5 4
 * Sorted array:
 * 1 2 3 4 5
 */

#include<stdio.h>
#define MAX_SIZE 100

void mergeSort(int arr[], int , int);
void merge(int arr[], int , int, int);
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
    mergeSort(arr, 0, size_array - 1);
    printf("Sorted array:\n");
    printArray(arr, size_array);
    return 0;
}

void mergeSort(int arr[], int l, int r)
{
    if(r > l)
    {
        int mid = l + (r-l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

//l is left index and r is right index
void merge(int arr[], int l, int mid, int r)
{
    int i = 0, j = 0, k = 0;
    int n1 = mid-l+1;
    int n2 = r-mid;

    // create two temporary arrays L and R of size n1 and n2
    int L[n1], R[n2];

    for(i = 0; i < n1; i++)
    {
        L[i] = arr[l+i];
    }
    for(j = 0; j< n2; j++)
    {
        R[j] = arr[mid+j+1];
    }

    /* merge temp arrays back to arr[l..r]  */
    i = 0;   // initial index of 1st subarray
    j = 0;   // initial index of 2nd subarray
    k = l;   // initial index of merge  subarray

    while( i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
