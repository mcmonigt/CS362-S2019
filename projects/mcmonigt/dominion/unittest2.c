#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

// Testing actionSmithy function
int main(){
  int player1 = 0;
  // arbitratily chose card number 3 in the array as the handPos argument
  int handPos = 3;
  struct gameState* game1 = newGame();
  struct gameState* game2 = newGame();
  int game_initialized;
  int cards[10] = { adventurer, village, smithy, council_room, feast, gardens, mine, minion, treasure_map };
  game_initialized = initializeGame(2, cards, 3, game1);
  if (game_initialized != 0){
    printf("game not intialized correctly\n");
    exit(1);
  }
  game_initialized = initializeGame(2, cards, 3, game2);
  if (game_initialized != 0){
    printf("game not intialized correctly\n");
    exit(1);
  }

  int i;
  int marker = 0;
  for (i = 1; i <= 10; i++){
    actionSmithy(player1, game1, handPos);
    int j;
    // discards 4 cards from hand and adds 4 cards to deck to make sure there's
    // enough cards to draw in actionSmithy function
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
