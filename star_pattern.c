/* 
* Program to print the below star pattern of a specified height.

*
* *
* * *
* * * *
* * * * *

*/

#include <stdio.h>

int main(void)
{
       int n = 0;
    do{
            printf(" Enter the height of star pattern: ");
            scanf("%d", &n);
       } while(n < 0 || n > 23);  
     
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}
