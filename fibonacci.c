
/*
This program generates a fibonacci sequence till nth term.
Fibonacci Sequence - Enter a number and have the program generate the Fibonacci
sequence (1,1,2,3,5,8,..) to that number or to the Nth number. 
*/

#include <stdio.h>

void fib(int);

int main(void)
{
    int n;
    printf("Enter the value of n:");
    scanf("%d",&n);  
    fib(n);
    return 0;
}
 
// function to print fibonacci series
void fib(int n)
{
    int a=0, b=1, c=1;
  
   for (int i = 1; i <= n ; i++)
   {
       if (i == n)
       {
            printf("%d\n", c);   
       }
       else
       {
            printf("%d, ", c);
       }
       c = a + b;
       a = b;
       b = c;
   }
}