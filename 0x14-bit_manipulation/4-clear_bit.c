#include "main.h"
#include <stdio.h>

/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * @n: pointer to decimal number to change
 * @index: index position to change
 *
 * Return: 1 if it worked, -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
        unsigned long int i;
        unsigned int hold;

        if (index > 63) /* index must be less than 64 */
                return (-1);

        hold = index;
        while (hold > 0)
        {
                i = 1UL << hold;
                *n &= ~i;
                hold--;
        }

        i = 1UL << index;
        if ((*n & i) != 0) /* check if bit at index is set */
                *n ^= i; /* unset bit at index */

        return (1);
}
