#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "rngs.h"

int checkCouncil_room(struct gameState* game1, int currentPlayer){
  struct gameState game2;
  int handPos = 0;
  memcpy(&game2, game1, sizeof(struct gameState));
  actionCouncil_room(currentPlayer, game1, handPos);
  // manually does actionAdventurer card expected functionality
  int i;
  for (i = 0; i < 4; i++){
    drawCard(currentPlayer, &game2);
  }

  //+1 Buy
  // Bug
  game2.numBuys++;

  //Each other player draws a card
  for (i = 0; i < game2.numPlayers; i++){
    if ( i != currentPlayer ){
      drawCard(i, &game2);
    }
  }
  //put played card in played card pile
  discardCard(handPos, currentPlayer, &game2, 0);
  // asserts if function worked as it should
  assert(memcmp(&game2, game1, sizeof(struct gameState)) == 0);
  return 0;
}

int main(){
  // initializes random generation of numbers
  SelectStream(2);
  PutSeed(3);

  struct gameState game1;
  int j, p, i, k;
  for (i = 0; i < 2000; i++){
    for (j = 0; j < sizeof(struct gameState); j++){
      ((char*)&game1)[j] = floor(Random() * 256);
    }
    p = 1;
    game1.numPlayers = 2;
    for (k = 0; k < 2; k++){
      // makes sure there's at least 4 cards to draw from the deck
      game1.deckCount[k] = floor(Random() * (MAX_DECK - 4)) + 4;
      game1.discardCount[k] = floor(Random() * MAX_DECK);
      // makes sure there's enough space in hand to draw cards
      game1.handCount[k] = floor(Random() * (MAX_HAND - 4));
    }
    game1.playedCardCount = floor(Random() * MAX_DECK);
    checkCouncil_room(&game1, p);

  }
  printf("All tests passed randomtestcard1\n");
  return 0;
}
