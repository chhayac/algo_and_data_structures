/* Program to extract maximum numeric value from a given alphanumeric string.
 * For example:
 * Enter a string: 100klh564abc365bg
 * Maximum numeric value = 564
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void remove_newline(char str[]);
long long max_numeric_value(char str[]);

int main(void)
{
    char str[26];
    printf("Enter a string: ");
    fgets(str, 26, stdin);
    remove_newline(str);
    long long maximum = max_numeric_value(str);
    printf("Maximum numeric value = %lld\n", maximum);
    return 0;
 }

long long max_numeric_value(char str[])
{
    long long num = 0;
    long long max = 0;
    int len_str = strlen(str);
    for(int i = 0; i < len_str; i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            num = num * 10 + (str[i] - '0');
            if(num > max)
            {
                max = num;
            }
        }
        else
        {
            num = 0;
        }
    }
    return max;
}

void remove_newline(char* str)
{
    size_t len_str = strlen(str);
    len_str--;
    if(*str && str[len_str] == '\n')
    {
        str[len_str] ='\0';
    }
}
