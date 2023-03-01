#include <stdio.h>
/**
 * infinite_add - Add up two numbers stored in given char arrays
 * @n1: The first number
 * @n2: The second number
 * @r: Pointer to the buffer to store result
 * @size_r: The size of the buffer
 *
 * Return: 0 if buffer too small to store result, else return pointer to buffer
 */

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = strlen(n1);
	int len2 = strlen(n2);
	int carry = 0;
	int i, j;

	// Check if result fits in buffer
	if (len1 + len2 + 1 > size_r)
	{
		return 0;
	}

	// Add digits from right to left
	for (i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0 || carry; i--, j--)
	{
		int sum = carry;
		if (i >= 0)
		{
			sum += n1[i] - '0';
		}
		if (j >= 0)
		{
			sum += n2[j] - '0';
		}
		if (sum >= 10)
		{
			carry = 1;
			sum -= 10;
		} else
		{
			carry = 0;
		}
		r[len1 + len2 - i - j - 2] = sum + '0';
	}

	// Null-terminate result string
	r[len1 + len2 - i - j - 1] = '\0';

	// Reverse result string in place
	for (i = 0, j = strlen(r) - 1; i < j; i++, j--)
	{
		char tmp = r[i];
		r[i] = r[j];
		r[j] = tmp;
	}

	return (r);
}

