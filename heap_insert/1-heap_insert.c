#include <stdlib.h>
#include "binary_trees.h"

static size_t tree_size(const binary_tree_t *tree);
static heap_t *insertion_parent(heap_t *root);
static heap_t *heap_sift_up(heap_t *node);

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Address of the pointer to the heap root
 * @value: Value to insert
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent, *node;

	if (root == NULL)
	{
		return (NULL);
	}

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	parent = insertion_parent(*root);
	if (parent == NULL)
	{
		return (NULL);
	}

	node = binary_tree_node(parent, value);
	if (node == NULL)
	{
		return (NULL);
	}

	if (parent->left == NULL)
	{
		parent->left = node;
	}
	else
	{
		parent->right = node;
	}
	node = heap_sift_up(node);

	return (node);
}

/**
 * tree_size - Computes the size (number of nodes) of a binary tree
 * @tree: Pointer to the tree
 *
 * Return: Number of nodes in the tree
 */
static size_t tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * insertion_parent - Finds the parent node where the next insertion must occur
 *                    to keep the tree complete (level-order scan).
 * @root: Root of the heap
 *
 * Return: Pointer to the parent for insertion, or NULL on failure
 */
static heap_t *insertion_parent(heap_t *root)
{
	size_t size, front = 0, back = 0;
	heap_t **q, *cur, *res = NULL;

	if (root == NULL)
	{
		return (NULL);
	}

	size = tree_size(root);
	q = malloc(sizeof(*q) * (size + 1));
	if (q == NULL)
	{
		return (NULL);
	}

	q[back++] = root;
	while (front < back)
	{
		cur = q[front++];

		if (cur->left == NULL || cur->right == NULL)
		{
			res = cur;
			break;
		}

		q[back++] = cur->left;
		q[back++] = cur->right;
	}

	free(q);
	return (res);
}

/**
 * heap_sift_up - Restores Max-Heap order by swapping values upward.
 * @node: Newly inserted node (initial position)
 *
 * Return: Pointer to the node that now contains the originally inserted value
 *         after the sift-up process.
 */
static heap_t *heap_sift_up(heap_t *node)
{
	int tmp;

	while (node->parent != NULL && node->n > node->parent->n)
	{
		tmp = node->n;
		node->n = node->parent->n;
		node->parent->n = tmp;
		node = node->parent;
	}
	return (node);
}
