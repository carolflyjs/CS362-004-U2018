#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "gameSet.h"
#include <string.h>

void testIsGameOver(){
	

	struct gameState *state = (struct gameState *) malloc (sizeof(struct gameState));

	state->supplyCount[province] = 0;
	if (isGameOver(state))
		printf("testIsGameOver(): PASS when no province is left\n");
	else
		printf("testIsGameOver(): FAIL when no province is left\n");
	
	state->supplyCount[province] = 3;
	state->supplyCount[adventurer] = 0;
	state->supplyCount[gold] = 0;
	state->supplyCount[gardens] = 0;
	if (isGameOver(state))
		printf("testIsGameOver(): PASS when no three piles are empty\n");
	else
		printf("testIsGameOver(): PASS when no three piles are empty\n");


}


int main(){
	testIsGameOver();
	return 0;
}
