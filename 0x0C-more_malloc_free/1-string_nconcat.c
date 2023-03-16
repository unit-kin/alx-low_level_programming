#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * string_nconcat - concatenates two strings, up to n bytes from s2
 * @s1: first string
 * @s2: second string
 * @n: number of bytes to concatenate from s2
 *
 * Return: pointer to newly allocated space containing s1 followed by
 * the first n bytes of s2, null terminated, or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *new_str;
	unsigned int s1_len = 0, s2_len = 0, i, j;

	if (s1 != NULL)
		s1_len = _strlen(s1);
	if (s2 != NULL)
		s2_len = _strlen(s2);

	if (n >= s2_len)
		n = s2_len;

	new_str = malloc(s1_len + n + 1);
	if (new_str == NULL)
		return (NULL);

	for (i = 0; i < s1_len; i++)
		new_str[i] = s1[i];

	for (j = 0; j < n; j++)
		new_str[i + j] = s2[j];

	new_str[i + j] = '\0';

	return (new_str);
}

