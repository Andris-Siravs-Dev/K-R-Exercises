/**
 * @file main.c
 * @brief Utility for converting integers to arbitrary base strings.
 * @details Implements a robust radix conversion algorithm supporting 
 * bases from 2 up to 36, handling both positive and negative integers.
 */

#include <stdio.h>
#include <string.h>

/** @brief Maximum buffer size for the output string. */
#define MAX 100

void reverse(char s[]);
void itob(int n, char s[], int b);

/**
 * @brief Application entry point.
 * @return Execution status (0 for success).
 */
int main(void)
{
        char s[MAX];
        itob(122, s, 2);
        printf("%s\n", s);
        return 0;
}

/**
 * @brief Converts an integer into a base-N string representation.
 * @details Extracts digits using modulo operations and translates values
 * >= 10 into lowercase alphabetic characters ('a'-'z'). Handles negative numbers.
 * 
 * @param n The integer value to convert.
 * @param s The target character array to store the resulting string.
 * @param b The radix/base for conversion (e.g., 2 for binary, 16 for hex).
 */
void itob(int n, char s[], int b)
{
        int i = 0;
        int sign = n; // Store original value to preserve sign status
        
        // Convert to absolute value for uniform processing
        if (n < 0)
                n = -n;

        // Extract digits sequentially from least to most significant
        do {
                char c = n % b;
                if (b > 10 && c >= 10)
                {
                        s[i++] = 'a' + c - 10; // Map values 10-35 to 'a'-'z'
                }
                else
                {
                        s[i++] = c + '0';      // Map values 0-9 to ASCII digits
                }
                n /= b;

        } while (n > 0 && i < MAX - 1); // Prevent buffer overflow, leave space for '\0'

        // Re-apply negative sign if required
        if (sign < 0)
                s[i++] = '-';

        s[i] = '\0'; // Terminate string
        reverse(s);  // Restore correct positional order
}

/**
 * @brief Reverses a null-terminated string in-place.
 * @param s The character array to be reversed.
 */
void reverse(char s[])
{
        int c, i, j;

        // Two-pointer swap strategy moving towards the center
        for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
        {
                c = s[i];
                s[i] = s[j];
                s[j] = c;
        }
}
