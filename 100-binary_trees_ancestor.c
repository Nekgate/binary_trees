#include "binary_trees.h"

/**
 * binary_trees_ancestor - This finds the lowest common ancestor of two nodes.
 * @first: The pointer to the first node.
 * @second: The pointer to the second node.
 *
 * Return: Lowest common ancestor node of the two given nodes.
 * If no common ancestor found, return NULL
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t
		*first, const binary_tree_t *second)
{
	binary_tree_t *tmp;

	if (first == NULL || second == NULL)
		return (NULL);
	tmp = (binary_tree_t *)second;
	while (first)
	{
		while (second)
		{
			if (first == second)
				return ((binary_tree_t *)first);
			second = second->parent;
		}
		second = tmp;
		first = first->parent;
	}
	return (NULL);
}
