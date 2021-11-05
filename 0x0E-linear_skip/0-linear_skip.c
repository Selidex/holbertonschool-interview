#include "search.h"

/**
 * printa - prints the first statement, function exists due to betty format
 * @index: the index
 * @n: the value
 * Return: void
 */

void printa(size_t index, int n)
{
	printf("Value checked at index [%lu] = [%d]\n", index, n);
}

/**
 * printb - prints the second statement, betty compliance
 * @a: the first index
 * @b: the second index
 * Return: void
 */

void printb(size_t a, size_t b)
{
	printf("Value found between indexes [%lu] and [%lu]\n", a, b);
}

/**
 * linear_skip - searches for a value in a sorted skip list of integers.
 * @list: the list being searched through
 * @value: the value being searched for
 * Return: a pointer to the node that contains the value, or NULL
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *search, *found;

	if (list == NULL)
		return (NULL);
	search = list;
	while (search != NULL)
	{
		if (search->express != NULL)
		{
			printa(search->express->index, search->express->n);
			if (value < search->express->n)
			{
				printb(search->index, search->express->index);
				found = search;
				while (found != search->express)
				{
					printa(found->index, found->n);
					if (found->n == value)
					{
						return (found);
					}
					found = found->next;
				}
			}
			search = search->express;
		}
		else
		{
			found = search;
			while (found != NULL)
			{
				printa(found->index, found->n);
				if (found->n == value)
					return (found);
				found = found->next;
			}
			return (NULL);
		}
	}
	return (NULL);
}
