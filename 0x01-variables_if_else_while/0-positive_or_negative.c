#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	int r;

	srand(time(0));
	r = rand() - RAND_MAX / 2;

	if (r > 0)
		printf("%i is positive\n", n);
	else if (r < 0)
		printf("%i is negative\n", n);
	else
		printf("%i is zero\n", n);

	return (0);
}

