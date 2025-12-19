#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: first integer
 * @b: second integer
 */
static void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * sift_down - restores heap property
 * @array: array of integers
 * @size: total size of the array
 * @start: root index
 * @end: last index of the heap
 */
static void sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t root = start;
	size_t child, swap_idx;

	while ((child = 2 * root + 1) <= end)
	{
		swap_idx = root;

		if (array[swap_idx] < array[child])
			swap_idx = child;
		if (child + 1 <= end && array[swap_idx] < array[child + 1])
			swap_idx = child + 1;
		if (swap_idx == root)
			return;
		swap(&array[root], &array[swap_idx]);
		print_array(array, size);
		root = swap_idx;
	}
}

/**
 * heap_sort - sorts an array using heap sort
 * @array: array of integers
 * @size: number of elements
 */
void heap_sort(int *array, size_t size)
{
	long i;
	size_t end;

	if (!array || size < 2)
		return;
	for (i = (size / 2) - 1; i >= 0; i--)
		sift_down(array, size, i, size - 1);
	for (end = size - 1; end > 0; end--)
	{
		swap(&array[0], &array[end]);
		print_array(array, size);
		sift_down(array, size, 0, end - 1);
	}
}
