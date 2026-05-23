/**
 * @file main.c
 * @brief A program to expand shorthand notations like 'a-z' or '0-9' from input into complete sequences.
 * 
 * This implementation reads lines from standard input and processes shorthand character 
 * ranges into their full literal representations using an optimized buffer approach.
 */

#include <stdio.h>

/**
 * @brief Maximum buffer size for input and output strings.
 */
#define MAX 2000

/* Function Prototypes */
int get_line(char s[]);
void expand(char s1[], char s2[]);

/**
 * @brief Application entry point.
 * 
 * Continuously reads lines from standard input, processes any shorthand notations,
 * and prints the expanded results until End-Of-File (EOF) or an empty line is reached.
 * 
 * @return int Returns 0 upon successful execution.
 */
int main(void)
{
        char s1[MAX], s2[MAX];
        int len;

        while ((len = get_line(s1)) != 0)
        {
                expand(s1, s2);
                printf("Result:  %s\n", s2);
        }
        return 0;
}

/**
 * @brief Reads a line from standard input into a character array.
 * 
 * Reads characters until a newline character or EOF is encountered, or until the
 * buffer limit is reached. Appends a newline and a null-terminator at the end.
 * 
 * @param s1 The character array where the input line will be stored.
 * @return int The total length of the string written into the buffer.
 */
int get_line(char s1[])
{
        int i, c;

        for (i = 0; i < MAX && (c = getchar()) != EOF && c != '\n'; i++)
        {
                s1[i] = c;
        }

        if (c == '\n')
        {
                s1[i++] = c;
        }

        s1[i] = '\0';
        return i;
}

/**
 * @brief Expands shorthand notations like 'a-z' into complete sequences.
 * 
 * Iterates through the source string. When a valid range pattern (e.g., 'a-z', '0-9')
 * is detected, it fills the target string with the intermediate characters sequentially.
 * Non-shorthand characters are copied as-is.
 * 
 * @param s1 The source character array containing the raw shorthand input string.
 * @param s2 The target character array where the fully expanded string will be stored.
 */
void expand(char s1[], char s2[])
{
        int i, j, c;
        i = j = 0;

        /* Process the source string until the null-terminator is reached */
        while (s1[i] != '\0')
        {
                /* Check for a valid shorthand notation pattern (e.g., 'a-z') */
                if (i > 0 && s1[i] == '-' && s1[i+1] != '\0' && s1[i-1] < s1[i+1])
                {
                        /* Fill s2 with the missing characters between the range boundaries */
                        for (c = s1[i-1] + 1; c <= s1[i+1]; c++)
                        {
                                s2[j++] = c;
                        }
                        
                        /* Advance past the upper limit character since it has been processed */
                        i++;
                }
                else
                {
                        /* Direct copy for standard characters, advancing both indices */
                        s2[j++] = s1[i++];
                }
        }
        
        /* Explicitly null-terminate the destination string */
        s2[j] = '\0';
}
