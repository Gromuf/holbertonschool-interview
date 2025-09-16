#include <stdio.h>
#include "sandpiles.h"


/**
 * is_stable - Check if a sandpile is stable
 * @grid: 3x3 grid
 *
 * Return: 1 if stable, 0 otherwise
 */

static int is_stable(int grid[3][3])
{
    int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			return (0);
		}
	}
	return (1);
}

/**
 * print_grid - Print a 3x3 grid
 * @grid: the grid
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
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
 * topple - Apply one round of toppling to the grid
 * @grid: 3x3 grid
 */
static void topple(int grid[3][3])
{
	int tmp[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid[i][j] > 3)
            {
                grid[i][j] -= 4;
                if (i > 0)
                    tmp[i - 1][j] += 1;
                if (i < 2)
                    tmp[i + 1][j] += 1;
                if (j > 0)
                    tmp[i][j - 1] += 1;
                if (j < 2)
                    tmp[i][j + 1] += 1;
            }
        }
    }

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            grid[i][j] += tmp[i][j];
}

/**
 * sandpiles_sum - Compute the sum of two sandpiles and stabilize
 * @grid1: first grid (final result is stored here)
 * @grid2: second grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;

    /* Step 1: Add both grids cell by cell */
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];
        }
    }

    /* Step 2: Stabilize the grid */
    while (!is_stable(grid1))
    {
        print_grid(grid1);
        topple(grid1);
    }
}