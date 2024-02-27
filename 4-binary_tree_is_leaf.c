#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
*binary_tree_is_leaf -function to check if node is a leaf or not
*@node: a pointer to the node to be checked
*Return: 1 if node is a leaf and 0 if not
*/
int binary_tree_is_leaf(const binary_tree_t *node)
{
while (node == NULL)
return (0);
while (node->left == NULL || node->right == NULL)
return (1);
}
