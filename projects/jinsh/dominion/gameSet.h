#ifndef GAMESET_H
#define GAMESET_H
#include "rngs.h"
#include "dominion.h"

struct gameData {
	struct gameState* state;
	int kingdomCards[10];
	int seed;
	int numPlayers;
};

#endif
