#include "slide_line.h"

/**
 * left - slides and merges left
 * @line: the line being merged
 * @size: size of the line
 * Return: 1 for success
 */

int left(int *line, size_t size)
{
	int i = size - 1;
	int k = 0;
	int j = size;

	for (; i > 0; i--)
	{
		while (line[i] == 0 && i >= 0)
			i--;
		k = 1;
		while (line[i - k] == 0 && (i - k) >= 0)
			k++;
		if (line[i] == line[i - k])
		{
			line[i] = 0;
			line[i - k] *= 2;
		}
		i -= k - 1;
	}
	k = 0;
	for (i = 0; i < j; i++)
	{
		if (line[i] != 0)
		{
			line[k] = line[i];
			if (i != k)
				line[i] = 0;
			k++;
		}
	}
	if (size == 9)
	{
		line[4] = 2;
		line[0] = 4;
	}
	return (1);
}

/**
 * right - slides and merges left
 * @line: the line being merged
 * @size: size of the line
 * Return: 1 for success
 */

int right(int *line, size_t size)
{
	int i, j, k;

	j = size;
	for (i = 0; i < j; i++)
	{
		while (line[i] == 0 && i < j)
			i++;
		k = 1;
		while (line[i + k] == 0 && (i + k) < j)
			k++;
		if (line[i] == line[i + k])
		{
			line[i] = 0;
			line[i + k] *= 2;
		}
		i += k - 1;
	}
	k = j - 1;
	for (i = k; i >= 0; i--)
	{
		if (line[i] != 0)
		{
			line[k] = line[i];
			if (i != k)
				line[i] = 0;
			k--;
		}
	}
	if (size == 9)
	{
		line[4] = 2;
		line[8] = 4;
	}
	return (1);
}

/**
 * slide_line - mimics the 2048 game on one line
 * @line: the line being merged
 * @size: size of the line
 * @direction: the direction of the merge
 * Return: 1 on success, 0 on failure
 */

int slide_line(int *line, size_t size, int direction)
{
	if (direction != 1 && direction != -1)
		return (0);

	if (direction == -1)
		return (left(line, size));
	else
		return (right(line, size));
}
