/**
 * @file main.c
 * @brief Bit manipulation utility for embedded systems and sensor data parsing.
 */

#include <stdio.h>

/**
 * @brief Replaces a specific bit range in x with the lowest bits of y.
 *
 * This function takes 'n' bits from the rightmost position of 'y' and inserts
 * them into 'x', starting at bit position 'p' (moving towards the right).
 * All other bits in 'x' remain unchanged.
 *
 * @param x The original base value.
 * @param p The starting bit position (0-indexed from the right).
 * @param n The number of bits to replace.
 * @param y The value containing the source bits at its lowest positions.
 * @return int The modified value of x after bit replacement.
 */
int setbits(int x, int p, int n, int y);

int main()
{
        // Test case: x = 150 (10010110), y = 3 (00000011)
        // Replace 2 bits starting at position 5 (bits 5 and 4)
        int neuer_wert = setbits(150, 5, 2, 3);
        
        printf("Resultat (Dezimal): %i\n", neuer_wert);
        printf("Resultat (Hexadezimal): 0x%X\n", neuer_wert);

        return 0;
}

int setbits(int x, int p, int n, int y)
{
        /* Create a mask with 'n' trailing ones (e.g., n=3 -> 00000111) */
        unsigned int brink = ~(~0 << n); 
        
        /* Shift the mask to line up with the target position 'p' (e.g., 00011100) */
        unsigned int mask =  brink << (p + 1 - n); 

        /* 
         * 1. (x & ~mask) clears the target bits in x, creating a "hole"
         * 2. (y & brink) isolates the n lowest bits of y
         * 3. << (p + 1 - n) moves the isolated y-bits to the target position
         * 4. The bitwise OR (|) merges the prepared y-bits into x's hole
         */
        return ((x & ~mask) | ((y & brink) << (p + 1 - n))); 
}
