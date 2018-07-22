#include <stdio.h>
#include "rngs.h"
#include "assert.h"
#include "gameSet.h"
#include "dominion.h"
#include <string.h>
#include <stdlib.h>

/***********************
 * For testing purpose
 * *********************/

struct gameData* buildGameData() {
	struct gameData* myData = (struct gameData *) malloc(sizeof(struct gameData));
	const int cards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	memcpy((int*)myData->kingdomCards, (const int*) cards, sizeof(cards));
	myData->seed = 5;
	myData->numPlayers = 3;
	
	myData->state = (struct gameState *) malloc (sizeof(struct gameState));
	return myData;
}
