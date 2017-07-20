/* Program to sort an array using Heap Sort.
 *
 * Input : 5,3,17,10,84,19,6,22,9
 * Output : 3 5 6 9 10 17 19 22 84
 *
 */

#include <stdio.h>
#include <math.h>
#define left(x) (2*x + 1)
#define right(x) (2*x + 2) 

void heapSort(int Arr[], int);
void heapify(int Arr[], int, int);
void printArray(int Arr[], int);

int main(void)
{
    int Arr[] = {5,3,17,10,84,19,6,22,9};
    int n = sizeof(Arr)/sizeof(Arr[0]);      // n is heap length / length of the array
    heapSort(Arr,n);
    printArray(Arr,n);
    return 0;
}

void heapSort(int Arr[], int n)
{
    int i;

    // Build heap i.e rearrange the array
    for(i = n/2 - 1; i >= 0 ; i--)
    {
        heapify(Arr, i, n);
    }

    // Extract an element from heap one by one
    for(i = n-1; i >= 0 ; i--)
    {
        int temp = Arr[i];
        Arr[i] = Arr[0];
        Arr[0] = temp;  
        // call heapify on the reduced heap
        heapify(Arr, 0, i);
    }
}

void heapify(int Arr[], int i, int n)
{
    int l = left(i);
    int r = right(i);
    int largest = i;    // Initialize largest as root

    // If left child is greater than root
    if(l < n && Arr[l] > Arr[i])
    {
        largest = l;
    }

    // If right child is greater than largest
    if(r < n && Arr[r] > Arr[largest])
    {
        largest = r;
    }

    // If largest is not root
    if(largest != i)
    {
        int temp = Arr[i];
        Arr[i] = Arr[largest];
        Arr[largest] = temp;
        heapify(Arr, largest, n);
    }

}

void printArray(int Arr[], int n)
{
    for (int i = 0; i < n ; i++)
    {
        printf("%d ",Arr[i]);
    }
    printf("\n");
}
