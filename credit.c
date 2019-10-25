#include <cs50.h>
#include <stdio.h>

bool checkAmex(long);
bool checkMasterLongVisa(long);
bool checkShortVisa(long);
long powerOfL(int, int);
bool checkValidLength(long);
bool checkValidLuhn(long);
int getLongLength(long);
int sumDigits(int[], int);
bool isTwoDigits(int);
bool printCard(long);

int main(void)
{
    bool validLength = false;
    bool validLuhn = false;
    long card;
    while (true)
    {
        
        // Get card details
        card = get_long("Enter card details\n");
        
        // printf("%i\n", getLongLength(card));
        // Check the length is OK
        if (!checkValidLength(card))
        {
            printf("INVALID\n");
            break;
        }
        // Check luhn's algorithm works on card
        if (!checkValidLuhn(card))
        {
            printf("INVALID\n");
            break;
        }
        
        if (!printCard(card))
        {
            printf("INVALID\n");
            break;
        }
        break;
        
    }
    
}

// Take card details Get_Long
// Checks if valid using luhn algorthim
// If valid, check which card it is using lookup table

// Checks if length matches amex length
bool checkAmex(long input)
{
    if (input >= powerOfL(10, 14) && input < powerOfL(10, 15))
    {
        return true;
    }
    return false;
}

// Checks if length matches long visa or master length
bool checkMasterLongVisa(long input)
{
    if (input >= powerOfL(10, 15) && input < powerOfL(10, 16))
    {
        return true;
    }
    return false;
}

// Checks if length matches the short visa length
bool checkShortVisa(long input)
{
    if (input >= powerOfL(10, 12) && input < powerOfL(10, 13))
    {
        return true;
    }    
    return false;
}

// Uses prior length functions to check valid card length
bool checkValidLength(long input)
{
    if (checkAmex(input) || checkMasterLongVisa(input) || checkShortVisa(input))
    {
        return true;
    }
    return false;
}

// Validates card using luhn's Algorithm
bool checkValidLuhn(long input)
{
    long temp = input;
    int length = getLongLength(temp);
    int sum[length / 2];
    int finalSum = 0;
    
    // Starting second to last digit
    for (int i = 0; i < length / 2; i++)
    {
        temp /= 10;
        sum[i] = (temp % 10) * 2;
        temp /= 10;
    }
    
    // Sum arrays' digits
    finalSum += sumDigits(sum, length / 2);
    
    // Add remaining digits from initial input to get final answer
    for (int i = 0; i <= length / 2; i++)
    {
        finalSum += input % 10;
        input /= 100;
    }
    
    // Check if valid calculation
    if (finalSum % 10 == 0)
    {
        return true;
    }
    return false;
}

// Returns sum of an int array
int sumDigits(int input[], int l)
{
    int total = 0;
    for (int i = 0; i < l; i++)
    {
        if (isTwoDigits(input[i]))
        {
            total += input[i] % 10;
            total += (input[i] / 10) % 10;
            continue;
        }
        total += input[i];
    }
    return total;
}

// Function to check if an integer is over 1 digit long, does not work over 99
bool isTwoDigits(int input)
{
    input /= 10;
    if (input % 10 == 0)
    {
        return false;
    }
    return true;
}

// Establishes the length of an inputted value
int getLongLength(long input)
{
    long comparison = 10;
    int length = 1;
    while (comparison < input)
    {
        comparison *= 10;
        length++;
    }
    return length;
}

bool printCard(long input)
{
    // if else statements containing ifs to check first card numbers
    if (checkAmex(input))
    {
        int digits = input / powerOfL(10, 13) % 100;
        if (digits == 34 || digits == 37)
        {
            printf("AMEX\n");
            return true;
        }
    }
    else if (checkMasterLongVisa(input))
    {
        int digits = input / powerOfL(10, 14) % 100;
        if (digits >= 51 && digits <= 55)
        {
            printf("MASTERCARD\n");
            return true;
        }
        else if ((digits / 10 % 10) == 4)
        {
            printf("VISA\n");
            return true;
        }
    }
    else if (checkShortVisa(input))
    {
        int digits = input / powerOfL(10, 13) % 10;
        if (digits == 4)
        {
            printf("VISA\n");
            return true;
        }
    }
    return false;
}

// Calulates exponent of a value returned as a long
long powerOfL(int base, int exponent)
{
    long result = base;
    for (int i = 1; i < exponent; i++)
    {
        result *= base;
    }
    return result;
}
