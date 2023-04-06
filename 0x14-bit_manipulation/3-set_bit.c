#include "main.h"

/**
 * set_bit - Sets the value of a bit at a given index to 1
 * @n: Pointer to the decimal number to modify
 * @index: Index of the bit to modify, starting from 0
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
        unsigned long int p;

        if (index > 63) /* The maximum index value for an unsigned long int is 63 */
                return (-1);

        for (p = 1; index > 0; index--, p *= 2)
                ;

        *n += p;

        return (1);
}
