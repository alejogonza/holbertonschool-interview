#include "binary_trees.h"

/**
 *sorted_array_to_avl - function that builds an AVL tree from an array
 *
 *@array: pointer to the first element of the array to be converted
 *@size: number of element in the array
 *
 *Return: pointer to the root node of the created AVL tree, or NULL on failure
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree;

	if (!array || size == 0)
		return (NULL);

	tree = fill_avl_tree(NULL, array, 0, size - 1);

	return (tree);
}


/**
 *fill_avl_tree - function that builds an AVL tree from an array
 *
 *@parent: pointer to parent of the new node
 *@array: pointer to the first element of the array to be converted
 *@start: index to start
 *@end: index to end
 *
 *Return: pointer to the root node of the created AVL tree, or NULL on failure
 */

avl_t *fill_avl_tree(avl_t *parent, int *array, size_t start, size_t end)
{
	avl_t *node;
	size_t index;

	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);

	index = (start + end) / 2;

	node->n = array[index];
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	if (index != start)
		node->left = fill_avl_tree(node, array, start, index - 1);

	if (index != end)
		node->right = fill_avl_tree(node, array, index + 1, end);

	return (node);
}
