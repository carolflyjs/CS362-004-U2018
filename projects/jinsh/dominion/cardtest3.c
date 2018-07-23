#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "rngs.h"

void testSmithy(){
	
	struct gameState *state = (struct gameState *) malloc (sizeof(struct gameState));
	int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	initializeGame(4, kingdomCards, 6, state);

	struct gameState *tempState = (struct gameState *) malloc (sizeof(struct gameState));
	
	*tempState = *state;

}

int main(){
	testSmithy();
	return 0;
}
