#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "rngs.h"

void testCouncilRoom(){
	
	struct gameState *state = (struct gameState *) malloc (sizeof(struct gameState));
	int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int bonus = 0;
	int handPos = 0;
	int choice1 = -1;
	int choice2 = -1;
	int choice3 = -1;

	struct gameState *tempState = (struct gameState *) malloc (sizeof(struct gameState));
	
	// test if 4 cards are drawn

	initializeGame(4, kingdomCards, 6, state);
	state->deckCount[0] = 10;
	state->deck[0][9] = copper;
	state->deck[0][8] = silver;
	state->deck[0][7] = estate;
	state->deck[0][6] = province;
	state->deck[0][5] = gardens;
	state->deck[0][4] = village;
	state->deck[0][3] = minion;
	state->deck[0][2] = curse;
	state->deck[0][1] = sea_hag;
	state->deck[0][0] = smithy;
	state->discardCount[0] = 2;
	state->discard[0][0] = silver;
	state->discard[0][1] = province;
	
	*tempState = *state;
	

	if (!cardEffect(council_room, choice1, choice2, choice3, state, handPos, &bonus)
		&& state->handCount[0] == 8)
		printf("testCouncilRoom(): PASS when four cards are drawn\n");
	else
		printf("testCouncilRoom(): FAIL when four cards are drawn\n");
	
	// test if 4 cards are added to hand
	if (state->hand[0][5] == copper
		&& state->hand[0][6] == silver
		&& state->hand[0][7] == estate
		&& state->hand[0][8] == province)
		printf("testCouncilRoom(): PASS when four cards on the top of deck are added to hands\n");
	else
		printf("testCouncilRoom(): FAIL when four cards on the top of deck are added to hands\n");
		
	// test if num of actions unchanged
	if (state->numActions == tempState->numActions)
		printf("testCouncilRoom(): PASS when num of actions unchanged\n");
	else
		printf("testCouncilRoom(): FAIL when num of actions unchanged\n");

	// test if num of buys increased
	if (state->numBuys == tempState->numBuys + 1)
		printf("testCouncilRoom(): PASS when num of buys increased by one\n");
	else
		printf("testCouncilRoom(): FAIL when num of buys increased by one\n");
	
	// test if council room is discarded
	if (state->hand[0][handPos] != council_room)
		printf("testCouncilRoom(): PASS when council room is discarded\n");
	else
		printf("testCouncilRoom(): FAIL when council room is discarded\n");
	
	// test if discard piles are not shullfed when not needed
	if (state->discardCount[0] != 0)
		printf("testCouncilRoom(): PASS when discard pileis not shuffled when not needed\n");
	else
		printf("testCouncilRoom(): FAIL when discard pileis not shuffled when not needed\n");

	// test if discard piles are shuffled when needed
	initializeGame(4, kingdomCards, 6, state);
	state->deckCount[0] = 3;
	state->deck[0][2] = copper;
	state->deck[0][1] = silver;
	state->deck[0][0] = estate;
	state->discardCount[0] = 7;
	state->discard[0][6] = province;
	state->discard[0][5] = gardens;
	state->discard[0][4] = village;
	state->discard[0][3] = minion;
	state->discard[0][2] = curse;
	state->discard[0][1] = sea_hag;
	state->discard[0][0] = smithy;
	*tempState = *state;
	

	if (!cardEffect(council_room, choice1, choice2, choice3, state, handPos, &bonus)
	&& state->discardCount[0] == 0)
		printf("testCouncilRoom(): PASS when discard pile is shuffled when needed\n");
	else
		printf("testCouncilRoom(): FAIL when discard pile is shuffled when needed\n");

	if (state->handCount[1] - tempState->handCount[1] == 1
		&& state->handCount[2] - tempState->handCount[2] == 1
		&& state->handCount[3] - tempState->handCount[3] == 1)
		printf("testCouncilRoom(): PASS when all other players gain a card\n");
	else
		printf("testCouncilRoom(): FAIL when all other players gain a card]n");
}

int main(){
	testCouncilRoom();
	return 0;
}
