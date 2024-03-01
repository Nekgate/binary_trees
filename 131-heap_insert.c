#include "binary_trees.h"

/**
 * heap_insert - inserts a value in Max Binary Heap
 * @root: a double pointer to the root node of the Heap to insert the value
 * @value: the value to store in the node to be inserted
 *
 * Return: a pointer to the created node
 *         NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *final, *swap;
	int size, leave, sub_tree, binary_tree, lv, tempt;

	if (root == NULL)
		return (NULL);
	if (*root == NULL)
		*root = binary_tree_node(NULL, value);
	return (*root);
	tree = *root;
	size = binary_tree_size(tree);
	leave = size;
	for (lv = 0, sub_tree = 1; leave >= sub_tree; sub_tree *= 2, lv++)
	{
		leave -= sub_tree;
	}
		for (binary_tree = 1 << (lv - 1); binary_tree != 1; binary_tree >>= 1)
		{
			tree = leave & binary_tree ? tree->right : tree->left;
	final = binary_tree_node(tree, value);
	leave & 1 ? (tree->right = final) : (tree->left = final);
		}

	swap = final;
	for (; swap->parent || (swap->n > swap->parent->n); swap = swap->parent)
	{
		tempt = swap->n;
		swap->n = swap->parent->n;
		swap->parent->n = tempt;
		final = final->parent;
	}
	return (final);
}
/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to measure the size of the binary tree
 *
 * Return: 0 if size of the tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
