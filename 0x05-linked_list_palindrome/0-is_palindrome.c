#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: the head of the list being checked
 * Return: 0 if palindrome, 1 if not
 */

int is_palindrome(listint_t **head)
{
	listint_t *current;
	int i, count = 0;
	int *array;

	if (*head == NULL)
		return (1);
	current = *head;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	array = malloc(count * sizeof(int));
	if (array == NULL)
		return (0);
	current = *head;
	count = 0;
	while (current != NULL)
	{
		array[count] = current->n;
		count++;
		current = current->next;
	}
	count--;
	for (i = 0; i < count; i++)
	{
		if (array[i] != array[count])
			return (0);
		count--;
	}
	return (1);
}
