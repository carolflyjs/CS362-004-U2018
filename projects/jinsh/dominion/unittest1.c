#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include <string.h>

void testInitGame(){
	
	int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int badKingdomCards[10] = {adventurer, adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute};
  	int seed = 2;
	int numPlayers1 = 1;
	int numPlayers2 = 2;
	int numPlayers3 = 3;
	int numPlayers4 = 4;
	int numPlayers5 = 5;
	struct gameState *state = (struct gameState *) malloc (sizeof(struct gameState));
	
	if (initializeGame(numPlayers1, kingdomCards, seed, state) == -1)
		printf("initializeGame(): PASS when test containing 1 player\n");
	else
		printf("initializeGame(): FAIL when test containing 1 player\n");
  
	if (initializeGame(numPlayers5, kingdomCards, seed, state) == -1)
		printf("initializeGame(): PASS when test containing 5 players\n");
	else
		printf("initializeGame(): FAIL when test containing 5 players\n");
  	
  	if (initializeGame(numPlayers2, badKingdomCards, seed, state) == -1)
		printf("initializeGame(): PASS when kingdom cards not unique\n");
	else
		printf("initializeGame(): FAIL when kingdom cards not unique\n");


	if (initializeGame(numPlayers2, kingdomCards, seed, state) == 0
		&& state->supplyCount[curse] == 10
		&& state->supplyCount[estate] == 8
		&& state->supplyCount[duchy] == 8
		&& state ->supplyCount[province] == 8
		&& state->supplyCount[copper] == 60 - 7 * numPlayers2
		&& state->supplyCount[silver] == 40
		&& state->supplyCount[gold] == 30
		&& state->supplyCount[adventurer] == 10
		&& state->supplyCount[gardens] == 8
		&& state->supplyCount[embargo] == 10
		&& state->supplyCount[village] == 10
		&& state->supplyCount[minion] == 10
		&& state->supplyCount[mine] == 10
		&& state->supplyCount[cutpurse] == 10
		&& state->supplyCount[sea_hag] == 10
		&& state->supplyCount[tribute] == 10
		&& state->supplyCount[smithy] == 10
		)
		printf("initializeGame(): PASS when supply cards correct for 2 players\n");
	else
		printf("initializeGame(): FAIL when supply cards incorrect for 2 players\n");

	if (initializeGame(numPlayers3, kingdomCards, seed, state) == 0
		&& state->supplyCount[curse] == 20
		&& state->supplyCount[estate] == 12
		&& state->supplyCount[duchy] == 12
		&& state ->supplyCount[province] == 12
		&& state->supplyCount[copper] == 60 - 7 * numPlayers3
		&& state->supplyCount[silver] == 40
		&& state->supplyCount[gold] == 30
		&& state->supplyCount[adventurer] == 10
		&& state->supplyCount[gardens] == 12
		&& state->supplyCount[embargo] == 10
		&& state->supplyCount[village] == 10
		&& state->supplyCount[minion] == 10
		&& state->supplyCount[mine] == 10
		&& state->supplyCount[cutpurse] == 10
		&& state->supplyCount[sea_hag] == 10
		&& state->supplyCount[tribute] == 10
		&& state->supplyCount[smithy] == 10
		)
		printf("initializeGame(): PASS when supply cards correct for 3 players\n");
	else
		printf("initializeGame(): FAIL when supply cards incorrect for 3 players\n");

	if (initializeGame(numPlayers4, kingdomCards, seed, state) == 0
		&& state->supplyCount[curse] == 30
		&& state->supplyCount[estate] == 12
		&& state->supplyCount[duchy] == 12
		&& state->supplyCount[province] == 12
		&& state->supplyCount[copper] == 60 - 7 * numPlayers4
		&& state->supplyCount[silver] == 40
		&& state->supplyCount[gold] == 30
		&& state->supplyCount[adventurer] == 10
		&& state->supplyCount[gardens] == 12
		&& state->supplyCount[embargo] == 10
		&& state->supplyCount[village] == 10
		&& state->supplyCount[minion] == 10
		&& state->supplyCount[mine] == 10
		&& state->supplyCount[cutpurse] == 10
		&& state->supplyCount[sea_hag] == 10
		&& state->supplyCount[tribute] == 10
		&& state->supplyCount[smithy] == 10
		)
		printf("initializeGame(): PASS when supply cards correct for 4 players\n");
	else
		printf("initializeGame(): FAIL when supply cards incorrect for 4 players\n");

	if (initializeGame(numPlayers2, kingdomCards, seed, state) == 0
		&& state->handCount[0] == 5
		&& state->handCount[1] == 0
		&& state->discardCount[0] == 0
		&& state->discardCount[1] == 0
		&& state->outpostPlayed == 0
		&& state->phase == 0
		&& state->numActions == 1
		&& state->playedCardCount == 0
		&& state->whoseTurn == 0
		)
		printf("initializeGame(): PASS when player hands correct for 2 players\n");
	else
		printf("initializeGame(): FAIL when player hands incorrect for 2 players\n");
	
	if (initializeGame(numPlayers3, kingdomCards, seed, state) == 0
		&& state->handCount[0] == 5
		&& state->handCount[1] == 0
		&& state->handCount[2] == 0
		&& state->discardCount[0] == 0
		&& state->discardCount[1] == 0
		&& state->discardCount[2] == 0 
		)
		printf("initializeGame(): PASS when player hands correct for 3 players\n");
	else
		printf("initializeGame(): FAIL when player hands incorrect for 3 players\n");
	
	if (initializeGame(numPlayers4, kingdomCards, seed, state) == 0
		&& state->handCount[0] == 5
		&& state->handCount[1] == 0
		&& state->handCount[2] == 0
		&& state->handCount[3] == 0
		&& state->discardCount[0] == 0
		&& state->discardCount[1] == 0
		&& state->discardCount[2] == 0 
		&& state->discardCount[3] == 0 
		)
		printf("initializeGame(): PASS when player hands correct for 4 players\n");
	else
		printf("initializeGame(): FAIL when player hands incorrect for 4 players\n");
	
}

int main(){
	testInitGame();
	return 0;
}
