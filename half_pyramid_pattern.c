/* 
*  Program to print out a half-pyramid of a specified height.

    ##
   ###
  #### 
 #####
######

*/

#include <stdio.h>

int main(void)
{
    int n = 0;
    do{
            printf(" Enter the height of half-pyramid: ");
            scanf("%d", &n);
       } while(n < 0 || n > 23); 
       
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<= (n-i); j++)
        {
            printf(" ");
        }
        for(int k=0; k<=i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}


