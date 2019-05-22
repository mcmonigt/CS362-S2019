#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "rngs.h"

int checkSmithyCard(struct gameState* game1, int currentPlayer){
  struct gameState game2;
  memcpy(&game2, game1, sizeof(struct gameState));
  // calls actionSmithy function for one copy of the gameState
  actionSmity(currentPlayer, game1, 0);
  // manually does what actionSmithy function should do
  int i;
  for (i = 0; i < 3; i++){
    drawCard(currentPlayer, &game2);
  }
  discardCard(0, currentPlayer, &game2, 0);
  // checks if both gameStates are the same
  assert(memcmp(&game2, game1, sizeof(struct gameState)) == 0);
  return 0;
}

int main(){
  // initializes random generation of numbers
  SelectStream(2);
  PutSeed(3);

  struct gameState game1;
  int j, p, i;
  for (i = 0; i < 2000; i++){
    for (j = 0; j < sizeof(struct gameState); j++){
      ((char*)&game1)[j] = floor(Random() * 256);
    }
    p = floor(Random() * 2);
    // makes sure there's at least three cards in the deck
    game1.deckCount[p] = floor(Random() * (MAX_DECK - 3)) + 3;
    // sets discardCount to a random number less than three less than MAX to allow space for drawing 3 cards
    game1.discardCount[p] = floor(Random() * (MAX_DECK - 3));
    // makes sure there's space to draw three cards
    game1.handCount[p] = floor(Random() * (MAX_HAND - 3));
    // makes sure there's at least one space for discardCard function
    game1.playedCardCount = floor(Random() * (MAX_HAND - 1));

    checkSmithyCard(&game1, p);

  }
  printf("All tests passed for randomtestadventurer\n");
  return 0;
}
