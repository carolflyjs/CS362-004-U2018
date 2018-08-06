#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "rngs.h"

void testSmithyEffect(){
	
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

	if (!cardEffect(smithy, choice1, choice2, choice3, state, handPos, &bonus)
		&& state->handCount[0] - tempState->handCount[0] + 1  == 3)
		printf("smithyEffect(): PASS when 3 cards are drawn\n");
	else
		printf("smithyEffect(): FAIL when 3 cards are drawn\n");

	// test if discard pile is shuffled when empty
	initializeGame(4, kingdomCards, 6, state);
	state->deckCount[0] = 1;
	state->deck[0][0] = gardens;
	state->discardCount[0] = 10;
	state->discard[0][9] = copper;
	state->discard[0][8] = copper;
	state->discard[0][7] = estate;
	state->discard[0][6] = province;
	state->discard[0][5] = council_room;
	state->discard[0][4] = village;
	state->discard[0][3] = minion;
	state->discard[0][2] = curse;
	state->discard[0][1] = sea_hag;
	state->discard[0][0] = smithy;
	*tempState = *state;
	
	if (!cardEffect(smithy, choice1, choice2, choice3, state, handPos, &bonus)
		&& state->discardCount[0] == 0)
		printf("smithyEffect(): PASS when discard pile is shuffled when deck is empty\n");
	else
		printf("smithyEffect(): FAIL when discard pile is shuffled when deck is empty\n");
	
	// test if last card in deck is drawn (use same state as before)
	if (state->hand[0][5] == gardens)
		printf("smithyEffect(): PASS when card is drawn before deck becomes empty\n");
	else
		printf("smithyEffect(): FAIL when card is drawn before deck becomes empty\n");


	// test if deck is added to hand correctly
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

	if(!cardEffect(smithy, choice1, choice2, choice3, state, handPos, &bonus)
		&& state->hand[0][5] == copper
		&& state->hand[0][6] == copper
		&& state->hand[0][7] == estate)
		printf("smithyEffect(): PASS when deck is added to hand correctly\n");
	else
		printf("smithyEffect(): FAIL when deck is added to hand correctly\n");

	// test if smithy is discarded
	if (state->hand[0][handPos] != smithy
	)	
		printf("smithyEffect(): PASS when smithy is discarded\n");
	else
		printf("smithyEffect(): FAIL when smithy is discarded\n");
	
	// test if action unchanged
	if (tempState->numActions - state->numActions == 0)
		printf("smithyEffect(): PASS when number of action unchanged\n");
	else
		printf("smithyEffect(): FAIL when number of action unchanged\n");
	
	// test if buy remains the same
	if (tempState->numBuys - state->numBuys == 0)
		printf("smithyEffect(): PASS when number of buys unchanged\n");
	else
		printf("smithyEffect(): FAIL when number of buys unchanged\n");
	
}

int main(){
	testSmithyEffect();
	return 0;
}
