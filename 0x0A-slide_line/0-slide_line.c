#include "slide_line.h"

/**
 * slide_line - slides array @line to left or right
 * @line: int array of powers of 2
 * @size: size of @line
 * @direction: either SLIDE_LEFT or SLIDE_RIGHT
 * Return: 1 upon success, or 0 upon failure
*/
int slide_line(int *line, size_t size, int direction)
{
	if (line && size)
		return (direction ? slide_right(line, size)
				  : slide_left(line, size));
	return (0);
}


/**
 * slide_left - slides values in array @line to left
 * @line: int array of powers of 2
 * @size: size of @line
 * Return: int value 1
 */
int slide_left(int *line, size_t size)
{
	size_t i = 0, j = 1;
	int last = line[i], curr = line[j];

	for (; j < size; curr = line[++j])
		if (curr != 0)
			last	=	last == 0	? curr
				:	last == curr	? (line[i++] = last * 2, 0)
				:			  (line[i++] = last, curr);

	if (last)
		line[i++] = last;

	for (; i < size; ++i)
		line[i] = 0;
	return (1);
}


/**
 * slide_right - slides values in array @line to right
 * @line: int array of powers of 2
 * @size: size of @line
 * Return: int value 1
 */
int slide_right(int *line, size_t size)
{
	int i = size - 1, j = size - 2;
	int last = line[i], curr = line[j];

	for (; j >= 0; curr = line[--j])
		if (curr != 0)
		{
			if (!last)
				last = curr;
			else if (last == curr)
			{
				line[i--] = last * 2;
				last = 0;
			}
			else
			{
				line[i--] = last;
				last = curr;
			}
		}

	if (last)
		line[i--] = last;

	for (; i >= 0; --i)
		line[i] = 0;
	return (1);
}
