#include "search.h"

static void print_found_range(skiplist_t *start, skiplist_t *end)
{
	printf("Value found between indexes [%lu] and [%lu]\n",
	       start->index, end->index);
}

/**
 * linear_skip - Searches for a value in a sorted skip list with express lane
 * @head: Pointer to head of skip list
 * @value: Value to search for
 *
 * Return: Pointer to node containing value, or NULL
 */
skiplist_t *linear_skip(skiplist_t *head, int value)
{
	skiplist_t *low, *high;

	if (head == NULL)
		return (NULL);

	low = head;
	high = head->express;

	while (high && high->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       high->index, high->n);
		low = high;
		high = high->express;
	}

	if (high)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       high->index, high->n);
		print_found_range(low, high);
	}
	else
	{
		skiplist_t *temp = low;

		while (temp->next)
			temp = temp->next;
		print_found_range(low, temp);
	}

	while (low && (!high || low->index <= high->index))
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       low->index, low->n);
		if (low->n == value)
			return (low);
		low = low->next;
	}

	return (NULL);
}
