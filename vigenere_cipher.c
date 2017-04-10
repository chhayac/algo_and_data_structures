/*
*  Program to encrypt text using Vigenère’s cipher, per the below.
*  Example: 
*  $ ./vigenere ABC
*  plaintext:  HELLO
*  ciphertext: HFNLP
*
*  For more Information: https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher
*
*  Example:
*  $ ./vigenere bacon
*  plaintext: Meet me at the park at eleven am
*  ciphertext: Negh zf av huf pcfx bt gzrwep oz
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

bool is_key_valid(char * key)
{
    unsigned int len = strlen(key);
    for (unsigned int i = 0; i < len; i++)
    {
        if ((key[i] < 'a' || key[i] > 'z') && (key[i] < 'A' ||  key[i] > 'Z'))
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    if (argc != 2 || (argc == 2 && !is_key_valid(argv[1])))
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    char plain_text[100];
    char *key = argv[1];
    printf("Plaintext: ");

    // reads a line from the specified stream and stores it into the string
    //
    fgets(plain_text, sizeof(plain_text), stdin);
    printf("Ciphertext: ");
    int n = strlen(plain_text);
    int key_len = strlen(key);
    int k1;
    int j = 0;
    for (int i = 0; i < n; i++)
    {   
        if((plain_text[i] >='A' && plain_text[i] <= 'Z') || (plain_text[i] >='a' && plain_text[i] <= 'z'))
        {
            int key_index = (j % key_len);
            if((key[key_index] >= 'A' && key[key_index] <= 'Z'))
            {
                k1 = key[key_index] - 'A'; 
            }
            else if (key[key_index] >= 'a' && key[key_index] <= 'z')
            {
                k1 = key[key_index] - 'a';
            }
            ++j;
        }
        if(plain_text[i] >='A' && plain_text[i] <= 'Z')
        {
            int p = plain_text[i] - 'A';
            int c = (p + k1) % 26;
            plain_text[i] = c + 'A';
        }
        else if(plain_text[i] >='a' && plain_text[i] <= 'z')
        {
            int p = plain_text[i] - 'a';
            int c = (p + k1) % 26;
            plain_text[i] = c + 'a';
        }
        printf("%c",plain_text[i]);
    }
}
