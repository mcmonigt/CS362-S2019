#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

// testing actionSmithy case statement within cardEffect function
int main(){
  int player1 = 0;
  int handPos = 2;
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

  //testing cardEffect
  int i;
  int marker = 0;
  for (i = 1; i <= 10; i++){
    cardEffect(smithy, choice1, choice2, choice3, game1, handPos, bonus);
    int j;
    //discards 4 cards from hand and adds 4 to deck to make sure theres enought to draw again
    for (j = 0; j < 4; j++){
      discardCard(handPos, player1, game1, 0);
      gainCard(i, game1, 1, player1);

    }
    printf("player 0 should have %d in hand and has %d\n", (5+(i*4)), game1->handCount[player1]);
    if (game1->handCount[player1] != 5 + (i*4)){
      marker++;
    }
  }
  if (marker == 0){
    printf("All test passed cardtest2\n");
  }
  else {
    printf("cardtest2 failed %d out of 10 tests\n", marker);
  }
  return 0;
}
