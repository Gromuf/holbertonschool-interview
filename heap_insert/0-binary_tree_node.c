#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - create a new binary tree node
 * @parent: pointer to parent node (NULL if root)
 * @value: value to store in the new node
 *
 * Return: pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *node = malloc(sizeof(*node));

    if (node == NULL)
        return NULL;

    node->n = value;
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;

    return node;
}