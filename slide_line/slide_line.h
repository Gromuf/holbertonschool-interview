#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stddef.h>

/* Macros defining slide directions */
#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

/**
 * slide_line - Slides and merges an array of integers to one direction.
 * @line: Pointer to an array of integers to be slided and merged.
 * @size: Number of elements in the array.
 * @direction: Direction to slide the line (SLIDE_LEFT or SLIDE_RIGHT).
 *
 * Description:
 * This function emulates the behavior of the 2048 game on a single line.
 * It slides all numbers to the given direction, merging identical numbers
 * when they are contiguous or separated by zeros. Each merge operation
 * is performed once per move (like in the original game).
 *
 * Return: 1 on success, 0 on failure (e.g., invalid direction).
 */
int slide_line(int *line, size_t size, int direction);

#endif