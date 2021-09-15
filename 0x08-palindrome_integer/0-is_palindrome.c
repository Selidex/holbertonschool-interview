#include "palindrome.h"

/**
 * is_palindrome - checks if a number is a palindrome
 * @n: the number being tested
 * Return: 1 if n is a palindrome, and 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	int p[100];
	int i, count;

	count = 0;
	while (n != 0)
	{
		p[count] = n % 10;
		n = n / 10;
		count++;
	}
	count--;
	for (i = 0; i < count; i++)
	{
		if (p[i] != p[count])
			return (0);
		count--;
	}
	return (1);
}
