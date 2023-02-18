#include <stdio.h>

/**
 * main - main block
 * Description: Use `putchar` to print lowercase and then uppercase alphabet.
 * Return: 0
 */

int main(void)
{
	char m = 'a';

	while (m <= 'z')
	{
		putchar(m);
		m++;
	}

	m = 'A';

	while (m <= 'Z')
	{
		putchar(m);
		m++;
	}

	putchar('\n');

	return (0);
}
