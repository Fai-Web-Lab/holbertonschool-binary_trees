#include "binary_trees.h"

/**
	* binary_tree_height_for_balance - Measures height for balance calculation
	* @tree: Pointer to the root node of the tree to measure the height
	*
	* Return: Height of the tree, 0 if tree is NULL
	*/
size_t binary_tree_height_for_balance(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
	return (0);

	left_height = binary_tree_height_for_balance(tree->left);
	right_height = binary_tree_height_for_balance(tree->right);

	if (left_height > right_height)
	return (left_height + 1);
	else
	return (right_height + 1);
}

/**
	* binary_tree_balance - Measures the balance factor of a binary tree
	* @tree: Pointer to the root node of the tree to measure the balance factor
	*
	* Return: Balance factor, 0 if tree is NULL
	*/
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
	return (0);

	/* Calculate heights of left and right subtrees */
	left_height = (int)binary_tree_height_for_balance(tree->left);
	right_height = (int)binary_tree_height_for_balance(tree->right);

	/* Balance factor = height(left) - height(right) */
	return (left_height - right_height);
}
