#include "header.h"

// Function to proceed to the next generation.
void nextGeneration()
{
	int i, j;
	for (i = 0; i < WORLD_WIDTH; i++)
	{
		for (j = 0; j < WORLD_HEIGHT; j++)
		{
			NEXT_GENERATION[i][j] = updateCellStatus(i, j);
		}
	}
	memcpy(WORLD_ARRAY, NEXT_GENERATION, sizeof(NEXT_GENERATION));
}
