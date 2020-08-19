#include "sandpiles.h"

/**
 * sandpiles_sum - function that computes the sum of two sandpiles
 * @grid1: stable sandpile
 * @grid2: stable sandpile
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, left, right, up, down, uneven = 0;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			grid2[i][j] = 0;
		}

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid1[i][j] > 3)
			{
				if (!uneven)
					PRINT_GRID(grid1);
				uneven = 1;
				grid1[i][j] -=  4;
				left = j - 1;
				right = j + 1;
				up = i - 1;
				down = i + 1;
				if (left > -1)
					grid2[i][left] += 1;
				if (right < 3)
					grid2[i][right] += 1;
				if (up > -1)
					grid2[up][j] += 1;
				if (down < 3)
					grid2[down][j] += 1;
			}
	if (uneven)
		sandpiles_sum(grid1, grid2);
}
