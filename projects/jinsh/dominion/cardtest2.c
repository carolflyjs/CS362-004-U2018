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
		&& state->handCount[0] == 7)
		printf("testAdventurer(): PASS when cards are drawn until two Treansures are revealed\n");
	else
		printf("testAdventurer(): FAIL when cards are drawn until two Treansures are revealed\n");
	
	// test if the other revealed cards are discarded
	if (state->discard[0][0] == estate
		&& state->discard[0][1] == village
		&& state->discard[0][2] == province
		&& state->discard[0][3] == council_room)
		printf("testAdventurer(): PASS when revealed non-Treausre cards are discarded\n");
	else
		printf("testAdventurer(): FAIL when revealed non-Treausre cards are discarded\n");

  	// test if cards are not shuffled when not empty
	initializeGame(4, kingdomCards, 6, state);
	state->deckCount[0] = 4;
	state->deck[0][3] = copper;
	state->deck[0][2] = estate;
	state->deck[0][1] = village;
	state->deck[0][2] = silver;
	if (!cardEffect(adventurer, choice1, choice2, choice3, state, handPos, &bonus)
		&& state->deckCount[0] == 0)
		printf("testAdventurer(): PASS when deck is empty after second Treasure is end of deck\n");
	else	
		printf("testAdventurer(): FAIL when deck is empty after second Treasure is end of deck\n");

	// test if cards are shuffled when empty
	initializeGame(4, kingdomCards, 6, state);
	state->deckCount[0] = 3;
	state->deck[0][2] = estate;
	state->deck[0][1] = village;
	state->deck[0][2] = silver;
	state->discardCount[0] = 3;
	state->discard[0][0] = gold;
	state->discard[0][1] = gardens;
	state->discard[0][2] = council_room;
	if (!cardEffect(adventurer, choice1, choice2, choice3, state, handPos, &bonus)
		&& state->discardCount[0] == 0)
		printf("testAdventurer(): PASS when cards are shuffled when empty\n");
	else
		printf("testAdventurer(): FAIL when cards are shuffled when empty\n");
	
	// test if two treasure cards are added to hand
	if (state->hand[0][5] == silver 
		&& state->hand[0][6] == gold)
		printf("testAdventurer(): PASS when two treausre cards are added to hand\n");
	else
		printf("testAdventurer(): FAIL when two treasure cards are added to hand\n");
	
	// test if num of actions unchanged
	if (state->numActions == tempState->numActions)
		printf("testAdventurer(): PASS when num of actions unchaged\n");
	else
		printf("testAdventurer(): FAIL when num of actions unchaged\n");
	
	// test if num of buys unchanged
	if (state->numBuys == tempState->numBuys)
		printf("testAdventurer(): PASS when num of buys unchaged\n");
	else
		printf("testAdventurer(): FAIL when num of buys unchaged\n");
}

int main(){
	testAdventurer();
	return 0;
}
