#include "binary_trees.h"

/**
 * binary_tree_node - adds a node
 * @parent: the parent of hte node being added
 * @value: the value of the node
 * Return: The node made, or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode;

	newNode = malloc(sizeof(binary_tree_t));
	if (newNode == NULL)
		return (NULL);

	newNode->n = value;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = parent;
	return (newNode);
}

/**
 * balance - returns the balance of trees
 * @tree: the tree being checked
 * Return: the balance
 */

int balance(heap_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);
	left = height(tree->left);
	right = height(tree->right);
	return (left - right);
}

/**
 * full - checks if a tree is full
 * @tree: the tree being checked
 * Return: a boolean
 */

int full(heap_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	return (full(tree->left) &&
		full(tree->right));
}

/**
 * perfect - checks if a tree is perfect
 * @tree: the tree being checked
 * Return: a boolean
 */

int perfect(heap_t *tree)
{
	if (tree == NULL)
		return (0);
	if (full(tree) == 0)
		return (0);
	if (balance(tree->left) != 0 ||
	    balance(tree->right) != 0)
		return (0);
	return (1);
}
