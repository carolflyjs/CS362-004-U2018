#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include <string.h>

void testBuyCard(){
	

	struct gameState *state = (struct gameState *) malloc (sizeof(struct gameState));

	state->numBuys = 0;
	if (buyCard(adventurer, state) == -1)
		printf("buyCard(): PASS when no buy is left\n");
	else
		printf("buyCard(): FAIL when no buy is left\n");
		
	state->numBuys = 1;
	state->supplyCount[adventurer] = 0;
	if (buyCard(adventurer, state) == -1)
		printf("buyCard(): PASS when no supply is left\n");
	else
		printf("buyCard(): FAIL when no supply is left\n");

	state->numBuys = 1;
	state->coins = 2;
	state->supplyCount[adventurer] = 1;
	if (buyCard(adventurer, state) == -1)
		printf("buyCard(): PASS when not enough coin to buy\n");
	else
		printf("buyCard(): FAIL when not enough coin to buy\n");

	state->numBuys = 1;
	state->coins = 6;
	state->supplyCount[adventurer] = 1;
	state->whoseTurn = 0;
	if (buyCard(adventurer, state) == 0
		&& state->coins == 0
		&& state->numBuys == 0
		&& state->supplyCount[adventurer] == 0
		&& state->discard[0][state->discardCount[0]-1] == adventurer)
		printf("buyCard(): PASS when buy is successful\n");
	else
		printf("buyCard(): FAIL when buy is successful\n");



}


int main(){
	testBuyCard();
	return 0;
}
