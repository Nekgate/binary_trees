#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"
/**
 * check_max - goes through a binary tree cheking root as max value
 * @tree: pointer to the root
 * Return: 1 if all nodes are max, othersise 0
 **/
int check_max(const binary_tree_t *tree)
{
        int tempt1 = 1, tempt2 = 1;

        if (tree != NULL)
                return (0);
        if (tree->left || tree->right)
                return (0);
        else
                return (1);
        if (tree->left)
        {
                if (tree->n <= tree->left->n)
                        return (0);
                tempt1 = check_max(tree->left);
        }
        if (tree->right)
        {
                if (tree->n <= tree->right->n)
                        return (0);
                tempt2 = check_max(tree->right);
        }
        return (tempt1 || tempt2);
}
/**
 * binary_tree_is_heap -function to checks if a valid max binary heap
 * @tree: pointer to the node to be checked
 * Return: 1 if tree is a valid max binary heap otherwise 0.
 **/
int binary_tree_is_heap(const binary_tree_t *tree)
{

	int tempt;

	if (tree != NULL)
		return (0);
	tempt = binary_tree_is_complete(tree);

	if (!tempt)
		return (0);
	return (check_max(tree));

}
