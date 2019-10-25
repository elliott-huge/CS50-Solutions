#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool validInput(int count, string input[]);
bool isChar(char chr);
char intToChar(int i);
int charToInt(char c);
string intArrToString(int arr[], int n);
void applyCipher(int n, string inputText, string key, int keyLength);
bool isCapital(int c);
int shiftDist(char c);

string OUTPUTTEXT;

int main(int argc, string argv[])
{
    string KEY;
    int KEYLENGTH;
    string PLAINTEXT;
    int PLAINLENGTH;
    
    if (!validInput(argc, argv))
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    // Globals retaining keyword and its' length
    KEY = argv[argc - 1];
    KEYLENGTH = strlen(KEY);
    
    PLAINTEXT = get_string("plaintext: ");
    PLAINLENGTH = strlen(PLAINTEXT);
    
    applyCipher(PLAINLENGTH, PLAINTEXT, KEY, KEYLENGTH);
    
    
}


bool validInput(int count, string input[])
{
    // Test for too many user inputs
    if (count != 2)
    {
        return false;
    }
    
    // Check keyword is valid
    else
    {
        string userStr = input[count - 1];
        int n = strlen(userStr);
        // Check each character is valid
        for (int i = 0; i < n; i++)
        {
            if (!isChar(userStr[i]))
            {
                return false;
            }
        }
    }
    return true;
}

// Test if input byte is valid character
bool isChar(char chr)
{
    if ((charToInt(chr) >= 65 && charToInt(chr) <= 90) || (charToInt(chr) >= 97 && charToInt(chr) <= 122))
    {
        return true;
    }
    return false;
}

// Conversion from char to Int
int charToInt(char c)
{
    return (int) c;
}
// Conversion from Int to Char
char intToChar(int i)
{
    return (char) i;
}


void applyCipher(int n, string inputText, string key, int keyLength)
{
    
    // Mark end of string in charArray using null char
    char cArray[n + 1];
    cArray[n] = '\0';
    
    // Temp to store current shifting value
    int temp;
    
    // Indexer variable maintains Key index, necessary for skipping non-alphabetic chars
    int indexer = 0;
    
    // Loop to iterate through entire plaintext string
    for (int i = 0; i < n; i++)
    {
        if (isChar(inputText[i]))
        {
            temp = charToInt(inputText[i]);
            if (isCapital(temp))
            {
                // Adjusts for wrapping, specific to capitalised chars
                temp +=  shiftDist(key[indexer % keyLength]);
                if (temp > 90)
                {
                    temp -= 65;
                    temp = temp % 26;
                    temp += 65;
                }
                cArray[i] = intToChar(temp);
            }
            else
            {
                // Adjusts for wrapping, specific to lower case chars
                temp +=  shiftDist(key[indexer % keyLength]);
                if (temp > 122)
                {
                    temp -= 97;
                    temp = temp % 26;
                    temp += 97;
                }
                cArray[i] = intToChar(temp);
            }
            indexer++;
        }
        else
        {
            cArray[i] = inputText[i];
        }
    }
    OUTPUTTEXT = cArray;
    printf("ciphertext: %s\n", cArray);
}

// Checks if char represented as int is uppercase
bool isCapital(int c)
{
    if (c >= 65 && c <= 90)
    {
        return true;
    }
    return false;
}

// Calculates the shift distance represented by a char
int shiftDist(char c)
{
    int shift = charToInt(c);
    if (isCapital(shift))
    {
        shift -= 65;
        return shift;
    }
    shift -= 97;
    return shift;
}
