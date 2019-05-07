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
  // arbitratily chose card #3 in the array as the handPos argument
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

  // performing functionality of actionSmithy with game1
  int i;
  for (i = 0; i < 3; i++){
    drawCard(player1, game1);
  }
  discardCard(handPos, player1, game1, 0);

  // call actionSmithy using game2
  actionSmithy(player1, game2, handPos);

  // compare results
  if (game1->handCount[player1] != game2->handCount[player1]){
    printf("Test failed unittest2: wrong number of cards in hand after calling actionSmithy\n");
  }
  else {
    printf("Test passed for unittest2\n");
  }
  return 0;

}
