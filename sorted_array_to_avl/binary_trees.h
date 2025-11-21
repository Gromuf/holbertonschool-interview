#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>

/**
 * struct avl_s - AVL tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 *
 * Description: AVL tree node structure
 */
typedef struct avl_s
{
	int n;
	struct avl_s *parent;
	struct avl_s *left;
	struct avl_s *right;
} avl_t;

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 *
 * @array: Pointer to first element of sorted array
 * @size: Number of elements in array
 *
 * Return: Pointer to root of created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size);

avl_t *create_node(int *array, int start, int end, avl_t *parent);

#endif /* BINARY_TREES_H */
