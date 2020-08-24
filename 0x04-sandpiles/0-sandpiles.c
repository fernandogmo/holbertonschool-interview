#include "sandpiles.h"

/**
 * sandpiles_sum - compute the sum of two stable sandpiles
 **			while printing intermediate states
 * @grid1: stable sandpile
 * @grid2: stable sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, changed;

	do {
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
			{
				grid1[i][j] += grid2[i][j];
				grid2[i][j] = 0;
			}

		changed = false;
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				if (grid1[i][j] > 3)
				{
					if (!changed)
						PRINT_GRID(grid1);
					changed = true;
					grid1[i][j] -= 4;
					if (i > 0)
						grid2[i - 1][j] += 1;
					if (i < 2)
						grid2[i + 1][j] += 1;
					if (j > 0)
						grid2[i][j - 1] += 1;
					if (j < 2)
						grid2[i][j + 1] += 1;
				}
	} while (changed);
}
