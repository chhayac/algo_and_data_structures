/* Given a sorted array with possibly duplicate elements, the task 
 * is to find indexes of first and last occurrences of an element x in the given array.
 * Example:
 * Enter number of elements: 10
 * Enter the elements of the array: 1 3 5 5 5 5 6 8 10 11
 * Enter the element whose occurence you want to find: 5
 * First occurence = 2
 * Last occurence = 5
 * 
 * Enter number of elements: 10
 * Enter the elements of the array: 1 3 5 5 5 5 6 8 10 11
 * Enter the element whose occurence you want to find: 8
 * First occurence = 7
 * Last occurence = 7
 */

#include<stdio.h>
#define MAX_SIZE 30

void occurence(int arr[], int, int);

int main(void)
{
    int arr[MAX_SIZE];
    int n;              // n being size of the array
    int element;
    do
    {
        printf("Enter number of elements: ");
        scanf("%d", &n);
        if(n > MAX_SIZE)
        {
            printf("Please enter value less than %d\n", MAX_SIZE);
        }
    }while(n > MAX_SIZE);
    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element whose occurence you want to find: ");
    scanf("%d", &element);
    occurence(arr,n, element);
    return 0;
}

void occurence(int arr[], int n, int element)
{
    int i, j, s, e =0;
    int flag = 0;
    for (i = 0; i < n; i++)
    {
        if(arr[i] == element)
        {
            flag = 1;
            s = i;
            break;
        }
    }
    for (j = n - 1; j >= 0; j--)
    {
        if(arr[j] == element)
        {
            flag = 1;
            e = j;
            break;
        }
    }

    if (flag == 1)
    {
        printf("First occurence = %d\n", s);
        printf("Last occurence = %d\n", e);
    }
    else
    {
        printf("Element not found\n");
    }
}
