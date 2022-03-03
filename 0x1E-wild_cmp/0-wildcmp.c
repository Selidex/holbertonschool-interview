#include "holberton.h"


/**
 *_strlen_recursion - returns string length recursively
 *@s: the string being measured
 *Return: the lenght of the string
 */
int _strlen_recursion(char *s)
{
	int n = 1;

	if (s[0] == '\0')
		return (0);

	if (*(s + 1) != '\0')
		n += _strlen_recursion(s + 1);
	return (n);
}

/**
 *do_wild - does the recursive checks
 *@s1: first string
 *@s2: second string
 *@l1: length of first string
 *@l2: length of second string
 *Return: 1 if "identical" 0 if not
 */

int do_wild(char *s1, char *s2, int l1, int l2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s1 != *s2 && *s2 != '*')
		return (0);

	if (*s2 == '*' && *(s2 + 1) == '\0')
		return (1);

	if (*s2 == '*' && *(s2 + 1) == '*')
		return (do_wild(s1, s2 + 1, l1, l2));

	if (*s1 == '\0' && *s2 == '*')
		return (do_wild(s1, s2 + 1, l1, l2));

	if (*s1 == *s2)
		return (do_wild(s1 + 1, s2 + 1, l1, l2));

	if (*s2 == '*' && *(s2 + 1) == *s1)
	{
		return (do_wild(s1, s2 + 1, l1, l2));
	}
	if (*s2 == '*' && *(s2 + 1) == *(s1 + 1))
		return (do_wild(s1 + 1, s2 + 1, l1, l2));

	if (*s2 == '*' && *(s2 + 1) != *(s1 + 1))
		return (do_wild(s1 + 1, s2, l1, l2));

	l1 = l2;
	return (-1);
}

/**
 *wildcmp - checks if two strings are identical, accounting for *
 *@s1: first string
 *@s2: second string, may contain *
 *Return: 1 if "identical" otherwise returns 0
 */

int wildcmp(char *s1, char *s2)
{
	int t1, t2;

	t1 = _strlen_recursion(s1);
	t2 = _strlen_recursion(s2);

	return (do_wild(s1, s2, t1, t2));
}
