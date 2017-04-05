/*
*  Prime Factorization- Have the user enter a number and find all 
*  prime factors (if there are any) and display them.
*/

#include <stdio.h>
#include <math.h>

#define bool int
#define true 1
#define false 0

bool isPrime(int);

int main(void)
{
    int i, n;
    printf("Enter the value of n : ");
    scanf("%d", &n);
    printf("Prime factors of %d are ", n);
    for (i = 2; i <= n; i++)
    {
        if(n % i == 0)
        {
            if(isPrime(i))
            {
                printf("%d ", i);
            }
        }
    }
    printf("\n");
}

bool isPrime(int n)
{
     if (n == 2)
    {
        return true;
    }
    
    if (n < 2 || n % 2 == 0)
    {
        return false;
    }
    
    for (int i = 2; i <= sqrt(n) ; i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}