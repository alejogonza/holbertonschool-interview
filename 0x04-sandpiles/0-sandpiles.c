#include "sandpiles.h"
/**
* print_grid - Prints a grid.
*
* @grid: Grid to be printed.
* Return: Nothing.
*/
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
/**
* is_stable - Define if a sandpile is stable or not.
*
* @grid: Grid to test.
* Return: 1 of stable, otherwise 0.
*/
int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}
/**
* topple - Colapse de sandpile if >3.
*
* @n: number of grains.
* Return: 4 if it collapses.
*/
int topple(int n)
{
	if (n > 3)
		return (4);
	else
		return (0);
}
/**
* unstable_neighbors - checks if the box is going to recieve
* grains from near collapsed boxes.
* @grid1: Grid to be analize.
* @i: Rows coordinate.
* @j: Cols coordinate.
* Return: number of grain recieved.
*/
int unstable_neighbors(int grid1[3][3], int i, int j)
{
	int up = 0, down = 0, right = 0, left = 0;

	if (i < 0 || i > 2 || j < 0 || j > 2)
		return (0);

	if (i - 1 >= 0 && i - 1 < 3)
		if (grid1[i - 1][j] > 3)
			up = 1;
	if (i + 1 >= 0 && i + 1 < 3)
		if (grid1[i + 1][j] > 3)
			down = 1;
	if (j - 1 >= 0 && j - 1 < 3)
		if (grid1[i][j - 1] > 3)
			left = 1;
	if (j + 1 >= 0 && j + 1 < 3)
		if (grid1[i][j + 1] > 3)
			right = 1;

	return (up + down + left + right);
}
/**
* sandpiles_sum - performs sandpiles addition.
*
* @grid1: grid1.
* @grid2: grid2.
* Return: Nothing.
*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int g_copy[3][3];
	int toppling, neighbors;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
	}
	while (is_stable(grid1) != 1)
	{
		printf("=\n");
		print_grid(grid1);
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				g_copy[i][j] = grid1[i][j];
			}
		}
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				toppling =  topple(g_copy[i][j]);
				neighbors = unstable_neighbors(g_copy, i, j);
				grid1[i][j] = grid1[i][j] - toppling + neighbors;
			}
		}
	}
}
