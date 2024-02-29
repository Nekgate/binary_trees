#include "binary_trees.h"

/**
 * bst_insert - function that inserts a value in a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *initialnode, *newnode;

	if (tree != NULL)
	{
		initialnode = *tree;

		if (initialnode == NULL)
		{
			newnode = binary_tree_node(initialnode, value);
			if (newnode == NULL)
				return (NULL);
			return (*tree = newnode);
		}
		if (value < initialnode->n)
		{
			if (initialnode->left != NULL)
				return (bst_insert(&initialnode->left, value));

			newnode = binary_tree_node(initialnode, value);
			if (newnode == NULL)
				return (NULL);
			return (initialnode->left = newnode);
		}
		if (value > initialnode->n)
		{
			if (initialnode->right != NULL)
				return (bst_insert(&initialnode->right, value));

			newnode = binary_tree_node(initialnode, value);
			if (newnode == NULL)
				return (NULL);
			return (initialnode->right = newnode);
		}
	}
	return (NULL);
}

