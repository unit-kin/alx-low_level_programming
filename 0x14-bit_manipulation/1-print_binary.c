#include "main.h"
#include <stdio.h>

/**
 * print_binary - print binary representation of a number
 * @n: decimal number to print as binary
 */
void print_binary(unsigned long int n)
{
	unsigned long int temp = n;
	int shifts = 0;

	if (n == 0)
	{
		printf("0");
		return;
	}

	while ((temp >>= 1) > 0)
		shifts++;

	while (shifts >= 0)
	{
		if ((n >> shifts) & 1)
			printf("1");
		else
			printf("0");

		shifts--;
	}
}
