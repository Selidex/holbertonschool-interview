#include "lists.h"

/**
 * find_listint_loop - finds a loop within a linked list
 * @head: the head of the list
 * Return: the address of the loop
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow, *fast;

	if (head == NULL)
		return (NULL);
	slow = head;
	fast = head;
	while (fast != NULL)
	{
		slow = slow->next;
		if (fast->next->next == NULL)
			break;
		fast = fast->next->next;
		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (slow);
		}
	}
	return (NULL);
}
