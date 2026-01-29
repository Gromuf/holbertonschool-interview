#include "binary_trees.h"
#include <stdlib.h>

static size_t tree_size(heap_t *tree);
static heap_t *get_last_node(heap_t *root, size_t size);
static void heapify_down(heap_t *root);

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root of the heap
 *
 * Return: Value stored in the extracted node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int extracted_value;
	heap_t *last_node;

	if (!root || !*root)
		return (0);

	extracted_value = (*root)->n;

	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;
		return (extracted_value);
	}

	size_t size = tree_size(*root);

	last_node = get_last_node(*root, size);

	(*root)->n = last_node->n;

	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;

	free(last_node);

	heapify_down(*root);

	return (extracted_value);
}

/**
 * tree_size - Counts the number of nodes in a binary tree
 * @tree: Pointer to the root of the tree
 *
 * Return: Number of nodes in the tree
 */
static size_t tree_size(heap_t *tree)
{
	if (!tree)
		return (0);
	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * get_last_node - Gets the last node in level-order traversal
 * @root: Pointer to the root of the heap
 * @size: Number of nodes in the heap
 *
 * Return: Pointer to the last node
 */
static heap_t *get_last_node(heap_t *root, size_t size)
{
	size_t path = size;
	heap_t *current = root;
	size_t mask = 1UL << (sizeof(size_t) * 8 - 1);

	while (!(path & mask) && mask)
		mask >>= 1;

	mask >>= 1;

	while (mask)
	{
		if (path & mask)
			current = current->right;
		else
			current = current->left;
		mask >>= 1;
	}

	return (current);
}

/**
 * heapify_down - Restores the Max Heap property from a given node
 * @root: Pointer to the node to heapify from
 */
static void heapify_down(heap_t *root)
{
	heap_t *largest = root;
	heap_t *left = root->left;
	heap_t *right = root->right;

	if (left && left->n > largest->n)
		largest = left;
	if (right && right->n > largest->n)
		largest = right;

	if (largest != root)
	{
		int temp = root->n;

		root->n = largest->n;
		largest->n = temp;
		heapify_down(largest);
	}
}
