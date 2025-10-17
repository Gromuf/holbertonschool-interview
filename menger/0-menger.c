#include "menger.h"

/**
 * draw_char - Determines whether to print '#' or ' '
 * @row: Row index
 * @col: Column index
 *
 * Return: void
 */
void draw_char(int row, int col)
{
	while (row > 0 || col > 0)
	{
		if (row % 3 == 1 && col % 3 == 1)
		{
			putchar(' ');
			return;
		}
		row /= 3;
		col /= 3;
	}
	putchar('#');
}

/**
 * menger - Draws a 2D Menger sponge
 * @level: Level of the Menger sponge
 *
 * Return: void
 */
void menger(int level)
{
	int size, row, col;
	if (level < 0)
		return;
	size = pow(3, level);
	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
			draw_char(row, col);
		putchar('\n');
	}
}