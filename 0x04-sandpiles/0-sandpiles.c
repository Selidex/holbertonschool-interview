#include "sandpiles.h"
#include <string.h>

/**
 * is_stable - checks if a sandpile is stable
 * @grid: the sandpile being checked
 * Return: 1 if stable, 0 if not
 */

int is_stable(int grid[3][3])
{
	int stable = 1;
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				stable = 0;
		}
	}
	return (stable);
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */

static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_sum - adds 2 sandpiles
 * @grid1: the first pile
 * @grid2: the second pile
 * Return: void
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, tmp[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}

	while (!is_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		memset(&tmp, 0, sizeof(tmp));
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					tmp[i][j] += grid1[i][j] - 4;
					if (i - 1 >= 0)
						tmp[i - 1][j] += 1;
					if (i + 1 <= 2)
						tmp[i + 1][j] += 1;
					if (j - 1 >= 0)
						tmp[i][j - 1] += 1;
					if (j + 1 <= 2)
						tmp[i][j + 1] += 1; }
				else
					tmp[i][j] += grid1[i][j]; }
		}
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				grid1[i][j] = tmp[i][j];
			} } } }
