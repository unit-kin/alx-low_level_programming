#include <stdio.h>

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
