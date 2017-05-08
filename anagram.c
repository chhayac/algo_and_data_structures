/* Program to determine if two strings are anagram or not.
 * Example:
 * Enter 1st string: listen
 * Enter 2nd string: silent
 * The two strings are anagrams.
 *
 * Enter 1st string: tommarvoloriddle
 * Enter 2nd string: iamlordvoldemort
 * The two strings are anagrams.
 */ 

 #include <stdio.h>
 #include <string.h>
 #include <ctype.h>

 void remove_newline(char str[]);

int main(void)
{
    char str1[26], str2[26];
    char count[26] = {0};
    printf("Enter 1st string: "); 
    fgets(str1, 26, stdin);
    remove_newline(str1);

    printf("Enter 2nd string: ");
    fgets(str2, 26, stdin);
    remove_newline(str2);

    if(strlen(str1) != strlen(str2))
    {
        printf("The two strings are not anagrams.\n");
        return 0;
    }
    int len1 = strlen(str1);
    int len2 = strlen(str2); 
    int i,j;
    for(i = 0; i < len1; i++)
    {
        str1[i] = toupper(str1[i]);
        count[str1[i]-'A']++;
    }
    for(j = 0; j < len2; j++)
    {   
        str2[j] = toupper(str2[j]);
        count[str2[j]-'A']--;
    }
    for(i = 0; i < len2; i++)
    {
        if(count[str2[i]-'A'] != 0)
        {
            break;
        }   
    }
    if(i == len2)
    {
        printf("The two strings are anagrams.\n");
    }
    else
    {
        printf("The two strings are not anagrams.\n");
    }
    return 0;
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
