#include "header.h"

// Child function for multi-threaded generation.
void *thread_populateWorld(void* thread_id)
{
	long threadID = (long) thread_id;
	int x, y; // X and Y index of the world array.
	int rowsPerThread = ((WORLD_HEIGHT * WORLD_WIDTH) / TOTAL_THREADS) * threadID; // Get the total number of rows each thread needs to handle.

	for (x = rowsPerThread; x < WORLD_WIDTH; x++)
	{
		for (y = rowsPerThread; y < WORLD_HEIGHT; y++)
		{
			WORLD_ARRAY[x][y] = getRandomState();
		}
	}
}

// Takes the given 2D array and populates each index with a random cell state.
void populateWorld()
{
	long thread;
	pthread_t *allThreads; // Define pointer to contain all threads.

	allThreads = malloc(TOTAL_THREADS * sizeof(pthread_t)); // Assign threads to pointer.

	// Assign eaceh thread to function.
	for (thread = 0; thread < TOTAL_THREADS; thread++)
	{
		pthread_create(&allThreads[thread], NULL, thread_populateWorld, (void *) thread);
	}

	for (thread = 0; thread < TOTAL_THREADS; thread++)
	{
		pthread_join(allThreads[thread], NULL);
	}

	free(allThreads); // Free thread allocations.
}