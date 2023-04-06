#include "main.h"
#include <stdio.h>

/**
 * flip_bits - flip bits to convert one number to another number
 * @n: This is the first number
 * @m: second number to be converted 
 * Return: number of bits that was needed to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
        unsigned long int diff;
        int counter;

        diff = n ^ m;
        counter = 0;

        for (; diff; counter++)
        {
                diff &= (diff - 1);
        }

        return (counter);
}
