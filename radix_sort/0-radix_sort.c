#include "sort.h"
#include <stdlib.h>


/**
 * get_max - A utility function to get maximum value in array[]
 * @array: The array
 * @size: size of the array
 * Return: maximum integer
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * count_sort - A function to do counting sort of array[] according to
 * the digit represented by exp.
 * @array: The array
 * @size: size of the array
 * @exp: exp is 10^i (unit, ten, hundred...)
 * @output: temporary array to store sorted elements
 */
void counting_sort(int *array, size_t size, int exp, int *output)
{
	int i, count[10] = {0};

	for (i = 0; i < (int)size; i++)
		count[(array[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = (int)size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 * using the Radix sort algorithm (LSD).
 * @array: The array to sort
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;
	int *output;

	if (!array || size < 2)
		return;
	output = malloc(sizeof(int) * size);
	if (!output)
		return;
	max = get_max(array, size);
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort(array, size, exp, output);
		print_array(array, size);
	}
	free(output);
}
