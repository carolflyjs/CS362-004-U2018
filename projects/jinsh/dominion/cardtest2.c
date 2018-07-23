#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "rngs.h"

void testAdventurer(){
	
	struct gameState *state = (struct gameState *) malloc (sizeof(struct gameState));
	int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	initializeGame(4, kingdomCards, 6, state);
	int choice1 = -1;
	int choice2 = -1;
	int choice3 = -1;
	int handPos = 0;

	struct gameState *tempState = (struct gameState *) malloc (sizeof(struct gameState));
	
	*tempState = *state;
	


}

int main(){
	testAdventurer();
	return 0;
}
