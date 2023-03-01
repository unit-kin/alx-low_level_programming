#include "main.h"

/**
 * leet - encode a string into 1337
 * @s: string
 * Return: encoded string `s`
 */

char *leet(char *s) {
    int i, j;
    char leet_letters[] = {'4', '3', '0', '7', '1'};
    char normal_letters[] = {'a', 'e', 'o', 't', 'l'};

    for (i = 0; s[i] != '\0'; i++) {
        for (j = 0; j < 5; j++) {
            if (s[i] == normal_letters[j] || s[i] == normal_letters[j] - 'a' + 'A') {
		    s[i] = leet_letters[j];
		    break;
	    }
	}
    }

    return s;
}

