#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

// World Definitions
#define WORLD_HEIGHT 10 // World height.
#define WORLD_WIDTH  10 // World width.
#define GENERATIONS  10 // Number of generations to complete.

// Cell States
#define CELL_EMPTY			0
#define CELL_HEALTHY		1
#define CELL_INFECTED		2
#define CELL_DEAD			3
#define CELL_INVULNERABLE	4

// Function declarations.
void populateWorld(); // populateWorld.c
int getRandomState(); // getRandomState.c
int getInvulnerableProbability(); // getRandomState.c
void nextGeneration(int currentGeneration); // generate.c
int updateCellStatus(int x, int y); // cellStatus.c

// Global variable declarations.
int WORLD_ARRAY[WORLD_HEIGHT][WORLD_WIDTH]; // Array that contains all cell states.
int NEXT_GENERATION[WORLD_HEIGHT][WORLD_WIDTH]; // Array to temporarily hold next generation's cell states.