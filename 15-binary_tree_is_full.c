#include "binary_trees.h"

/**
 * is_full_recursive - Checks if the binary tree is full recursively.
 * @tree: Pointer to the root node of the tree to examine.
 *
 * Return: 0, If tree is full.
 * Otherwise 1.
 */

int is_full_recursive(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL && tree->right == NULL)
				|| (tree->left == NULL && tree->right != NULL)
				|| is_full_recursive(tree->left) == 0
				|| is_full_recursive(tree->right) == 0)
			return (0);
	}
	return (1);
}

/**
 * binary_tree_is_full - It checks if the binary tree is full.
 * @tree: Pointer to the root node of the tree to examine.
 *
 * Return: 0, If tree is full/NULL.
 * Otherwise 1.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_full_recursive(tree));
}
