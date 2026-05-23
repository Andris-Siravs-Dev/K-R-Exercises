/**
 * @file invert.c
 * @brief Bit inversion utility for toggling flags in embedded systems.
 */

#include <stdio.h>

/**
 * @brief Inverts (toggles) 'n' bits of 'x' starting at bit position 'p'.
 *
 * This function applies a bitwise XOR operation using a generated mask.
 * The bits starting at position 'p' and moving 'n' positions to the right
 * are inverted (0 becomes 1, and 1 becomes 0). All other bits remain unchanged.
 *
 * @param x The original base value.
 * @param p The starting bit position (0-indexed from the right).
 * @param n The number of bits to invert.
 * @return int The modified value of x after bit inversion.
 */
int invert(int x, int p, int n);

int main()
{
        // Test case: x = 150 (10010110)
        // Invert 3 bits starting at position 4 (bits 4, 3, and 2)
        // Expected binary change: 100[101]10 -> 100[010]10 (which is 138)
        int neuer_wert = invert(150, 4, 3);

        printf("Resultat (Dezimal): %i\n", neuer_wert);
        printf("Resultat (Hexadezimal): 0x%X\n", neuer_wert);

        return 0;
}

int invert(int x, int p, int n)
{
        /* Create n ones and shift them to line up with position p */
        unsigned int mask = ~(~0 << n) << (p + 1 - n);
        
        /* XOR toggles exactly the bits where the mask has a '1' */
        return (x ^ mask);
}
