#include <stdio.h>

/**
 * main - main block
 * Description: Use `putchar` to print all letters but the letter 'q' and 'e'.
 * Return: 0
 */

int main(void)
{
	char m = 'a';

	while (m <= 'z')
	{
		if (m != 'q' && m != 'e')
			putchar(m);
		m++;
	}
	putchar('\n');

	return (0);
}
