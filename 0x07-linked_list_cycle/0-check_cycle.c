#include "lists.h"

/**
 * check_cycle - checks if a linked list is a cycle
 * @list: the list being checked
 * Return: 1 is cycle, 0 if not
 */

int check_cycle(listint_t *list)
{
	listint_t *slow, *fast;

	if (list == NULL)
		return (0);

	fast = list;
	slow = list;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast == NULL)
			return (0);
		fast = fast->next;
		slow = slow->next;
		if (fast == slow)
			return (1);
	}
	return (0);
}
