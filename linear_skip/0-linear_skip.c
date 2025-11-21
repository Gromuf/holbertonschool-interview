#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @head: Pointer to the head of the skip list
 * @value: Value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *head, int value)
{
	skiplist_t *express_node, *prev_node;

	if (head == NULL)
		return (NULL);

	express_node = head->express;
	prev_node = head;

	while (express_node != NULL && express_node->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       express_node->index, express_node->n);
		prev_node = express_node;
		express_node = express_node->express;
	}

	if (express_node != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       express_node->index, express_node->n);
		printf("Value found between indexes [%lu] and [%lu]\n",
		       prev_node->index, express_node->index);
	}
	else
	{
		skiplist_t *temp = prev_node;
		while (temp->next != NULL)
			temp = temp->next;
		printf("Value found between indexes [%lu] and [%lu]\n",
		       prev_node->index, temp->index);
	}

	while (prev_node != NULL && prev_node->index <=
	       (express_node != NULL ? express_node->index : prev_node->index))
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       prev_node->index, prev_node->n);
		if (prev_node->n == value)
			return (prev_node);
		prev_node = prev_node->next;
	}

	return (NULL);
}