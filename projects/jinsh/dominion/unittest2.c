#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "gameSet.h"
#include <string.h>

void testUpdateCoins(){
	

	struct gameState *state = (struct gameState *) malloc (sizeof(struct gameState));

	state->numPlayers = 4;
	int combo0[5] = {copper, silver, adventurer, embargo, village};
	state->handCount[0] = 5;
	int combo1[4] = {gardens, minion, smithy, gold};
	state->handCount[1] = 4;	
	int combo2[5] = {mine, minion, copper, copper, copper};
	state->handCount[2] = 5;
	int combo3[0] = {};
	state->handCount[3] = 0;
	int i;
	for (i = 0; i < 5; i++) {
		state->hand[0][i] = combo0[i];
		state->hand[1][i] = combo1[i];
		state->hand[2][i] = combo2[i];
		state->hand[3][i] = combo3[i];
	}

	
	if (updateCoins(0, state, 0) == 0
		&& state->coins == 3)
		printf("updateCoins(): PASS when player has copper and silver\n");
	else
		printf("updateCoins(): FAIL when player has copper and silver\n");
	
	if (updateCoins(1, state, 0) == 0
		&& state->coins == 3)
		printf("updateCoins(): PASS when player has gold\n");
	else
		printf("updateCoins(): FAIL when player has gold\n");

	if (updateCoins(2, state, 2) == 0
		&& state->coins == 5)
		printf("updateCoins(): PASS when player has three coppers and bonus 2\n");
	else
		printf("updateCoins(): FAIL when player has three coppers and bonus 2\n");

	if (updateCoins(3, state, 0) == 0
		&& state->coins == 0)
		printf("updateCoins(): PASS when player has no card\n");
	else
		printf("updateCoins(): FAIL when player has no card\n");
}

int main(){
	testUpdateCoins();
	return 0;
}
