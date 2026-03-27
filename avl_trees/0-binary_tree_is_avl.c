#include "binary_trees.h"
#include <limits.h>

/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node
 * Return: Height of the tree, or 0 if NULL
 */
size_t height(const binary_tree_t *tree)
{
	size_t left_h, right_h;

	if (tree == NULL)
		return (0);

	left_h = height(tree->left);
	right_h = height(tree->right);

	return ((left_h > right_h ? left_h : right_h) + 1);
}

/**
 * is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node
 * @min: Lower bound for the node's value
 * @max: Upper bound for the node's value
 * Return: 1 if valid BST, 0 otherwise
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst(tree->left, min, tree->n) &&
		is_bst(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node
 * Return: 1 if AVL, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left_h, right_h, diff;

	if (tree == NULL)
		return (0);

	if (!is_bst(tree, INT_MIN, INT_MAX))
		return (0);

	left_h = height(tree->left);
	right_h = height(tree->right);

	diff = left_h - right_h;
	if (diff < -1 || diff > 1)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left == NULL)
		return (binary_tree_is_avl(tree->right));
	if (tree->right == NULL)
		return (binary_tree_is_avl(tree->left));

	return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
}
