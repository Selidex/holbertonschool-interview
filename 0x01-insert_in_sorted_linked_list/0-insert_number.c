#include "lists.h"

/**
 *insert_node - inserts a node into a sorted link list
 *@head: the list being inserted into
 *@number: the number being inserted
 *Return: null if failed, the node if success.
 */

listint_t *insert_node(listint_t **head, int number){
	listint_t *new;
	listint_t *current;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	if(*head == NULL || new-> n < (*head)->n)
	{
		new->next = *head;
		*head = new;
		return new;
	}
	current = *head;
	while(current->next != NULL && new->n > current->next->n)
	{
		current = current->next;
	}
	new->next = current->next;
	current->next = new;
	return new;
}
