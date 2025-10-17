#include "slide_line.h"
#include <stdio.h>

/**
 * merge_left - Merge and slide numbers to the left (2048 logic)
 * @line: Pointer to the line of integers
 * @size: Number of elements in the line
 */
static void merge_left(int *line, size_t size)
{
	size_t i, j;

	for (i = 0, j = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			if (i != j)
			{
				line[j] = line[i];
				line[i] = 0;
			}
			j++;
		}
	}

	for (i = 0; i + 1 < size; i++)
	{
		if (line[i] != 0 && line[i] == line[i + 1])
		{
			line[i] *= 2;
			line[i + 1] = 0;
		}
	}

	for (i = 0, j = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			if (i != j)
			{
				line[j] = line[i];
				line[i] = 0;
			}
			j++;
		}
	}
}

/**
 * merge_right - Merge and slide numbers to the right (2048 logic)
 * @line: Pointer to the line of integers
 * @size: Number of elements in the line
 */
static void merge_right(int *line, size_t size)
{
	/* 💬 Utilisation de ssize_t (type signé)
	 * pour éviter boucle infinie : size_t ne peut jamais être < 0
	 */
	ssize_t i, j;

	for (i = size - 1, j = size - 1; i >= 0; i--)
	{
		if (line[i] != 0)
		{
			if (i != j)
			{
				line[j] = line[i];
				line[i] = 0;
			}
			j--;
		}
	}

	for (i = size - 1; i > 0; i--)
	{
		if (line[i] != 0 && line[i] == line[i - 1])
		{
			line[i] *= 2;
			line[i - 1] = 0;
		}
	}

	for (i = size - 1, j = size - 1; i >= 0; i--)
	{
		if (line[i] != 0)
		{
			if (i != j)
			{
				line[j] = line[i];
				line[i] = 0;
			}
			j--;
		}
	}
}

/**
 * slide_line - Slides and merges an array of integers like 2048
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 *
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);

	if (direction == SLIDE_LEFT)
		merge_left(line, size);
	else
		merge_right(line, size);

	return (1);
}
