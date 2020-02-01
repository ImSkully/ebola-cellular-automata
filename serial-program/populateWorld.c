#include "header.h"

// Takes the given 2D array and populates each index with a random cell state.
void populateWorld()
{
	int i, j;
	for (i = 0; i < WORLD_WIDTH; i++)
	{
		for (j = 0; j < WORLD_HEIGHT; j++)
		{
			WORLD_ARRAY[i][j] = getRandomState();
		}
	}
}