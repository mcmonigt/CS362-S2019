#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "rngs.h"

int checkAdventureCard(struct gameState* game1, int currentPlayer){
  struct gameState game2;
  memcpy(&game2, game1, sizeof(struct gameState));
  //calls actionAdventurer function for one copy of gameState
  int temphand2[MAX_HAND];
  int z = 0;
  AdventurerFunction(0, game1, currentPlayer, temphand2, z);
  // manually does what actionAdventurer function should do
  int temphand[MAX_HAND];
  int drawntreasure = 0;
  z = 0;
  while (drawntreasure < 2){
    if (game2.deckCount[currentPlayer] <1){
      shuffle(currentPlayer, &game2);
    }
    drawCard(currentPlayer, &game2);
    int cardDrawn = game2.hand[currentPlayer][game2.handCount[currentPlayer]-1];
    if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
      drawntreasure++;
    else{
      temphand[z]=cardDrawn;
      game2.handCount[currentPlayer]--;
      z++;
    }
  }
  while(z-1>=0){
    game2.discard[currentPlayer][game2.discardCount[currentPlayer]++]=temphand[z-1];
    z=z-1;
  }
  // checking if both gameStates are the same
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
    // makes sure there's at least two cards in the deck
    game1.deckCount[p] = floor(Random() * (MAX_DECK - 2)) + 2;
    // initializes discardCount to zero to avoid going over MAX_HAND value in array
    game1.discardCount[p] = 0;
    game1.handCount[p] = floor(Random() * (MAX_HAND - 2));
    // adding treasures to random positions in the deck to make sure there's some in there
    game1.deck[p][game1.deckCount[p] - 1] = 5;
    game1.deck[p][game1.deckCount[p] - 2] = 5;
    game1.deck[p][game1.deckCount[p] - 3] = 5;
    game1.deck[p][game1.deckCount[p] - (int)(Random() * game1.deckCount[p])] = 5;
    game1.deck[p][game1.deckCount[p] - (int)(Random() * game1.deckCount[p])] = 5;
    game1.deck[p][game1.deckCount[p] - (int)(Random() * game1.deckCount[p])] = 5;
    game1.deck[p][game1.deckCount[p] - (int)(Random() * game1.deckCount[p])] = 5;
    checkAdventureCard(&game1, p);

  }
  printf("All tests passed for randomtestadventurer\n");
  return 0;
}
