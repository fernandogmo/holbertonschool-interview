#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdio.h>

#define PRINT_GRID(grid) {\
	int i, j;\
	for (i = 0; i < 3; i++) {\
		if (!i) puts("=");\
		for (j = 0; j < 3; j++) {\
			if (j) putchar(' ');\
			printf("%d", grid[i][j]);\
		}\
		putchar('\n');\
	}\
}\

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

#endif /* SANDPILES_H */
