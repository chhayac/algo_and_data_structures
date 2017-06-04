/* Program to build max heap with an input array
 *
 * Input : 5,3,17,10,84,19,6,22,9
 * Output : 84 22 19 10 3 17 6 5 9
 *
 */

#include <stdio.h>
#include <math.h>
#define left(x) (2*x + 1)
#define right(x) (2*x + 2) 

void build_maxheap(int Arr[], int);
void max_heapify(int Arr[], int, int);
void printArray(int Arr[], int);

int main(void)
{
    int Arr[] = {5,3,17,10,84,19,6,22,9};
    int n = sizeof(Arr)/sizeof(Arr[0]);      // n is heap length / length of the array
    build_maxheap(Arr,n);
    printArray(Arr,n);
    return 0;
}

void build_maxheap(int Arr[], int n)
{
    int i;
    for(i = n/2 - 1; i >= 0 ; i--)
    {
        max_heapify(Arr, i, n);
    }
}

void max_heapify(int Arr[], int i, int n)
{
    int l = left(i);
    int r = right(i);
    int largest ;
    if(l < n && Arr[l] > Arr[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }
    if(r < n && Arr[r] > Arr[largest])
    {
        largest = r;
    }
    if(largest != i)
    {
        int temp = Arr[i];
        Arr[i] = Arr[largest];
        Arr[largest] = temp;
        max_heapify(Arr, largest, n);
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
