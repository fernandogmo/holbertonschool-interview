#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdio.h>
#include <stdbool.h>

#define PRINT_GRID(grid) {\
	int i, j;\
	puts("=");\
	for (i = 0; i < 3; i++)\
	{\
		for (j = 0; j < 3; j++)\
			printf(j ? " %d" : "%d", (grid)[i][j]);\
		putchar('\n');\
	} \
}

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

#endif /* SANDPILES_H */
