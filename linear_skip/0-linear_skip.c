#include "search.h"

/**
 * print_range - Prints the search range
 * @low: Starting node
 * @high: Ending node
 */
static void print_range(skiplist_t *low, skiplist_t *high)
{
	printf("Value found between indexes [%lu] and [%lu]\n",
	       low->index, high->index);
}

/**
 * find_express_range - Moves along express lane to find search interval
 * @head: Pointer to head of list
 * @value: Value to search for
 *
 * Return: pointer to the lower bound of the range
 */
static skiplist_t *find_express_range(skiplist_t *head, skiplist_t **high,
				      int value)
{
	skiplist_t *low = head;

	*high = head->express;

	while (*high && (*high)->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       (*high)->index, (*high)->n);
		low = *high;
		*high = (*high)->express;
	}

	if (*high)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       (*high)->index, (*high)->n);
		print_range(low, *high);
	}
	else
	{
		skiplist_t *tmp = low;

		while (tmp->next)
			tmp = tmp->next;
		print_range(low, tmp);
	}

	return (low);
}

/**
 * linear_skip - Searches for a value in a sorted skip list
 * @head: Pointer to head of skip list
 * @value: Value to search for
 *
 * Return: Pointer to node containing value, or NULL
 */
skiplist_t *linear_skip(skiplist_t *head, int value)
{
	skiplist_t *low, *high;

	if (!head)
		return (NULL);

	low = find_express_range(head, &high, value);

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
