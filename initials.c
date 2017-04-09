/*
 *  Generate initials of a given name.
 *  Example:
 *  Input  : John Alison Doe
 *  Output : JAD
 *  
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h> 

int main(void)
{
    char name[100]; 
    int i = 0;

    // pretend there's a space before the string
    // 
    char prev = ' ' ; 
    printf("Enter the name: ");

    // reads a line from the specified stream and stores it into the string
    //
    fgets(name, sizeof(name), stdin);

    while (name[i]!='\0') 
    {
        if ((name[i] != ' ' || name[i] != '\t'))     
        {
            if ((name[i] >= 'A' && name[i] <='Z') || (name[i] >= 'a' && name[i] <= 'z')) 
            {
                if(prev == ' ')
                {
                    putchar(toupper(name[i]));
                }
            }
        }
        prev = name[i];
        i++;
    }
    putchar('\n');
    return 0;
}
