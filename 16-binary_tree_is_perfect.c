#include "binary_trees.h"

/**
	* binary_tree_height_for_perfect - Measures height for perfect tree check
	* @tree: Pointer to the root node of the tree to measure the height
	*
	* Return: Height of the tree (number of edges), 0 if tree is NULL
	*/
size_t binary_tree_height_for_perfect(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
	return (0);

	left_height = binary_tree_height_for_perfect(tree->left);
	right_height = binary_tree_height_for_perfect(tree->right);

	if (left_height > right_height)
	return (left_height + 1);
	else
	return (right_height + 1);
}

/**
	* binary_tree_is_perfect - Checks if a binary tree is perfect
	* @tree: Pointer to the root node of the tree to check
	*
	* Return: 1 if the tree is perfect, 0 otherwise
	*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
	return (0);

	/* Get heights of left and right subtrees */
	left_height = binary_tree_height_for_perfect(tree->left);
	right_height = binary_tree_height_for_perfect(tree->right);

	/* Heights must be equal for perfect tree */
	if (left_height != right_height)
	return (0);

	/* If leaf node, it's perfect */
	if (tree->left == NULL && tree->right == NULL)
	return (1);

	/* Both children must exist and both subtrees must be perfect */
	if (tree->left != NULL && tree->right != NULL)
	return (binary_tree_is_perfect(tree->left) &&
	binary_tree_is_perfect(tree->right));

	/* If we reach here, tree is not perfect */
	return (0);
}
