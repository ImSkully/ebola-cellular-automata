#include "header.h"

void generateWorld(int* rows, int* cols)
{
	FILE *myFile;
	myFile = fopen("output/test.txt", "w");
	
	for (int i = 1; i <= WORLD_WIDTH; i++)
	{
		for (int j = 1; j <= WORLD_HEIGHT; j++)
		{
			fprintf(myFile, "WIDTH: %i - HEIGHT: %i\n", i, j);
		}
	}
	printf("Done file output.\n");
}