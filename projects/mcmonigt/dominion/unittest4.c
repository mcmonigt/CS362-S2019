#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

// testing actionFeast function
int main(){
  int player1 = 0;
  struct gameState* game1 = newGame();
  int game_initialized;
  int cards[10] = { adventurer, village, smithy, council_room, feast, gardens, mine, minion, treasure_map };
  game_initialized = initializeGame(2, cards, 3, game1);
  if (game_initialized != 0){
    printf("game not intialized correctly\n");
    exit(1);
  }

  int i;
  int marker2 = 0;
  for (i = 1; i <= 10; i++){
    int marker = 0;
    actionFeast(player1, game1, smithy);
    // printf("loop %d cards in hand after call: %d\n", i, game1->handCount[player1]);
    int j;
    for (j = 0; j < game1->deckCount[player1]; j++){
      if (game1->deck[player1][j] == smithy){
        marker++;
      }
    }
    printf("player should have %d smithys in hand and has %d\n", i, marker);
    if (marker != i){
      marker2++;
    }
  }
  if (marker2 == 0){
    printf("All test passed unittest4\n");
  }
  else {
    printf("%d out of 10 test failed\n", marker2);
  }
  return 0;
}
