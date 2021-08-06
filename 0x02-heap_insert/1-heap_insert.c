#include "binary_trees.h"

/**
 * check - does max heap number swap
 * @tree: the initial position of the new node
 * Return: The final position of the new node
 */

heap_t *check(heap_t *tree)
{
	int tmp = 0;

	while (tree->parent != NULL && tree->n > tree->parent->n)
	{
		tmp = tree->parent->n;
		tree->parent->n = tree->n;
		tree->n = tmp;
		tree = tree->parent;
	}
	return (tree);
}

/**
 * heap_insert - inserts a node into a binary heap
 * @root: root of the binary tree
 * @value: the value being inserted into the heap
 * Return: the node being inserted, or NULL on failure
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *current;

	if (*root == NULL)
	{
		*root = binary_tree_node(*root, value);
		return (*root);
	}
	current = *root;
	current = traverse(current, value);
	current = check(current);
	return (current);
}

/**
 * count - counts nodes in tree
 * @tree: tree being counted
 * Return: the count
 */

int count(heap_t *tree)
{
	if (tree == NULL)
		return (0);
	return (count(tree->left) + 1 + count(tree->right));
}

/**
 * traverse - traverses the tree
 * @tree: the tree being traversed
 * @value: the value of the new node
 * Return: The nodes initial position
 */

heap_t *traverse(heap_t *tree, int value)
{
	if (tree->left == NULL)
	{
		tree->left = binary_tree_node(tree, value);
		return (tree->left);
	}
	else if (tree->right == NULL)
	{
		tree->right = binary_tree_node(tree, value);
		return (tree->right);
	}
	else if (!perfect(tree->left))
		return (traverse(tree->left, value));
	else if (!perfect(tree->right))
	{
		return (traverse(tree->right, value));
	}
	else if (height(tree->left) != height(tree->right))
		return (traverse(tree->right, value));
	else
		return (traverse(tree->left, value));
}
