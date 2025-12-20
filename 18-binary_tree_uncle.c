#include "binary_trees.h"

/**
	* binary_tree_uncle - Finds the uncle of a node
	* @node: Pointer to the node to find the uncle
	*
	* Return: Pointer to the uncle node, or NULL if no uncle
	*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent, *grandparent;

	if (node == NULL || node->parent == NULL)
	return (NULL);

	/* Get the parent of the node */
	parent = node->parent;

	/* Get the grandparent (parent of parent) */
	grandparent = parent->parent;
	if (grandparent == NULL)
	return (NULL);

	/* Uncle is the sibling of the parent */
	if (grandparent->left == parent)
	return (grandparent->right);
	else
	return (grandparent->left);
}
