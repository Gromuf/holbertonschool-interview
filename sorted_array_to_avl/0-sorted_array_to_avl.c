#include <stdlib.h>
#include "binary_trees.h"

/**
 * create_node - Recursively creates nodes for an AVL tree
 *
 * @array: Pointer to the sorted array
 * @start: Starting index of the current subarray
 * @end: Ending index of the current subarray
 * @parent: Pointer to the parent node
 *
 * Return: Pointer to created AVL tree node, or NULL on failure
 */
static avl_t *create_node(int *array, int start, int end, avl_t *parent)
{
	int mid;
	avl_t *node;

	if (start > end)
		return (NULL);

	mid = start + (end - start) / 2;
	node = malloc(sizeof(avl_t));
	if (node == NULL)
		return (NULL);

	node->n = array[mid];
	node->parent = parent;

	node->left = create_node(array, start, mid - 1, node);
	node->right = create_node(array, mid + 1, end, node);

	return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 *
 * @array: Pointer to first element of sorted array
 * @size: Number of elements in array
 *
 * Return: Pointer to root of created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (create_node(array, 0, (int)size - 1, NULL));
}
