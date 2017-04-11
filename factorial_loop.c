/*
*  Program to calculate factorial of a number using loop
*  Example: 
*  Enter a number whose factorial you wish to calculate: 10
*  Factorial of 10 is 3628800
*/

#include <stdio.h>

unsigned long long factorial(int);

int main(void)
{
    int num;
    printf("Enter a number whose factorial you wish to calculate: ");
    scanf("%d", &num);
    unsigned long long number = factorial(num);
    printf("Factorial of %d is %llu\n", num, number);
    return 0;
}

// Function to find factorial of a number using for loop
//
unsigned long long factorial(int num)
{
    unsigned long long fact = 1;
    int n = num;
    for(int i = 1; i < num; i++)
    {
        fact = fact * n;
        n-= 1;
    }
    return fact;
}
