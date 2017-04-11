/*
*  Program to convert various units(temperature, currency and weight) from one type to other.
*  The user enters the type of unit, the type of unit they want to convert
*  to and then the value. The program will then make the conversion.
*
*  Example: 
*  1. Temperature
*  2. Currency
*  3. Weight
*  Enter the unit for conversion: 1
*  1. Celsius to Fahrenheit
*  2. Fahrenheit to Celsius
*  Enter the type of conversion you wish to do: 2
*  Enter the temperature in Fahrenheit: 200
*  200.000000 degree celsius to degree fahrenheit is 93.3
*/

#include <stdio.h>
#include <math.h>

void convert_temp(void);
void convert_currency(void);
void convert_weight(void);
void celsius_to_fahrenheit(float);
void fahrenheit_to_celsius(float);
void indian_rupee_to_usd(float);
void usd_to_indian_rupee(float);
void kilogram_to_pound(float);
void pound_to_kilogram(float);

int main(void)
{
    int unit;
    printf("1. Temperature\n");
    printf("2. Currency\n");
    printf("3. Weight\n");
    printf("Enter the unit for conversion: ");
    scanf("%d",&unit);
    switch(unit)
    {
        case 1:
            convert_temp();
            break;
        case 2:
            convert_currency();
            break;
        case 3:
            convert_weight();
            break;
        default:
            printf("Invalid option");
    }
    return 0;
}

void convert_temp(void)
{   
    int index; 
    float celsius, fahrenheit;
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter the type of conversion you wish to do: ");
    scanf("%d", &index);
    switch(index)
    {
        case 1:
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &celsius);
            celsius_to_fahrenheit(celsius);
            break;
        case 2:
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            fahrenheit_to_celsius(fahrenheit);
            break;
    }
}

// function to convert degree celsius to degree fahrenheit 
//
void celsius_to_fahrenheit(float celsius)
{
    float fahren;
    fahren = (celsius * 9/5) + 32;
    printf("%f degree celsius to degree fahrenheit is %0.1f\n", celsius, fahren);
}

// function to convert degree fahrenheit to degree celsius
//
void fahrenheit_to_celsius(float fahrenheit)
{
    float celsius;
    celsius = (fahrenheit - 32) * 5/9;
    printf("%f degree celsius to degree fahrenheit is %0.1f\n", fahrenheit, celsius);
}

void convert_currency(void)
{   
    int index; 
    float inr, usd;
    printf("1. Indian Rupee to US Dollar\n");
    printf("2. US Dollar to Indian Rupee\n");
    printf("Enter the type of conversion you wish to do: ");
    scanf("%d", &index);
    switch(index)
    {
        case 1:
            printf("Enter the value in Indian rupee: ");
            scanf("%f", &inr);
            indian_rupee_to_usd(inr);
            break;
        case 2:
            printf("Enter the value in US dollar: ");
            scanf("%f", &usd);
            usd_to_indian_rupee(usd);
            break;
    }
}

// function to convert Indian Rupee to US dollar
//
void indian_rupee_to_usd(float inr)
{
    float usd;
    usd = inr * 0.015;
    printf("%f Indian rupee is %0.1f US dollar\n", inr, usd);
}

// function to convert US dollar to Indian Rupee
//
void usd_to_indian_rupee(float usd)
{
    float inr;
    inr = usd * 64.56;
    printf("%f US dollar is %0.1f Indian rupee\n", usd, inr);
}

void convert_weight(void)
{   
    int index; 
    float kg, pound;
    printf("1. Kilogram to Pound\n");
    printf("2. Pound to Kilogram\n");
    printf("Enter the type of conversion you wish to do: ");
    scanf("%d", &index);
    switch(index)
    {
        case 1:
            printf("Enter the weight in kilogram: ");
            scanf("%f", &kg);
            kilogram_to_pound(kg);
            break;
        case 2:
            printf("Enter the weight in pound: ");
            scanf("%f", &pound);
            pound_to_kilogram(pound);
            break;
    }
}

// function to convert kilogram to pound
//
void kilogram_to_pound(float kg)
{
    float pound;
    pound = kg * 2.2046;
    printf("%f kilogram is %0.1f pound\n", kg, pound);
}

// function to convert pound to kilogram
//
void pound_to_kilogram(float pound)
{
    float kg;
    kg = pound * 0.453592;
    printf("%f pound is %0.1f kilogram\n", pound, kg);
}
