/*
 * Program to encrypt text using Caesar’s cipher, as per below.
 * Example: 
 * $ ./caesar 1
 * Input  : plaintext:  HELLO
 * Output : ciphertext: URYYB
 *
 * $ ./caesar 1 2 3 4 5
 * Usage: ./caesar k
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    char plain_text[100]; 
    int k = atoi(argv[1]);
    printf("Enter Plaintext: ");

    // reads a line from the specified stream and stores it into the string
    //
    fgets(plain_text, sizeof(plain_text), stdin);
    printf("Ciphertext: ");
    for (int i = 0, n = strlen(plain_text); i < n; i++)
    {
        if(plain_text[i] >= 'a' && plain_text[i] <= 'z')
        {
            int p = plain_text[i] - 'a';
            int c1 = (k + p) % 26;
            plain_text[i] = c1 + 'a';    
        }
        else if(plain_text[i] >= 'A' && plain_text[i] <= 'Z')
        {
            int p = plain_text[i] - 'A';
            int c1 = (k + p) % 26;
            plain_text[i] = c1 + 'A';   
        }
        printf("%c",plain_text[i]);
     }
}
