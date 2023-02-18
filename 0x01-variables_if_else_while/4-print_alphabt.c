#include <stdio.h>

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
