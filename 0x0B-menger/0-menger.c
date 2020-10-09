#include "menger.h"

/**
 * menger - draws a 2D Menger Sponge, AKA a Sierpinksi Carpet
 * @level: dimension of Menger sponge to be drawn
 */
void menger(int level)
{
	int i, j, n, size = pow(3, level);

	for (i = 0; i < size; ++i)
	{
		for (j = 0; j < size; ++j)
		{
			for (n = size / 3; n; n /= 3)
				if (((i % (n * 3)) / n == 1) &&
				    ((j % (n * 3)) / n == 1))
					break;
			putchar(n ? ' ' : '#');
		}
		putchar('\n');
	}
}
