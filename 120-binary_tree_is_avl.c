#include "binary_trees.h"
#include <limits.h>

/* Function prototypes */
int btia_helper(const binary_tree_t *tree, int min, int max);
size_t binary_tree_height(const binary_tree_t *tree);

/**
 * binary_tree_is_avl - This finds if a binary tree is an AVL
 * @tree: The pointer to the root node of the tree
 *
 * Return: 1 if tree is AVL,
 *         0 otherwise.
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (btia_helper(tree, INT_MIN, INT_MAX));
}

/**
 * btia_helper - The helper that finds if a binary tree is an AVL
 * @tree: The pointer to the root node of the tree
 * @min: minimum value
 * @max: maximum value
 *
 * Return: 1 if tree is AVL
 *         0 otherwise
 */

int btia_helper(const binary_tree_t *tree, int min, int max)
{
	int path_lt, path_rt;

	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);

	path_lt = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	path_rt = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	if (abs(path_lt - path_rt) > 1)
		return (0);

	return (btia_helper(tree->left, min, tree->n - 1) &&
			btia_helper(tree->right, tree->n + 1, max));
	/* A part of the BST check logic */
}

/**
 * binary_tree_height - This measures the height of a binary tree
 * @tree: The tree to measure the height of.
 *
 * Return: Height of the tree
 *         0 if tree is NULL.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_lt = 0;
	size_t height_rt = 0;

	if (!tree)
		return (0);

	height_lt = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_rt = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_lt > height_rt ? height_lt : height_rt);
}
