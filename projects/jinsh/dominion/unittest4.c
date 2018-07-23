#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include <string.h>

void testIsGameOver(){
	

	struct gameState *state = (struct gameState *) malloc (sizeof(struct gameState));
	int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
 
  initializeGame(3, kingdomCards, 6, state);
  if (!isGameOver(state))
    printf("testIsGameOver(): PASS when game is not over\n");
	else
		printf("testIsGameOver(): FAIL when game is not over\n");
  
	state->supplyCount[province] = 0;
	if (isGameOver(state))
		printf("testIsGameOver(): PASS when no province is left\n");
	else
		printf("testIsGameOver(): FAIL when no province is left\n");

	state->supplyCount[province] = 3;
	state->supplyCount[adventurer] = 0;
	state->supplyCount[gold] = 0;
	if (!isGameOver(state))
		printf("testIsGameOver(): PASS when two piles are empty\n");
	else
		printf("testIsGameOver(): PASS when two piles are empty\n");
  
  state->supplyCount[gardens] = 0;
  if (isGameOver(state))
		printf("testIsGameOver(): PASS when three piles are empty\n");
	else
		printf("testIsGameOver(): PASS when three piles are empty\n");

  

}


int main(){
	testIsGameOver();
	return 0;
}
