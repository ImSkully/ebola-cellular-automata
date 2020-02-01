#include "header.h"

// Function which takes a cell's index within the World Array and returns its new state.
/*
	[RULES]
		1. If cell is empty, do nothing.
		2. If cell is invulnerable, do nothing.
		3. If cell is dead, make it empty.
		4. If cell is healthy and has 3 infected neighbors or 1 dead neighbor, infect it.
		5. If cell is infected and has 9 healthy neighbors (and no dead or infected neighbors), make it invulnerable. (Cannot be infected twice!)
		6. If a cell is infected and has 4 infected neighbors (or 2 infected neighbors and 1 dead neighbor), kill it.
*/
int updateCellStatus(int x, int y)
{
	int thisCell = WORLD_ARRAY[x][y]; // The cells current state.

	// Rule 1 & Rule 2.
	if (thisCell == CELL_EMPTY || thisCell == CELL_INVULNERABLE) return thisCell;

	// Rule 3.
	if (thisCell == CELL_DEAD) return CELL_EMPTY;
	
	// Get the state of each of this cell's neighbors.
	int maxSize = WORLD_WIDTH; // Assuming the world is a square, just get one of the width for use as max size.

	int neighborCells[9]; // Neighboring cell table.
	/*
		[neighborCells Table Key]
			0 1 2
			3 4 5
			6 7 8
	*/
	
	// Top row cells.
	neighborCells[0] = WORLD_ARRAY[((maxSize + x) - 1) % maxSize][((maxSize + y) - 1) % maxSize];
	neighborCells[1] = WORLD_ARRAY[((maxSize + x) - 1) % maxSize][y];
	neighborCells[2] = WORLD_ARRAY[((maxSize + x) - 1) % maxSize][((maxSize + y) + 1) % maxSize];
	
	// Central row cells.
	neighborCells[3] = WORLD_ARRAY[x][((maxSize + y) - 1) % maxSize];
	neighborCells[4] = 10; // Give this index a random value because we don't want to use it.
	neighborCells[5] = WORLD_ARRAY[x][((maxSize + y) + 1) % maxSize];

	// Bottom row cells.
	neighborCells[6] = WORLD_ARRAY[((maxSize + x) + 1) % maxSize][((maxSize + y) - 1) % maxSize];
	neighborCells[7] = WORLD_ARRAY[((maxSize + x) + 1) % maxSize][y];
	neighborCells[8] = WORLD_ARRAY[((maxSize + x) % maxSize)][((maxSize + y) + 1) % maxSize];
	
	int totalHealthyNeighbors = 0; // Counter of how many neighbors are healthy.
	int totalInfectedNeighbors = 0; // Counter of how many neighbors are infected.
	int totalDeadNeighbors = 0; // Counter of how many neighbors are dead.

	// Summarize the state of all neighbors.
	for (int i = 0; i < 9; i++)
	{
		if (neighborCells[i] == CELL_HEALTHY) totalHealthyNeighbors++;
		else if(neighborCells[i] == CELL_INFECTED) totalInfectedNeighbors++;
		else if(neighborCells[i] == CELL_DEAD) totalDeadNeighbors++;
	}

	// Rule 4.
	if (thisCell == CELL_HEALTHY && totalInfectedNeighbors >= 3 || totalDeadNeighbors >= 1) return CELL_INFECTED;
	// Rule 5.
	if (thisCell == CELL_INFECTED && totalHealthyNeighbors >= 9) return getInvulnerableProbability();

	// Rule 6. If a cell is infected and has 4 infected neighbors (or 2 infected neighbors and 1 dead neighbor), kill it.	
	if (thisCell == CELL_INFECTED && totalInfectedNeighbors >= 4 || totalInfectedNeighbors >= 2 && totalDeadNeighbors >= 1) return CELL_DEAD;
}