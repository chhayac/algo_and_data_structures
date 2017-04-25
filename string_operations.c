/*
* Program to perform string operations copy and compare without using string functions.
* Example: 
* 1.Copy String
* 2.Compare String
* 3.Quit
*
* Enter your choice:1
* Enter a string: My name is Derek
* Copied string is: My name is Derek
*
* Enter your choice:2
* Enter 1st string: Fish
* Enter 2nd string: Food
* Compare result from program is -6
* String function strcmp result is -6
* String2 > String1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copy(char str2[], char str1[]);
int compare(char str1[], char str2[]);
int smaller(int, int);
void remove_newline(char str[]);
size_t string_length(char str[]);

int main(void)
{
    int option, result;
    char str1[100], str2[100];
    printf("1.Copy String\n");
    printf("2.Compare String\n");
    printf("3.Quit\n");
    printf("Enter your choice:");
    scanf("%d", &option);
    int c;
    while((c = getchar()) != '\n' && c != EOF);
    switch(option)
    {
        case 1:
            printf("Enter a string: ");
            fgets(str1, 100 , stdin);
            copy(str2, str1);
            printf("Copied string is: %s",str2);
            break;

        case 2:
            printf("Enter 1st string: ");
            fgets(str1,100, stdin);
            remove_newline(str1);

            printf("Enter 2nd string: ");
            fgets(str2, 100, stdin);
            remove_newline(str2);

            result = compare(str1, str2);
            printf("Compare result from program is %d\n", result);
            printf("String function strcmp result is %d\n", strcmp(str1,str2));
            if(result > 0)
            {
                printf("String1 > String2\n");
            }
            else if(result < 0)
            {
                printf("String2 > String1\n");
            }
            else if(result == 0)
            {
                printf("String1 and String2 are same\n");
            }
            break;

        default:
            printf("Invalid choice\n");
            break;
    }
}

void copy(char str2[], char str1[])
{
    int i = 0;
    while(str1[i] != '\0')
    {
        str2[i] = str1[i];
        i++;
    }
    str2[i] = '\0';
}

int compare(char str1[], char str2[])
{
    size_t i = 0;
    size_t len_str1 = string_length(str1);
    size_t len_str2 = string_length(str2);
    size_t smallerLength = smaller(len_str1, len_str2);

    char * smallerstring;
    if(len_str1 == smallerLength)
    {
        smallerstring = str1;
    }
    else
    {
        smallerstring = str2;
    }
    i = 0;
    while(smallerstring[i] != '\0')
    {
        if(str1[i] != str2[i])
        {
            return str1[i] - str2[i];
        }
        i++;
    }
    if (i < len_str1)
    {
        return str1[i];
    }
    else if (i < len_str2)
    {
        return -str2[i];
    }
    return 0;
}

int smaller(int len_str1, int len_str2)
{
    return len_str1 < len_str2 ? len_str1 : len_str2;
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

void remove_newline(char* str)
{
    size_t len_str = string_length(str);
    len_str--;
    if (*str && str[len_str] == '\n') 
    str[len_str] = '\0';
}
