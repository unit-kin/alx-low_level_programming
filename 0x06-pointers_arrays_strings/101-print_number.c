#include "main.h"
#include <stdio.h>
/**
 * print_number - Print an integer using only _putchar
 * @n: integer to print
 */

void print_number(int n)
{
	int divisor = 1;
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	while (n / divisor > 9)
	{
		divisor *= 10;
	}
	while (divisor > 0)
	{
		_putchar('0' + n / divisor);
		n %= divisor;
		divisor /= 10;
	}
}

