/* Program to check if a given postive number is a happy number or not.
*
*  A happy number is a number defined by the following process: Starting with any
*  positive integer, replace the number by the sum of the squares of its digits, 
*  and repeat the process until the number equals 1 (where it will stay), or it loops 
*  endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
*  Example: 
*  Enter a positive number: 82
*  Number entered is a happy number.
*/

#include <stdio.h>
void isHappy(int);

int main(void)
{
    int num;
    printf("Enter a positive number: ");
    scanf("%d", &num);
    isHappy(num);  
    return 0; 
}

void isHappy(int num)
{
    int digit = 0;
    while(num!=1 && num!=4)
    {
        int sum = 0;
        while(num > 0)
        {
            digit  = num % 10;
            num = num / 10;
            sum += digit * digit; 
        }
        num = sum;
    }
    if(num == 1)
    {
        printf("Number entered is a happy number.\n");
    }
    else
    {
        printf("Number entered is not a happy number.\n");
    }
}
