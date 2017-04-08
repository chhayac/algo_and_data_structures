/*
*  Program to determine whether a provided credit card number is valid according to Luhn’s algorithm.
*  According to Luhn’s algorithm, you can determine if a credit card number is (syntactically) valid as follows:
*  1. Multiply every other digit by 2, starting with the number’s second-to-last digit, 
*  and then add those products' digits together.
*  2. Add the sum to the sum of the digits that weren’t multiplied by 2.
*  3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is
*  congruent to 0), the number is valid!
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

int cleanStdin();
int countCreditCardDigits(long long);
int get_first_two_digits(long long, int);   
bool credit_card_type(int, int);
void validate_credit_card(long long);

int main(void)
{
    long long cc_num = 0;
    char n;
    int c = 0;
    bool firstTime = true;
    do
    {
        if (firstTime)
        {
            firstTime = false;
        }
        else
        {
            printf("Retry: ");
        }
        
        printf("Enter the credit card number without any dashes or space: ");
    } while ((scanf("%llu%c", &cc_num, &n) != 2 || n != '\n') && cleanStdin());
    
    c = countCreditCardDigits(cc_num);
    int start_digits = get_first_two_digits(cc_num, c);
    if (credit_card_type(c, start_digits))
    {
        validate_credit_card(cc_num);
    }
    return 0;
}

int cleanStdin()
{
    while(getchar() != '\n') { }
    return 1;
}

// function to count the number of digits in a credit card number
//
int countCreditCardDigits(long long n)
{
    int c = 0;
    while (n)
    {
        n /= 10;
        c++;
    }
    return c;
}

// function to return first two digits of a credit card number
//
int get_first_two_digits(long long n, int c)            
{
    return n / pow(10, (c - 2));
}

// function to find type of card based on
// on number of digits and first two digits
//
bool credit_card_type(int c, int start_digits)
{
    bool valid_credit_card = true;
    
    if(c == 15 && (start_digits == 34 || start_digits == 37))
    {
        printf("It's an American Express Credit Card\n");
    }
    else if(c == 16 && (start_digits >= 51 && start_digits <=55))
    {
        printf("It's a MasterCard\n");
    }
    else if((c == 13 || c == 16) && (start_digits >= 40 && start_digits <=50))
    {
        printf("It's a Visa Card\n");
    }       
    else
    {
        printf("Invalid Card\n" );
        valid_credit_card = false;
    }
    return valid_credit_card;
}        
 
// function to check checksum of a credit card number.
//
void validate_credit_card(long long n)
{   
    int rem = 0, total = 0, checksum = 0;
    int even_place = 0;
    int odds = 0, evens = 0;
    while(n)
    {
        odds += ( n % 10 );
        n = n / 10;
        even_place = n % 10;
        even_place *= 2;
        if(even_place > 9)              // checking if number is 2 or more digits, then add individual digits
        {   
            rem = even_place % 10;
            evens += (rem + 1);
        }
        else
        {   
            evens += even_place;
        }
        n = n / 10;
    }
    
    total = odds + evens;
    checksum = total % 10;
    if(checksum != 0)
    {
        printf("The credit card number is invalid\n");
    }
    else
    {
        printf("Success!! Credit card number is valid\n");
    }
}
