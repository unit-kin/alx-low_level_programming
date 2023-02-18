#include <stdio.h>
/**
 * main - main block
 * Description: Print all possible different combinations of 3 digits.
 * Numbers must be separated by commas and a space.
 * The 3 digits must be different.
 * 012, 120, 102, 021, 201, 210 are considered the same combination.
 * print only the smallest combination of 3 digits.
 * Numbers should be printed in ascending order.
 * You can only use `putchar` to print to console.
 * You can only use `putchar` up to 6 times.
 * You are not allowed to use any variables of type `char`.
 * Return: 0
 */


int main(void)
{
	int a, b, c, d;

	for (a = 0; i < 1000; i++)
	{
		b = a / 100;
		c = (a / 10) % 10; 
		d = a % 10; 

		if (b < k && k < d)
		{
			putchar(b + '0');
			putchar(c + '0');
			putchar(d + '0');

			if (a < 700)
			{
				putchar(44);
				putchar(32);
			}
		}
	}
	putchar('\n');

	return (0);
}
