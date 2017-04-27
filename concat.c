/*  Program to concat two strings without using library function
 *  Enter 1st string: Today is a wonderful
 *  Enter 2nd string: day
 *  Concated string is "Today is a wonderfulday"
 */

#include <stdio.h>

void concat(char [], char []);
void remove_newline(char str[]);
size_t string_length(char str[]);

int main(void)
{
    char str1[100], str2[100];
    printf("Enter 1st string: ");
    fgets(str1, 100, stdin);
    remove_newline(str1);

    printf("Enter 2nd string: ");
    fgets(str2, 100, stdin);
    remove_newline(str2);

    concat(str1, str2);
    printf("Concated string is \"%s\"\n", str1);
    return 0;
}

void concat(char str1[], char str2[])
{
    int i,j;
    i = 0;
    while (str1[i] != '\0')
    {
        ++i;
    }
    for(j = 0; str2[j] != '\0'; i++,j++)
    {
        str1[i] = str2[j];
    }
    str1[i] = '\0';
}

void remove_newline(char* str)
{
    size_t len_str = string_length(str);
    len_str--;
    if (*str && str[len_str] == '\n') 
    str[len_str] = '\0';
}

size_t string_length(char * str)
{
    size_t len_str = 0;
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        len_str++;
    }
    return len_str;
}
