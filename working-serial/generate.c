#include "header.h"

// Function to proceed to the next generation.
void nextGeneration(int currentGeneration)
{
	FILE *fileReader;
	fileReader = fopen("output/output.json", "a");
	if (fileReader == NULL)
	{
		printf("ERROR: Failed to open file!\n");
	}

	// Opening JSON array brace.
	if (currentGeneration == 0) { fprintf(fileReader, "{"); }

	fprintf(fileReader, "\"%i\":{", ++currentGeneration); // This generation index.
	int i, j;
	for (i = 0; i < WORLD_WIDTH; i++)
	{
		fprintf(fileReader, "\"%i\":{", i); // Row index.
		for (j = 0; j < WORLD_HEIGHT; j++)
		{
			NEXT_GENERATION[i][j] = updateCellStatus(i, j);

			// Parse column index.
			if (j == (WORLD_HEIGHT - 1)) fprintf(fileReader, "\"%i\":%i", j, NEXT_GENERATION[i][j]); else fprintf(fileReader, "\"%i\":%i,", j, NEXT_GENERATION[i][j]);
		}

		// Parse closing brace for row.
		if (i == (WORLD_HEIGHT - 1)) fprintf(fileReader, "}"); else fprintf(fileReader, "},");
	}

	// Parse closing brace for JSON array.
	if (currentGeneration == GENERATIONS) fprintf(fileReader, "}}"); else fprintf(fileReader, "},\n");

	memcpy(WORLD_ARRAY, NEXT_GENERATION, sizeof(NEXT_GENERATION));
	fclose(fileReader);
}
