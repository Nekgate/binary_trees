#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure height.
 *
 * Return: Height, If tree is NULL, return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lef = 0, rigt = 0;

		lef = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		rigt = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((lef > rigt) ? lef : rigt);
	}
	return (0);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: Balance factor, If tree is NULL return 0.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
	return (0);
}
