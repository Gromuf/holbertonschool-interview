#include "holberton.h"

/**
 * wildcmp - Compare deux chaînes de caractères avec prise en charge de '*'
 * @s1: La première chaîne de caractères
 * @s2: La deuxième chaîne pouvant contenir le caractère spécial '*'
 *
 * Return: 1 si les chaînes peuvent être considérées identiques, 0 sinon
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	if (*s2 == '*')
	{
		if (*s1 == '\0')
			return (wildcmp(s1, s2 + 1));
		return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
	}
	return (0);
}