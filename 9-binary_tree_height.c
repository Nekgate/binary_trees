#include "binary_trees.h"

/**
 * binary_tree_height -function that  Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: return 0 if tree is NULL.
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



