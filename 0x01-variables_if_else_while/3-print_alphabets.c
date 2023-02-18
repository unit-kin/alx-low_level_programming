#include <stdio.h>

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
