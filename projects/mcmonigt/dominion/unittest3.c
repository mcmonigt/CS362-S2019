#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

// unit test for actionTreasure_map
int main(){
  int player1 = 0;
  // handPos will be the index where a treasure map will be placed
  int handPos = 4;
  struct gameState* game1 = newGame();
  int game_initialized;
  int cards[10] = { adventurer, village, smithy, council_room, feast, gardens, mine, minion, treasure_map };
  game_initialized = initializeGame(2, cards, 3, game1);
  if (game_initialized != 0){
    printf("game not intialized correctly\n");
    exit(1);
  }

  int i;
  int marker = 0;
  int num_gold = 0;
  // changes two cards for the trasure map in the players hand
  game1->hand[player1][4] = treasure_map;
  game1->hand[player1][3] = treasure_map;
  for (i = 1; i <= 10; i++){
    // calls the function
    actionTreasure_map(player1, game1, handPos);
    // checks results
    if (game1->handCount[player1] != 3){
      printf("loop %d number of cards in hand: %d\n", i, game1->handCount[player1]);
      printf("Test %d failed unittest3: wrong number of cards in hand\n", i);
      marker++;
    }
    int j;
    for (j = 0; j < game1->handCount[player1]; j++){
      if (game1->hand[player1][i] == treasure_map){
        printf("Test %d failed unittest3: not all treasure map cards discarded\n", i + 10);
        marker++;
      }
    }
    for (j = 0; j < game1->deckCount[player1]; j++){
      if (game1->deck[player1][j] == gold){
        num_gold++;
      }
    }
    if (num_gold != i*4){
      printf("test %d failed unittest3: number of gold cards added to deck incorrect\n", i + 20);
      marker++;
    }
  }
  if (marker == 0){
    printf("All test passed unittest3\n");
  }
  else {
    printf("%d out of 30 tests failed unittest3\n", marker);
  }
  return 0;

}
