/*
*  Program to print the reverse of a string
*/

#include <stdio.h>

int main(void)
{
    char str[20];
    char reverse_string[20] = {'\0'};
    unsigned int len = 0;
    printf("Enter the string: ");
    fgets(str, 20, stdin);
    int i;
    for (i = 0; i < str[i] != 0; i++)
    {
        len++;
    }
    printf("Reverse of the string is ");
    for(i = len - 1; i >= 0; i--)
    {
        reverse_string[len - i - 1] = str[i];
        printf("%c", reverse_string[len-i-1]);
    }
    printf("\n");
}
