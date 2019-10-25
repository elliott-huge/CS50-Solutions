#include <cs50.h>
#include <stdio.h>
#include <crypt.h>
#include <string.h>

char intToChar(int i);
char AlphaCharGen(int value);
void PassGen();
string cropString(string s, int l);

int main(int argc, string argv[])
{
    // Check inputs are valid
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    else if (strlen(argv[1]) != 13)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    
    // Main program
    PassGen(argv[1]);
}

void PassGen(string hash)
{
    // Preamble
    char testString[6] = {' ', ' ', ' ', ' ', ' ', '\0'};
    
    string salt;
    char arr[3] = {' ', ' ', '\0'};
    for (int i = 0; i < 2; i++)
    {
        arr[i] = hash[i];
    }
    salt = arr;
        
    // Main loop
    for (int i = 0; i < 53; i++)
    {
        for (int j = 0; j < 53; j++)
        {
            for (int k = 0; k < 53; k++)
            {
                for (int l = 0; l < 53; l++)
                {
                    for (int m = 1; m < 53; m++)
                    {
                        testString[4] = AlphaCharGen(m);
                        // Meat of code goes here
                        string artiHash = crypt(cropString(testString, 5), salt);
                        if (strncmp(artiHash, hash, 13) == 0)
                        {
                            printf("%s\n", cropString(testString, 5));
                            return;
                        }
                    }
                    testString[3] = AlphaCharGen(l);
                }
                testString[2] = AlphaCharGen(k);
            }
            testString[1] = AlphaCharGen(j);
        }
        testString[0] = AlphaCharGen(i);
    }
}



// Takes a range of 1-56, NOT 0
char AlphaCharGen(int value)
{
    if (value == 0)
    {
        value = 32;
    }
    else if (value >= 1 && value <= 26)
    {
        value += 64;
    }
    else
    {
        value += 70;
    }
    char a = intToChar(value);
    return a;
    // Value is 0: char is null
    // Value is 1-26: char is in bound 65-90 (caps)
    // Value is 27-52: char is in bound 97-122 (lower-case)
    // NB: point of macro design... loop around to 1, instead of 0, when value hits 53
}

char intToChar(int i)
{
    return (char) i;
}

string cropString(string s, int l)
{
    int count = l;
    for (int i = 0; i < l; i++)
    {
        if (s[i] == ' ')
        {
            count--;
        }
    }
    
    char charOut[count + 1];
    charOut[count] = '\0';
    
    int placeHolder = 0;
    for (int i = 0; i < l; i++)
    {
        if (s[i] != ' ')
        {
            charOut[placeHolder] = s[i];
            placeHolder++;
        }
    }
    string out = charOut;
    return out;
}
