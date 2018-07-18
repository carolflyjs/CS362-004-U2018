#ifndef GAMESET_H
#define GAMESET_H
#include "rngs.h"
#include "dominion.h"

struct gameData {
	struct gameState* state;
	int kindomCards[10];
	int seed;
	struct numPlayers;
};

#endif
