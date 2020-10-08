#include "menger.h"


/**
 * menger - draws a 2D Menger Sponge, AKA a Sierpinksi Carpet
 * @level: how many levels of Menger sponge to be drawn
 */
void menger(int level)
{
	int row, col, r, c;
	int size = pow(3, level);
	char x;

	if (level < 0)
		return;
	for (row = 0; row < size; ++row)
	{
		for (col = 0; col < size; ++col)
		{
			x = '#';
			for (r = row, c = col; r || c; r /= 3, c /= 3)
			{
				if (r % 3 == 1 && c % 3 == 1)
				{
					x = ' ';
					break;
				}
			}
			putchar(x);
		}
		putchar('\n');
	}

}
