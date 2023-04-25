#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees a 2d grid made by alloc_grid function
 * @grid: 2d array made by alloc_grid
 * @height: no of rows in grid
 *
 * Return: Void
 */

void free_grid(char **grid, int height)
{
	while (height > 0)
	{
		free(grid[--height]);

	}
	free(grid);
}
