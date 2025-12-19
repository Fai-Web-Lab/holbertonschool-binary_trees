#include "binary_trees.h"

/**
	* tree_size - counts the number of nodes in a binary tree
	* @tree: pointer to the root node
	*
	* Return: number of nodes
	*/
static size_t tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
	return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
	* is_complete - checks if a binary tree is complete using index method
	* @tree: pointer to the root node
	* @index: index of the current node
	* @size: total number of nodes
	*
	* Return: 1 if complete, 0 otherwise
	*/
static int is_complete(const binary_tree_t *tree, size_t index, size_t size)
{
	if (tree == NULL)
	return (1);

	if (index >= size)
	return (0);

	return (is_complete(tree->left, 2 * index + 1, size) &&
	is_complete(tree->right, 2 * index + 2, size));
}

/**
	* binary_tree_is_complete - checks if a binary tree is complete
	* @tree: pointer to the root node
	*
	* Return: 1 if complete, 0 otherwise
	*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (tree == NULL)
	return (0);

	size = tree_size(tree);
	return (is_complete(tree, 0, size));
}
