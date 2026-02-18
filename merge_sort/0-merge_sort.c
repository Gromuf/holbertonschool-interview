#include "sort.h"

/*
 * merge_sort - Sorts an array of integers in ascending order using the
 *               Merge Sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	size_t mid = size / 2;
	int *left = malloc(mid * sizeof(int));
	int *right = malloc((size - mid) * sizeof(int));

	if (left == NULL || right == NULL)
	{
		free(left);
		free(right);
		return;
	}

	for (size_t i = 0; i < mid; i++)
		left[i] = array[i];
	for (size_t i = mid; i < size; i++)
		right[i - mid] = array[i];

	merge_sort(left, mid);
	merge_sort(right, size - mid);

	size_t i = 0, j = 0, k = 0;
	while (i < mid && j < size - mid)
	{
		if (left[i] <= right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}
	while (i < mid)
		array[k++] = left[i++];
	while (j < size - mid)
		array[k++] = right[j++];

	free(left);
	free(right);
}
