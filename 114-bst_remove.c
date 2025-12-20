#include "binary_trees.h"
#include <stdlib.h>

/**
	* bst_min_value_node - Finds the node with the minimum value
	* @node: Pointer to the root node of the subtree
	*
	* Return: Pointer to the node with the smallest value
	*/
bst_t *bst_min_value_node(bst_t *node)
{
	while (node && node->left)
	node = node->left;
	return (node);
}

/**
	* bst_remove - Removes a node with a given value from a BST
	* @root: Pointer to the root node of the BST
	* @value: Value of the node to remove
	*
	* Return: Pointer to the new root of the BST after removal
	*/
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (!root)
	return (NULL);

	if (value < root->n)
	root->left = bst_remove(root->left, value);
	else if (value > root->n)
	root->right = bst_remove(root->right, value);
	else
	{
	if (!root->left && !root->right)
	{
	free(root);
	return (NULL);
	}

	if (!root->left)
	{
	temp = root->right;
	temp->parent = root->parent;
	free(root);
	return (temp);
	}

	if (!root->right)
	{
	temp = root->left;
	temp->parent = root->parent;
	free(root);
	return (temp);
	}

	temp = bst_min_value_node(root->right);
	root->n = temp->n;
	root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}
