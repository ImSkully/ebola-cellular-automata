#include "header.h"

int main(int argc, char *argv[])
{
	srand(time(NULL));

	// Open new FileReader.
	FILE *fileReader;
	fileReader = fopen("output/output.json", "w"); // Open in 'write' mode to clear file.
	fclose(fileReader); // Close file, its now ready to use.

	// Setup API parameters.
	fileReader = fopen("output/api.php", "w");
	fprintf(fileReader, "<?php\ndefine('WORLD_HEIGHT', %i);\ndefine('WORLD_WIDTH', %i);\ndefine('GENERATIONS', %i);", WORLD_HEIGHT, WORLD_WIDTH, GENERATIONS);
	fclose(fileReader);

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
		nextGeneration(i);
		printf("=====================\n");
		printf("World Width:	%i\n", WORLD_WIDTH);
		printf("World Height:	%i\n", WORLD_HEIGHT);
		printf("=====================\n\n");
		printf("\n[Generation %i]\n\n", i + 1);
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