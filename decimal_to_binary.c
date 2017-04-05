/*
*  Develop a converter to convert a decimal number to its binary equivalent.
*/ 

#include <stdio.h>
#include <math.h>

int decimal_to_binary(int);

int main(void)
{
    int n, dec;
    printf("Enter a decimal value: ");
    scanf("%d", &n);
    dec = n;
    printf("The decimal value is %d\n", dec);
    
    // function to convert decimal to binary
    decimal_to_binary(n);
}

int decimal_to_binary(int n)
{
    int rem;
    int bin = 0, base = 1;
    while(n != 0)
    {
        rem = n % 2;
        bin = bin + rem * base;
        n = n / 2;
        base = base * 10;
    }
    printf("Binary equivalent is %d\n", bin);
    return 0;
}