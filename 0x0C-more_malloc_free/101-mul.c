#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * is_digit - Check if a string is a digit
 *
 * @s: String to check
 *
 * Return: 1 if the string is a digit, 0 otherwise
 */
int is_digit(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}

	return (1);
}

/**
 * mul - Multiply two numbers
 *
 * @num1: First number to multiply
 * @num2: Second number to multiply
 *
 * Return: The result of the multiplication
 */
char *mul(char *num1, char *num2)
{
	int len1 = 0, len2 = 0, i, j, k, carry = 0, n1, n2, sum;
	char *result;

	/* Get the length of each number */
	while (num1[len1] != '\0')
		len1++;
	while (num2[len2] != '\0')
		len2++;

	/* Allocate memory for the result */
	result = malloc(sizeof(char) * (len1 + len2 + 1));
	if (result == NULL)
		return (NULL);

	/* Initialize the result */
	for (i = 0; i < len1 + len2; i++)
		result[i] = '0';
	result[len1 + len2] = '\0';

	/* Multiply each digit of num2 with num1 */
	for (i = len2 - 1; i >= 0; i--)
	{
		carry = 0;
		n2 = num2[i] - '0';

		/* Multiply each digit of num1 with the current digit of num2 */
		for (j = len1 - 1, k = len1 + i; j >= 0; j--, k--)
		{
			n1 = num1[j] - '0';
			sum = n1 * n2 + carry + (result[k] - '0');
			carry = sum / 10;
			result[k] = (sum % 10) + '0';
		}

		/* Add the carry to the remaining digits in the result */
		if (carry > 0)
		{
			sum = carry + (result[k] - '0');
			carry = sum / 10;
			result[k] = (sum % 10) + '0';
			k--;
		}
	}

	/* Remove leading zeros */
	for (i = 0; result[i] == '0' && result[i + 1] != '\0'; i++)
		;
	if (i > 0)
	{
		for (j = i; j <= len1 + len2; j++)
			result[j - i] = result[j];
	}

	return (result);
}

/**
 * main - Entry point
 *
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
	char *num1, *num2, *result;

	/* Check the number of arguments */
	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	/* Check if the arguments are digits */
	num1 = argv[1];
	num2 = argv[2];
	if (!is_digit(num1

