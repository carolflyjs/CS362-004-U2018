#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "rngs.h"

void testMine(){
	
	struct gameState *state = (struct gameState *) malloc (sizeof(struct gameState));
	int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int bonus = 0;
	int handPos = 0;
	int choice1 = -1;
	int choice2 = -1;
	int choice3 = -1;

	struct gameState *tempState = (struct gameState *) malloc (sizeof(struct gameState));
	
	// test if 3 cards are drawn

	initializeGame(4, kingdomCards, 6, state);
	state->deckCount[0] = 10;
	state->deck[0][9] = copper;
	state->deck[0][8] = copper;
	state->deck[0][7] = estate;
	state->deck[0][6] = province;
	state->deck[0][5] = council_room;
	state->deck[0][4] = village;
	state->deck[0][3] = minion;
	state->deck[0][2] = curse;
	state->deck[0][1] = sea_hag;
	state->deck[0][0] = smithy;
	*tempState = *state;

}

int main(){
	testMine();
	return 0;
}
