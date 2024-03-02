#include "binary_trees.h"

/**
 * array_to_heap - function to build a Max Binary Heap tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size: the number of element in the array
 *
 * Return: a pointer to the root node of the created Binary Heap
 *         NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	size_t j;
	heap_t *root = NULL;

	if (!(array == NULL))
	{
		for (j = 0; j < size; j++)
		{
			heap_insert(&root, (array[j]));
		}
	}
					return (root);
					}



