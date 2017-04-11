/*
*  Program to calculate factorial of a number using recursion method
*  Example: 
*  Enter a number whose factorial you wish to calculate: 20
*  Factorial of 20 is 2432902008176640000
*/

#include <stdio.h>

unsigned long long factorial(int);

int main(void)
{
    int num;
    printf("Enter a number whose factorial you wish to calculate: ");
    scanf("%d", &num);
    printf("Factorial of %d is %llu\n", num, factorial(num));
    return 0;
}

unsigned long long factorial(int num)
{   
    if(num < 2)
    {
        return 1;
    }   
    else
    {
        return(num * factorial(num - 1));
    }
}
