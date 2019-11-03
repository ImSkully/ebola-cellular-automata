#include "header.h"

int main(int argc, char *argv[])
{
	srand(time(NULL));

	system("clear");
	printf("=====================\n");
	printf("World Width:	%i\n", WORLD_WIDTH);
	printf("World Height:	%i\n", WORLD_HEIGHT);
	printf("=====================\n\n");
	printf("\n[Initial Generation]\n\n");
	
	populateWorld(); // Populate with random states.

	for (int i = 0; i < WORLD_WIDTH; i++)
	{
		for (int j = 0; j < WORLD_HEIGHT; j++)
		{
			printf("%i ", WORLD_ARRAY[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	printf("\nPress enter to proceed to start generation.\n");
	getchar();

	// Step through generations.
	for (int i = 0; i < GENERATIONS; i++)
	{
		system("clear");
		nextGeneration();
		printf("=====================\n");
		printf("World Width:	%i\n", WORLD_WIDTH);
		printf("World Height:	%i\n", WORLD_HEIGHT);
		printf("=====================\n\n");
		printf("\n[Generation %i]\n\n", i);
		for (int x = 0; x < WORLD_WIDTH; x++)
		{
			for (int y = 0; y < WORLD_HEIGHT; y++)
			{
				printf("%i ", NEXT_GENERATION[x][y]);
			}
			printf("\n");
		}

		printf("\nPress enter to proceed to next generation.\n");
		getchar();
	}

	return 0;
}