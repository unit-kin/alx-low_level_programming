#include "main.h"

/**
 * wildcmp - compare two strings with "wildcard expansion" capabilities
 * @s1: string 1
 * @s2: string 2
 * Return: 1 if strings can be considered identical. else 0.
 */

int wildcmp(char *s1, char *s2)
{
	// If both strings are empty, they are considered identical
	if (*s1 == '\0' && *s2 == '\0') {
		return 1;
	}

	// If the current characters match, compare the next characters
	if (*s1 == *s2) {
		return wildcmp(s1 + 1, s2 + 1);
	}

	// If s2 contains a '*', recursively compare the substrings after the '*'
	if (*s2 == '*') {
		// Check if the '*' represents an empty string
		if (wildcmp(s1, s2 + 1)) {
			return 1;
		}
		// Otherwise, recursively compare all possible substrings after the '*'
		while (*s1 != '\0') {
			if (wildcmp(s1 + 1, s2)) {
				return 1;
			}
			s1++;
		}
	}

	// If none of the above conditions are true, the strings are not identical
	return 0;
}

