#include <stdio.h>
#include "search_algos.h"

/**
 * print_array - prints an array of integers
 * @array: array to print
 * @left: starting index
 * @right: ending index
 */
static void print_array(int *array, size_t left, size_t right)
{
	size_t i;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		if (i > left)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * advanced_binary_recursive - recursive binary search
 * @array: array to search
 * @left: left index
 * @right: right index
 * @value: value to find
 * 
 * Return: index of first occurence or -1
 */
static int advanced_binary_recursive(int *array, size_t left,
	size_t right, int value)
{
	size_t mid;

	if (right < left)
		return (-1);
	print_array(array, left, right);
	mid = left + (right - left) / 2;
	if (array[mid] == value)
	{
		if (mid == left || array[mid - 1] != value)
			return (mid);
		return (advanced_binary_recursive(array, left, mid, value));
	}
	if (array[mid] < value)
		return (advanced_binary_recursive(array, mid + 1, right, value));
	return (advanced_binary_recursive(array, left, mid - 1, value));
}

/**
 * advanced_binary - searches for a value in a sorted array
 * @array: pointer to the first element
 * @size: number of elements
 * @value: value to search for
 *
 * Return: index of first occurrence or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);
	return (advanced_binary_recursive(array, 0, size - 1, value));
}
