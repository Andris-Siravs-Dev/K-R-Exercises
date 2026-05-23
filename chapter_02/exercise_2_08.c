/**
 * @file rightrot.c
 * @brief Bit rotation utility for circular bit-shifting in embedded systems.
 */

#include <stdio.h>

/** @brief Number of bits in a standard integer on a 32-bit architecture. */
#define SIZE 32

/**
 * @brief Rotates the bits of an unsigned integer to the right.
 *
 * This function performs a circular right shift by 'n' positions. Bits that 
 * fall off the right side (least significant bit) are wrapped around and 
 * reinserted on the left side (most significant bit).
 *
 * @param x The original 32-bit unsigned value to rotate.
 * @param n The number of positions to rotate by.
 * @return unsigned int The rotated value.
 */
unsigned int rightrot(unsigned int x, int n);

int main()
{
        // Test case: x = 1000, rotated right by 3 positions
        int value = rightrot(1000, 3);
        printf("Resultat: %i\n", value); 
        
        return 0;
}

unsigned int rightrot(unsigned int x, int n)
{
	/*
	* 1. (x >> n) shifts the main body to the right.
        * 2. (x << (SIZE - n)) catapults the wrapped bits instantly to the far left.
        * 3. The bitwise OR (|) merges both halves instantly.
        */
        return ((x >> n) | (x << (SIZE-n)));
}

