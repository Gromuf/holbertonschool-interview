#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * merge_sub - Fusionne deux sous-tableaux.
 * @array: Le tableau d'origine.
 * @buff: Le tableau de travail (temp).
 * @start: Index de début.
 * @mid: Index du milieu.
 * @end: Index de fin.
 */
void merge_sub(int *array, int *buff, size_t start, size_t mid, size_t end)
{
	size_t i = start, j = mid, k = 0;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, end - mid);
	while (i < mid && j < end)
		buff[k++] = (array[i] < array[j]) ? array[i++] : array[j++];
	while (i < mid)
		buff[k++] = array[i++];
	while (j < end)
		buff[k++] = array[j++];
	for (i = start, k = 0; i < end; i++)
		array[i] = buff[k++];
	printf("[done]: ");
	print_array(array + start, end - start);
}

/**
 * sort_recursive - Divise récursivement le tableau.
 * @array: Le tableau à trier.
 * @buff: Le tableau de travail.
 * @start: Début du segment.
 * @end: Fin du segment.
 */
void sort_recursive(int *array, int *buff, size_t start, size_t end)
{
	size_t mid;
	if (end - start < 2)
		return;
	mid = start + (end - start) / 2;
	sort_recursive(array, buff, start, mid);
	sort_recursive(array, buff, mid, end);
	merge_sub(array, buff, start, mid, end);
}

/**
 * merge_sort - Lance le tri fusion (Top-down).
 * @array: Le tableau d'entiers.
 * @size: La taille du tableau.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;
	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;
	sort_recursive(array, buff, 0, size);
	free(buff);
}
