#include "holberton.h"

/**
 *do_wild - does the recursive checks
 *@s1: first string
 *@s2: second string
 *Return: 1 if "identical" 0 if not
 */

int do_wild(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s1 != *s2 && *s2 != '*')
		return (0);
	if (*s2 == '*' && *(s2 + 1) == '\0')
		return (1);
	if (*s2 == '*' && *(s2 + 1) == '*')
		return (do_wild(s1, s2 + 1));
	if (*s1 == '\0' && *s2 == '*')
		return (do_wild(s1, s2 + 1));
	if (*s1 == *s2)
		return (do_wild(s1 + 1, s2 + 1));
	if (*s2 == '*' && *(s2 + 1) == *s1)
		return (do_wild(s1 + 1, s2 + 1)
			|| do_wild(s1 + 1, s2)
			|| do_wild(s1, s2 + 1)
			);

	if (*s2 == '*' && *(s2 + 1) == *(s1 + 1))
		return (do_wild(s1 + 1, s2 + 1));
	if (*s2 == '*' && *(s2 + 1) != *(s1 + 1))
		return (do_wild(s1 + 1, s2));
	return (1);
}

/**
 *wildcmp - checks if two strings are identical, accounting for *
 *@s1: first string
 *@s2: second string, may contain *
 *Return: 1 if "identical" otherwise returns 0
 */

int wildcmp(char *s1, char *s2)
{
	return (do_wild(s1, s2));
}
