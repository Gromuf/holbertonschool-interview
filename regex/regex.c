#include "regex.h"

/**
 * regex_match - Vérifie si une expression régulière
 * @str: La chaîne à analyser
 * @pattern: L'expression régulière (peut contenir '.' et '*')
 *
 * Return: 1 si le motif correspond à la chaîne, 0 sinon
 */
int regex_match(char const *str, char const *pattern)
{
	int first_match = 0;

	if (*pattern == '\0')
		return (*str == '\0');
	first_match = (*str != '\0' && (*str == *pattern || *pattern == '.'));
	if (*(pattern + 1) == '*')
	{
		return (regex_match(str, pattern + 2) ||
			(first_match && regex_match(str + 1, pattern)));
	}
	return (first_match && regex_match(str + 1, pattern + 1));
}
