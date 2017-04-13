/* Program to check if a given string is a palindrome.
*  Example: 
*  Enter the string: ALA
*  String is a palindrome.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char c[20], reverse_string[20] = {'\0'};
    int i, len = 0, flag = 0;
    printf("Enter the string: ");
    gets(c);
    len = strlen(c);

    for(i = len - 1; i >= 0; i--)
    {
        reverse_string[len - i - 1] = c[i];
    }

    for(i = 0; i < len; i++)
    {
        if(reverse_string[i] == c[i])
        {
            flag = 1;
        }
        else
        {
            flag = 0;
        }
    }
    if(flag == 1)
    {
        printf("String is a palindrome.\n");
    }
    else if(flag == 0)
    {
        printf("String is not a palindrome.\n");
    }
}
