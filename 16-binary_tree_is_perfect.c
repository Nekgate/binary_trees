#include "binary_trees.h"

/**
 * binary_tree_is_leaf - This checks if a node is a leaf
 * @node: pointer to the node to check
 *
 * Return: 1 if node is a leaf and 0 If node is NULL.
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node != NULL && node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

/**
 * binary_tree_height - This measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure height
 *
 * Return: The height of tree. If tree is NULL, return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL || binary_tree_is_leaf(tree))
		return (0);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	if (left >= right)
		return (1 + left);
	return (1 + right);
}

/**
 * binary_tree_is_perfect - This checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, If tree is NULL return 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    binary_tree_t *lt, *rt;

    if (tree == NULL)
        return (0);

    lt = tree->left;
    rt = tree->right;

    if (binary_tree_is_leaf(tree))
        return (1);

    if (lt == NULL || rt == NULL)
        return (0);

    if (binary_tree_height(lt) == binary_tree_height(rt))
    {
        if (binary_tree_is_perfect(lt) && binary_tree_is_perfect(rt))
            return (1);
    }

    return (0);
}
