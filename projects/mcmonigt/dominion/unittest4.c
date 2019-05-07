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
  int handPos = 0;
  struct gameState* game1 = newGame();
  int game_initialized;
  int cards[10] = { adventurer, village, smithy, council_room, feast, gardens, mine, minion, treasure_map };
  game_initialized = initializeGame(2, cards, 3, game1);
  if (game_initialized != 0){
    printf("game not intialized correctly\n");
    exit(1);
  }
  // sets fest card to be in handPos in hand
  game1->hand[player1][handPos] = feast;
  // calling actionFeast on game1 player1
  int marker = 0;
  int marker2 = 0;
  actionFeast(player1, game1, smithy);
  int i;
  for (i = 0; i < game1->deckCount[player1]; i++){
    if (game1->deck[player1][i] == smithy){
      marker = 1;
    }
  }
  if (marker == 0){
    printf("Test failed unittest4: card not gained to deck\n");
    marker2++;
  }
  for (i = 0; i < game1->handCount[player1]; i++){
    if (game1->hand[player1][i] == feast){
      printf("Test failed unittest4: feast card not trashed from hand\n");
      marker2++;
    }
  }
  if (marker2 == 0){
    printf("All tests passed unittest4\n");
  }
  return 0;
}
