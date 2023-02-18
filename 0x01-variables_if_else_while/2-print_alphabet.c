#include <stdio.h>
/**
 * main - main block
 * Description: Use `putchar` function to print the alphabet in lowercase.
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
	putchar('\n');

	return (0);
}
