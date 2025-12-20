#include "binary_trees.h"

/**
	* binary_trees_ancestor - find the lowest common ancestor of 2 nodes
	* @first: pointer to the 1st node
	* @second: pointer to the 2nd node
	*
	* Return: pointer to the lowest common ancestor, or NULL if none
	*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second)
{
	const binary_tree_t *a, *b;

	if (first == NULL || second == NULL)
	return (NULL);

	a = first;
	while (a)
	{
	b = second;
	while (b)
	{
	if (a == b)
	return ((binary_tree_t *)a);
	b = b->parent;
	}
	a = a->parent;
	}

	return (NULL);
}
