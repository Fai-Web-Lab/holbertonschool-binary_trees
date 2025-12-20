#include "binary_trees.h"

/**
	* tree_height - measures the height of a binary tree
	* @tree: pointer to the root node
	*
	* Return: height of the tree
	*/
static size_t tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
	return (0);

	left = tree_height(tree->left);
	right = tree_height(tree->right);

	return ((left > right ? left : right) + 1);
}

/**
	* print_level - prints all nodes at a given level
	* @tree: pointer to the root node
	* @level: level to print
	* @func: function to call for each node
	*/
static void print_level(const binary_tree_t *tree, size_t level,
	void (*func)(int))
{
	if (tree == NULL)
	return;

	if (level == 1)
	func(tree->n);
	else
	{
	print_level(tree->left, level - 1, func);
	print_level(tree->right, level - 1, func);
	}
}

/**
	* binary_tree_levelorder - traverses a binary tree using level-order
	* @tree: pointer to the root node
	* @func: function to call for each node
	*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t h, i;

	if (tree == NULL || func == NULL)
	return;

	h = tree_height(tree);

	for (i = 1; i <= h; i++)
	print_level(tree, i, func);
}
