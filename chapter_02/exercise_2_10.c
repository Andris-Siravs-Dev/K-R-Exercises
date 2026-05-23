/**
 * @file main.c
 * @brief A simple command-line utility to convert text lines to lowercase.
 * @author Your Name
 * @date 2026-05-20
 */

#include <stdio.h>

/** 
 * @def MAX
 * @brief Maximum buffer size for a single line of text.
 */
#define MAX 2000

int get_line(char line[]);
void lower(char line[], char l[]);

/**
 * @brief Main execution point. Reads lines from stdin until EOF and prints them in lowercase.
 * @return int Returns 0 upon successful completion.
 */
int main(void)
{
    char l[MAX], line[MAX];

    /* Loop through each line until get_line returns 0 (EOF) */
    while (get_line(line) != 0)
    {
        lower(line, l);
        printf("%s", l); 
    }
    return 0;
}

/**
 * @brief Reads a line from standard input (stdin) into the provided buffer.
 * 
 * @param line Character array where the input line will be stored.
 * @return int The length of the line read, including the newline character if present.
 */
int get_line(char line[])
{
    int c, i;
    
    /* Read characters until EOF, newline, or buffer limit is reached */
    for (i = 0; (c = getchar()) != EOF && c != '\n' && i < MAX - 1; i++)
    {
        line[i] = c;
    }

    /* Preserve the newline character if it was read */
    if (c == '\n')
    {
        line[i++] = c;
    }

    line[i] = '\0'; /* Null-terminate the string */
    return i;
}

/**
 * @brief Converts all uppercase ASCII characters in a string to lowercase.
 * 
 * @param line The original input string.
 * @param l The destination buffer to store the lowercase version.
 */
void lower(char line[], char l[])
{
    int i;
    
    /* Process characters until null-terminator, newline, or buffer limit */
    for (i = 0; line[i] != '\0' && line[i] != '\n' && i < MAX - 1; i++)
    {
        /* Convert to lowercase if character is between 'A' and 'Z' */
        l[i] = (line[i] >= 'A' && line[i] <= 'Z') ? (line[i] - 'A' + 'a') : line[i];
    }
    
    /* Append newline if present in the original line */
    if (line[i] == '\n')
    {
        l[i++] = '\n';
    }
    
    l[i] = '\0'; /* Null-terminate the output string */
}
