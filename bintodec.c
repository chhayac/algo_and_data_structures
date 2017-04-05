/* 
*  Program in C to develop a converter to convert a binary number to its decimal equivalent.
*/

#include <stdio.h>
#include <math.h>

int binary_to_decimal(int);

int main(void)
{
    int n, bin;
    printf("Enter a binary number (only 1s and 0s) :");
    scanf("%d", &n);
    bin = n;
    printf("Binary value is %d\n", bin);
    
    // function to convert binary to decimal
    binary_to_decimal(n);
}


int binary_to_decimal(int n)
{
    int rem;
    int dec = 0, base = 1;
    while(n > 0)
    {
        rem = n % 10;
        dec = dec + rem * base;
        n = n / 10;
        base = base * 2;
    }
    
    printf("Decimal equivalent is %d\n", dec);
    return 0;
}