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
	
	// test if player can exchange copper with gold

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
	state->hand[0][0] = mine;
	state->hand[0][1] = copper;
	state->hand[0][2] = minion;
	state->hand[0][3] = silver;
	state->hand[0][4] = gold;
	*tempState = *state;
	
	if (cardEffect(mine, 1, gold, choice3, state, handPos, &bonus) == -1)
		printf("testMine(): PASS when player wants to exchange copper with gold\n");
	else
		printf("testMine(): FAIL when player wants to exchange copper with gold\n");

	// test if player can exachange silver with gold

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
	state->hand[0][0] = mine;
	state->hand[0][1] = copper;
	state->hand[0][2] = minion;
	state->hand[0][3] = silver;
	state->hand[0][4] = gold;
	*tempState = *state;
	
	if (cardEffect(mine, 1, silver, choice3, state, handPos, &bonus) == 0)
		printf("testMine(): PASS when player wants to exchange copper with silver\n");
	else
		printf("testMine(): FAIL when player wants to exchange copper with silver\n");

	// test if players can exchange copper with silver
	
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
	state->hand[0][0] = mine;
	state->hand[0][1] = copper;
	state->hand[0][2] = minion;
	state->hand[0][3] = silver;
	state->hand[0][4] = gold;
	*tempState = *state;
	
	if (cardEffect(mine, 3, gold, choice3, state, handPos, &bonus) == 0)
		printf("testMine(): PASS when player wants to exchange silver with gold\n");
	else
		printf("testMine(): FAIL when player wants to exchange silver with gold\n");
	
	// test if numActions unchanged
	if (state->numActions == tempState->numActions)
		printf("testMine(): PASS when num of actions unchanged\n");
	else
		printf("testMine(): FAIL when num of actions unchanged\n");

	// test if numBuys unchanged
	if (state->numBuys == tempState->numBuys)
		printf("testMine(): PASS when num of buys unchanged\n");
	else
		printf("testMine(): FAIL when num of buys unchanged\n");

	// test if gained card added to hand
	if (state->hand[0][5] == gold)
		printf("testMine(): PASS when gained card added to hand\n");
	else
		printf("testMine(): FAIL when gained card added to hand\n");

	// test if discard pile unchanged
	if (state->discardCount[0] == tempState->discardCount[0])
		printf("testMine(): PASS when discard pile unchanged\n");
	else
		printf("testMine(): FAIL when discard pile unchanged\n");
	
	// test if deck pile unchanged
	if (state->deckCount[0] == tempState->deckCount[0])
		printf("testMine(): PASS when deck pile unchanged\n");
	else
		printf("testMine(): FAIL when deck pile unchanged\n");
	

	// test if players can exchange a non-treasure card

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
	state->hand[0][0] = mine;
	state->hand[0][1] = copper;
	state->hand[0][2] = minion;
	state->hand[0][3] = silver;
	state->hand[0][4] = gold;
	*tempState = *state;
	
	if (cardEffect(mine, 2, gold, choice3, state, handPos, &bonus) == -1)
		printf("testMine(): PASS when player wants to exchange non-Treasure card\n");
	else
		printf("testMine(): FAIL when player wants to exchange non-Treasure card\n");

	
}


int main(){
	testMine();
	return 0;
}
