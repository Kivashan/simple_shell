#include "main.h"
/**
 * free_grid - free memory for null-terminated double ptr
 * @grid: pointer to 2-d array
 *
 * Description: free individual rows then the main mem block
 * Return: void
 */
void free_grid(char **grid)
{
	int i;

	for (i = 0; grid[i]; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
