#include "binary_trees.h"

/**
	* is_bst - checks if a binary tree is a valid BST
	* @tree: pointer to the root node
	* @min: minimum allowed value
	* @max: maximum allowed value
	*
	* Return: 1 if valid BST, 0 otherwise
	*/
static int is_bst(const binary_tree_t *tree, long min, long max)
{
	if (tree == NULL)
	return (1);

	if (tree->n <= min || tree->n >= max)
	return (0);

	return (is_bst(tree->left, min, tree->n) &&
	is_bst(tree->right, tree->n, max));
}

/**
	* binary_tree_is_bst - checks if a binary tree is a valid BST
	* @tree: pointer to the root node
	*
	* Return: 1 if BST, 0 otherwise
	*/
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
	return (0);

	return (is_bst(tree, LONG_MIN, LONG_MAX));
}
