#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "rngs.h"

void testAdventurer(){
	
	struct gameState *state = (struct gameState *) malloc (sizeof(struct gameState));
	int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int bonus = 0;
	int handPos = 0;
	int choice1 = -1;
	int choice2 = -1;
	int choice3 = -1;

	struct gameState *tempState = (struct gameState *) malloc (sizeof(struct gameState));
	
	// test if drawn until two treasures are revealed

	initializeGame(4, kingdomCards, 6, state);
	state->deckCount[0] = 10;
	state->deck[0][9] = copper;
	state->deck[0][8] = estate;
	state->deck[0][7] = village;
	state->deck[0][6] = province;
	state->deck[0][5] = council_room;
	state->deck[0][4] = copper;
	state->deck[0][3] = minion;
	state->deck[0][2] = curse;
	state->deck[0][1] = sea_hag;
	state->deck[0][0] = smithy;
	*tempState = *state;

	if (!cardEffect(adventurer, choice1, choice2, choice3, state, handPos, &bonus)
		&& state->handCount[0] == 10)
		
  
}

int main(){
	testAdventurer();
	return 0;
}
