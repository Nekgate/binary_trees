#include "binary_trees.h"

/**
 * binary_tree_height - This measures the height of a binary tree
 * @tree: The pointer to the root node of tree to measure the height
 *
 * Return: The height of the tree. If tree is NULL, return 0
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	{
		size_t k = 0, j = 0;

		k = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		j = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((k > j) ? k : j);
	}
}

/**
 * binary_tree_level - This perform a function on
 * A specific level of a binary tree.
 * @tree: The pointer to the root of the tree.
 * @lev: The level of the tree to perform a function on.
 * @func: function to perform.
 *
 * Return: void.
 */

void binary_tree_level(const binary_tree_t *tree,
		size_t lev, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (lev == 1)
		func(tree->n);
	else if (lev > 1)
	{
		binary_tree_level(tree->left, lev - 1, func);
		binary_tree_level(tree->right, lev - 1, func);
	}
}

/**
 * binary_tree_levelorder - This traverses a binary tree using
 * level-order traversal
 * @tree: The pointer to the root node of the tree to traverse
 * @func: The pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function
 *
 * Return: void
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, j;

	if (tree == NULL || func == NULL)
		return;
	height = binary_tree_height(tree);
	for (j = 1; j <= height; j++)
		binary_tree_level(tree, j, func);
}
