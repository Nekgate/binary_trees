#include "binary_trees.h"
#include <stdio.h>

/**
 * greater_than - This check if all values
 *      in the tree are greater than a value
 * @tree: The pointer to the tree to check
 * @val: The value to check against
 *
 * Return: 1 if true, and 0 otherwise.
 */

int greater_than(const binary_tree_t *tree, int val)
{
	int lt, rt;

	if (tree == NULL)
		return (1);
	if (tree->n > val)
	{
		lt = greater_than(tree->left, val);
		rt = greater_than(tree->right, val);
		if (lt && rt)
			return (1);
	}
	return (0);
}

/**
 * less_than - This check if all values
 *      In the tree are less than a specific value.
 * @tree: The pointer to the tree to check
 * @val: The value to check against
 *
 * Return: 1 if true, 0 if false
 */
int less_than(const binary_tree_t *tree, int val)
{
	int lt, rt;

	if (tree == NULL)
		return (1);
	if (tree->n < val)
	{
		lt = less_than(tree->left, val);
		rt = less_than(tree->right, val);
		if (lt && rt)
			return (1);
	}
	return (0);
}

/**
 * binary_tree_is_bst - This checks if a binary tree is
 *          A valid binary search tree
 * @tree: The pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise.
 *              If tree is NULL, return 0
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (less_than(tree->left, tree->n) && greater_than(tree->right, tree->n))
	{
		if (!tree->left || binary_tree_is_bst(tree->left))
		{
			if (!tree->right || binary_tree_is_bst(tree->right))
				return (1);
		}
	}
	return (0);
}
