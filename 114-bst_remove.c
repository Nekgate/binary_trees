#include "binary_trees.h"
/**
* inorder_successor - Returns the minimum value of a binary search tree.
 * @root: A pointer to the root node of the BST to search.
 *
 * Return: The minimum value of the tree.
 */
bst_t *inorder_successor(bst_t *root)
{
	if (root)
	{
		while (root->left)
		{
			root = root->left;
		}
}
return (root);
}
/**
 * bst_remove -function that Removes a node from a binary search tree.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @value: The value to remove in the BST.
 *
 * Return: A pointer to the new root node after deletion.
 *
 * Description: If the node to be deleted has two children, it
 *              is replaced with its first in-order successor.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}
/**
 * bst_remove_recursive - recursively Removes a node from a binary search tree.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @node: A pointer to the current node in the BST.
 * @value: The value to remove from the BST.
 *
 * Return: A pointer to the root node after deletion.
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node == NULL)
		return (NULL);
		{
	if (node->n == value)
		return (bst_delete(root, node));
	if (node->n > value)
		return (bst_remove_recursive(root, node->left, node->right, value));
		}
		return (NULL);
}
/**
 * bst_delete - Deletes a node from a binary search tree.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the node to delete from the BST.
 *
 * Return: A pointer to the new root node after deletion.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	if (!node->left)
	{
		if (parent)
			if (parent->left == node)
			parent->left = node->right;
		else if (parent)
			parent->right = node->right;
		if (node->right)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	if (!node->right)
	{
		if (parent)
			if (parent->left == node)
				parent->left = node->left;
			else if (parent)
				parent->right = node->left;
		if (node->left)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	successor = inorder_successor(node->right);
	node->n = successor->n;

	return (bst_delete(root, successor));
}





