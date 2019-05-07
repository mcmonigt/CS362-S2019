#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

// testing actionAdventurer case statement within cardEffect funct
int main(){
  struct gameState* game1 = newGame();
  int game_initialized;
  int cards[10] = { adventurer, village, smithy, council_room, feast, gardens, mine, minion, treasure_map };
  game_initialized = initializeGame(2, cards, 3, game1);
  if (game_initialized != 0){
    printf("game not intialized correctly\n");
    exit(1);
  }
  // dummy variables not used but needed to be initialized for cardEffect
  int choice1 = 0;
  int choice2 = 0;
  int choice3 = 0;
  int bonus[2] = {0 , 1};
  int handPos = 3;

  //testing cardEffect
  int i;
  int marker = 0;
  for (i = 1; i <= 10; i++){
    cardEffect(adventurer, choice1, choice2, choice3, game1, handPos, bonus);
    //adds treasure and another card to the players deck so it doesnt empty
    gainCard(4, game1, 1, 0);
    gainCard(i, game1, 1, 0);
    // printf("player 0 deck %d cards\n", game1->deckCount[0]);
    printf("player 0 should have %d cards in hand and has %d\n", (5 + (2*i)), game1->handCount[0]);
    if (game1->handCount[0] != (5 + (2*i))){
      marker++;
    }
  }
  if (marker == 0){
    printf("All tests passed cardtest1\n");
  }
  else {
    printf("%d out of 10 test failed cardtest1\n", marker);
  }
  return 0;
}
