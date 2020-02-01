#include "header.h"

int main(int argc, char *argv[])
{
	srand(time(NULL));
	clock_t timeStart = clock();

	// Open new FileReader.
	FILE *fileReader;
	fileReader = fopen("output/output.json", "w"); // Open in 'write' mode to clear file.
	fclose(fileReader); // Close file, its now ready to use.

	// Setup API parameters.
	fileReader = fopen("output/api.php", "w");
	fprintf(fileReader, "<?php\ndefine('WORLD_HEIGHT', %i);\ndefine('WORLD_WIDTH', %i);\ndefine('GENERATIONS', %i);", WORLD_HEIGHT, WORLD_WIDTH, GENERATIONS);
	fclose(fileReader);

	system("clear");
	printf("==========================\n");
	printf("World Width:		%i\n", WORLD_WIDTH);
	printf("World Height:		%i\n", WORLD_HEIGHT);
	printf("Total Generations:	%i\n", GENERATIONS);
	printf("==========================\n\n");
	printf("[SERIAL] Begining world population..\n");
	
	populateWorld(); // Populate with random states.

	printf("\nPreparing generation output..\n");

	// Step through generations.
	for (int i = 0; i < GENERATIONS; i++)
	{
		nextGeneration(i);
		printf("Processing generation %i..\n", i + 1);
	}

	clock_t timeEnd = clock();
	double timeTaken = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;
	printf("\nDone generation, took %g seconds to execute.\n\n", timeTaken);
	return 0;
}