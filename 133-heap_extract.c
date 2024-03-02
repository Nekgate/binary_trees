#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_extract -function toextracts the root node from a Max Binary Heap
 * @root: pointer to the heap root
 * Return: value of extracted node
 **/
int heap_extract(heap_t **root)
{
	int value;
	heap_t *heap_right, *node;

	if (root == NULL && *root == NULL)
	{
		return (0);
	}

	heap_right = *root;
	value = heap_right->n;
	if (heap_right->left == NULL || heap_right->right == NULL)
	{

		*root = NULL;
		free(heap_right);
		return (value);
	}
}
