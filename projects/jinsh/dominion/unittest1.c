#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "gameSet.h"


void testInitGame(){
	struct gameData * myData =  buildGameData();
	int numPlayers = myData->numPlayers;
	int kingdomCard[10];
  memcpy(kingdomCard, myData->kingdomCards, sizeof(kingdomCards));
  int seed = myData->seed;
  struct gameState* state = myData->state;
  
  //int initializeGame(int numPlayers, int kingdomCards[10], int randomSeed, struct gameState *state);
	initializeGame(numPlayers, kingdomCards, seed, state);
  
}

int main(){
	testInitGame();
	return 0;
}
