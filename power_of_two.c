/* Program to check if an integer is a power of two.
*  Example:
*  Enter the number to check if it is power of 2: 64
*  Number is a power of 2
*/

#include <stdio.h>

int isPoweroftwo(int);

int main(void)
{
    int n;
    printf("Enter the number to check if it is power of 2: ");
    scanf("%d", &n);  
    int istrue = isPoweroftwo(n);
    if(istrue == 1)
    {
        printf("Number is a power of 2\n");
    }
    else
    {
        printf("Number is not a power of 2\n");
    }
}

int isPoweroftwo(int n)
{
    return((n > 0) && (n & (n-1)) == 0);
}
