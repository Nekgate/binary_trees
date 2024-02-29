#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a binary search tree.
 * @tree: A pointer to the root node of the BST to search.
 * @value: The value to search for in the BST.
 *
 * Return: If the tree is NULL or the value is not found, NULL.
 *         Otherwise, a pointer to the node containing the value.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	const bst_t *initial = tree;

	if (initial != NULL)
	{
		if (initial->n == value)
			return ((bst_t *)initial);
		if (initial->n > value)
			return (bst_search(initial->left, value));
		return (bst_search(initial->right, value));
	}
	return (NULL);
}
