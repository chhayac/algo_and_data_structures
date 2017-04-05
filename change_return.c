/* 
* Program to calculate the minimum number of coins required to give a user change.
*/

#include <stdio.h>
#include <math.h>

int main(void)
{   
    float m = 0.0;
    int min_coins = 0, n = 0;
    int quarters = 0, dimes = 0, nickels = 0, pennies = 0;
    printf("Hi! How much change is owed in dollars?\n");
    do
    {
        scanf("%f", &m);
    } while (m < 0);
    
    m = m * 100;            
    n = round(m);
  
    if (n >= 1)
    {
        quarters = n / 25;
        dimes = (n - (25 * quarters))/10;
        nickels = (n -(25 * quarters + 10 * dimes))/5;
        pennies= (n -(25 * quarters + 10 * dimes + 5 * nickels))/1;
    }
    
    min_coins = quarters + dimes + nickels + pennies;
    printf("Minimum number of coins required for change are: %d", min_coins);  
    printf("\n");
    
}