#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

typedef binary_tree_t avl_t;

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 *
 * @array: Pointer to first element of sorted array
 * @size: Number of elements in array
 *
 * Return: Pointer to root of created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size);

#endif /* BINARY_TREES_H */
