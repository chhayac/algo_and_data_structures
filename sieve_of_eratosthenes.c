/* 
*  Program to implement Sieve of Eratosthenes problem - Have the user enter any number till 1000
*  and the display all prime numbers up to the number entered by the user.
*/

#include <stdio.h>
#include <math.h>

void sieve(int n);
    
int main(void)
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Prime numbers till %d are ", n);
    sieve(n);
    return 0;
}

void sieve (int n)
{   
    if (n >= 1000)
    {
        printf("Please enter a value less than 1000.\n");
        return;
    }
    int arr[1000] = {0};
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i <= sqrt(n); i++)
    {
        for (int j = 2; i * j <= n; j++)
        {
            arr[i * j] = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}


