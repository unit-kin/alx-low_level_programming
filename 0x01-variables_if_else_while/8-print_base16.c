#include <stdio.h>

/**
 * main - main block
 * Description: Print all numbers of base64 in lowercase.
 * You can only use `putchar`, and only 3 times.
 * Return: 0
 */

int main(void)
{
	int x;
	char c;
	

	for (x = 0; x< 10; x++)
	{
		putchar(x + '0');
	}
	for (c = 'a'; c < 'g'; c++)
	{
		putchar(c);
	}
	putchar('\n');

	return (0);
}
