#include "binary_trees.h"
#include <stdlib.h>

/**
 * makeNode - makes a node
 * @n: the value of the node
 * @tree: the parent node
 * Return: the node
 */

avl_t *makeNode(int n, avl_t *tree)
{
	avl_t *root = malloc(sizeof(avl_t));

	if (root == NULL)
		return (NULL);
	root->left = NULL;
	root->right = NULL;
	root->n = n;
	if (tree == NULL)
	{
		root->parent = NULL;
		tree = root;
	}
	else
		root->parent = tree;
	return (root);
}

/**
 * zhuli - do the thing
 * @tree: the tree being inserted
 * @array: the array being converted
 * @s: start of array
 * @e: end of array
 * Return: the binary tree
 */

avl_t *zhuli(avl_t *tree, int *array, int s, int e)
{
	int mid;

	if (s > e)
		return (NULL);
	mid = (s + e) / 2;
	tree = makeNode(array[mid], tree);
	if (tree == NULL)
		return (NULL);
	tree->left = zhuli(tree, array, s, mid - 1);
	tree->right = zhuli(tree, array, mid + 1, e);
	return (tree);
}

/**
 * sorted_array_to_avl - converts a sorted array to avl tree
 * @array: the sorted array
 * @size: The size of the array
 * Return: the binary tree
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size < 1)
		return (NULL);
	return (zhuli(NULL, array, 0, size - 1));
}
