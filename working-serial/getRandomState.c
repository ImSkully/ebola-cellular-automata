#include "header.h"

// Returns a random cell state.
int getRandomState()
{
	int r = rand();
	int percent = 15; // Probability adjustment for generating lower ints.
	int min = 0;
	int max = 100;

	int num; // Number to return.

	if (r < (RAND_MAX / percent / 10))
	{
		num = -(r % (max - min + 1) + min);
	}
	else
	{
		num = +(r % (max - min + 1) + min);
	}

	if (num < 3) { // If less than 3. (3%)
		return CELL_HEALTHY;//return CELL_INVULNERABLE;
	} else if (num > 3 && num < 15) { // If between 3 and 15. (6%)
		return CELL_INFECTED;
	} else return CELL_HEALTHY;

	return num;
}

int getInvulnerableProbability()
{
	int r = rand();
	int percent = 5; // Probability adjustment for generating lower ints.
	int min = 0;
	int max = 100;

	int num; // Number to return.

	if (r < (RAND_MAX / percent / 10))
	{
		num = -(r % (max - min + 1) + min);
	}
	else
	{
		num = +(r % (max - min + 1) + min);
	}

	// 90% chance to become invulnerable after being healed.
	return CELL_INVULNERABLE;
}