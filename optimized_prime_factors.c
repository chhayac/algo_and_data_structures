/*
*  Program to find all prime factors of a number less than 1000 using sieve of eratosthenes.
*/

#include <stdio.h>
#include <math.h>

void sieve (int *, int);
void printPrimeFactors(int);

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printPrimeFactors(n);
    return 0;
}

void printPrimeFactors(int n)
{
    if (n >= 1000)
    {
        printf("Your value is greater than 1000, program works for values less than 1000\n");
        return;
    }
    
    printf("The prime factors of %d are: ", n);
    
    int arr[1000] = { 0 };
    
    // Mark all prime numbers till n
    //
    sieve(arr, n);
    
    // Check if any prime is factor of n, if it is, print it.
    //
    for ( int i = 0; i < n; ++i)
    {
        if (arr[i] == 0)
        {
            if (n % i == 0)
            {
                printf("%d ", i);
            }
        }
    }
    
    printf("\n");
}

void sieve (int *arr, int n)
{
    if (n >= 1000)
    {
        printf("Your value is greater than 1000, program works for values less than 1000\n");
        return;
    }
    
    arr[0] = 1;
    arr[1] = 1;
    
    for (int i = 2; i <= sqrt(n); i++)
    {
        for (int j = 2; i * j <= n; j++)
        {
            if (arr[i * j] == 0)
            {
                arr[i * j] = 1;
            }
        }
    }
    
}
