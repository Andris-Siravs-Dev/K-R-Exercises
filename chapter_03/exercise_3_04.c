#include <stdio.h>
#include <string.h>

#define MAX 100

void reverse(char s[]);
void itoa(int n, char s[]);

int main(void)
{
        char s[MAX];

        // Test with the minimum negative value for an 8-bit representation
        itoa(-128, s);
        printf("%s\n", s);
        
        return 0;
}

/**
 * @brief Converts an integer into an ASCII string.
 *
 * This architecture-independent implementation correctly handles the largest 
 * negative integer in two's complement representation (-(2^(word_size-1))). 
 * It processes the digits natively in the negative domain to prevent arithmetic 
 * overflow caused by standard negation (n = -n).
 *
 * @param n The integer value to be converted.
 * @param s The destination character array where the string will be stored.
 */
void itoa(int n, char s[])
{
        int i, sign;

        // Save the original value to determine the sign later
        sign = n;

        i = 0;
        do {
                // In C, modulo of a negative number yields a negative result
                int digit = n % 10;
                
                // Invert the single digit to make it positive for ASCII conversion
                if (digit < 0)
                {
                        digit = -digit;
                }
                
                // Convert the digit to its ASCII character representation
                s[i++] = digit + '0';

        // Using '!= 0' ensures negative numbers are fully processed 
        // until they reach zero, preventing premature loop termination
        } while ((n /= 10) != 0);

        // Append the minus sign if the original number was negative
        if (sign < 0)
                s[i++] = '-';

        // Terminate the string properly
        s[i] = '\0';
        
        // Reverse the string since digits were extracted in reverse order
        reverse(s);
}

/**
 * @brief Reverses a string in-place.
 *
 * Uses a two-pointer approach moving from the boundaries towards the center 
 * to swap characters.
 *
 * @param s The null-terminated string to be reversed.
 */
void reverse(char s[])
{
        int c, i, j;

        for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
        {
                c = s[i];
                s[i] = s[j];
                s[j] = c;
        }
}
