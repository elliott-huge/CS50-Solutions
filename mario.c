#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h = 0;
    while (h <= 0 || h > 8)
    {
        h = get_int("Height: ");
    }
    
    // 2D loop of height then depth
    for (int i = h; i > 0; i--)
    {
        // Print left
        for (int j = 1; j <= h; j++)
        {
            if (j >= i)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        // Print gap
        printf("  ");
        
        // Print right
        for (int a = h; a > 0; a--)
        {
            if (a >= i)
            {
                printf("#");
            }
        }
        
        printf("\n");
    }
}
