#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * check_match - Vérifie si un bloc de mots correspond à l'index actuel
 * @s: Le sous-segment de la chaîne principale à analyser
 * @words: Le tableau de mots
 * @nb_words: Le nombre total de mots
 * @w_len: La longueur de chaque mot
 * @found: Tableau temporaire pour cocher les mots trouvés
 *
 * Return: 1 si tous les mots correspondent, 0 sinon
 */
int check_match(char const *s, char const **words,
		int nb_words, int w_len, int *found)
{
	int j, k, matched;

	for (j = 0; j < nb_words; j++)
		found[j] = 0;

	for (k = 0; k < nb_words; k++)
	{
		matched = 0;
		for (j = 0; j < nb_words; j++)
		{
			if (found[j] == 0 &&
			    strncmp(s + (k * w_len), words[j], w_len) == 0)
			{
				found[j] = 1;
				matched = 1;
				break;
			}
		}
		if (!matched)
			return (0);
	}
	return (1);
}

/**
 * find_substring - Trouve tous les index de départ des sous-chaînes valides
 * @s: La chaîne principale à analyser
 * @words: Le tableau contenant les mots à chercher
 * @nb_words: Le nombre de mots dans le tableau 'words'
 * @n: Pointeur pour stocker la taille du tableau retourné
 *
 * Return: Un tableau alloué dynamiquement avec les index, ou NULL
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int i, w_len, len_s;
	int *indices, *found;

	*n = 0;
	if (!s || !words || nb_words == 0)
		return (NULL);
	len_s = strlen(s);
	w_len = strlen(words[0]);
	if (len_s < nb_words * w_len)
		return (NULL);
	indices = malloc(len_s * sizeof(int));
	if (!indices)
		return (NULL);
	found = malloc(nb_words * sizeof(int));
	if (!found)
	{
		free(indices);
		return (NULL);
	}
	for (i = 0; i <= len_s - (nb_words * w_len); i++)
	{
		if (check_match(s + i, words, nb_words, w_len, found))
		{
			indices[*n] = i;
			(*n)++;
		}
	}
	free(found);
	if (*n == 0)
	{
		free(indices);
		return (NULL);
	}
	return (indices);
}
