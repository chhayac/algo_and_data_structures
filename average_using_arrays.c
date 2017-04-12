/* Program to calculate average of numbers using arrays
* Example:
* Enter the number of elements: 6
* Enter number1: 1
* Enter number2: 2
* Enter number3: 3
* Enter number4: 4
* Enter number5: 5
* Enter number6: 6
* Sum of 6 numbers is 21.00
* Average of 6 numbers is 3.50
*/

#include <stdio.h>

int main(void)
{
    float num[100], sum = 0.0, average = 0.0;
    int i, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    while(n > 100 || n <= 0)
    {
        printf("Please enter value between 1 and 100.\n");
        printf("Enter the number of elements again: ");
        scanf("%d", &n);
    }
    for (i = 0; i < n; i++)
    {
        printf("Enter number%d: ",i+1);
        scanf("%f",&num[i]);
        sum += num[i];
    }
    average = sum / n;
    printf("Sum of the %d numbers is %0.2f\n",n, sum);
    printf("Average of the %d numbers is %0.2f\n", n, average);
    return 0;
}
