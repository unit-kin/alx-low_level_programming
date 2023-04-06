#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @binary: pointer to a string of 0 and 1 characters
 *
 * Return: converted decimal number or 0 if there is an unconvertible character
 */
unsigned int binary_to_uint(const char *binary)
{
	unsigned int total = 0, power = 1;
	int index;

	if (binary == NULL)
		return (0);

	for (index = 0; binary[index]; index++)
	{
		if (binary[index] != '0' && binary[index] != '1')
			return (0);
	}

	for (index--; index >= 0; index--, power *= 2)
	{
		if (binary[index] == '1')
			total += power;
	}

	return (total);
}

