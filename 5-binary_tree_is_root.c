#include "binary_trees.h"
/**
*binary_tree_is_root -function to check if node is a root or not
*@node: a pointer to the node to be checked
*Return: 1 if node is a root and 0 if not
*/
int binary_tree_is_root(const binary_tree_t *node)
{
if (node == NULL)
return (0);
if (node->parent == NULL)
return (1);
return (0);
}
