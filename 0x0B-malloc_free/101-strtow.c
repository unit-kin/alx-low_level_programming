#include "main.h"
#include <stdlib.h>

/**
 * count_words - Counts the number of words in a string.
 * @str: The string to be counted.
 *
 * Return: The number of words in @str.
 */
static int count_words(char *str)
{
	int words = 0, i = 0;

	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i])
			words++;
		while (str[i] && str[i] != ' ')
			i++;
	}

	return (words);
}

/**
 * strtow - Splits a string into words.
 * @str: The string to be split.
 *
 * Return: If str is NULL or fails - NULL.
 *         Otherwise - a pointer to an array of strings (words).
 */
char **strtow(char *str)
{
	char **words;
	int i, j, k, len, wc;

	if (str == NULL || *str == '\0')
		return (NULL);

	wc = count_words(str);
	if (wc == 0)
		return (NULL);

	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	for (i = 0, j = 0; i < wc; i++)
	{
		while (str[j] && str[j] == ' ')
			j++;
		len = 0;
		while (str[j + len] && str[j + len] != ' ')
			len++;
		words[i] = malloc((len + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			for (k = 0; k < i; k++)
				free(words[k]);
			free(words);
			return (NULL);
		}
		for (k = 0; k < len; k++)
			words[i][k] = str[j + k];
		words[i][len] = '\0';
		j += len;
	}

	words[i] = NULL;
	return (words);
}

