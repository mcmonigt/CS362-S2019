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
  // arbitratily chose card #3 in the array as the handPos argument
  int handPos = 0;
  struct gameState* game1 = newGame();
  int game_initialized;
  int cards[10] = { adventurer, village, smithy, council_room, feast, gardens, mine, minion, treasure_map };
  game_initialized = initializeGame(2, cards, 3, game1);
  if (game_initialized != 0){
    printf("game not intialized correctly\n");
    exit(1);
  }
  // modifies two cards from game1 player1 hand to  be trasure maps
  game1->hand[player1][0] = treasure_map;
  game1->hand[player1][1] = treasure_map;
  // tests actionTreasure_map function
  actionTreasure_map(player1, game1, handPos);


  int marker = 0;
  int i;
  int num_gold = 0;
  // checks to see if game1 and game2 status for player1 match
  if (game1->handCount[player1] != 3){
    printf("Test failed unittest3: wrong number of cards in hand\n");
    marker++;
  }
  for (i = 0; i < game1->handCount[player1]; i++){
    if (game1->hand[player1][i] == treasure_map){
      printf("Test failed unittest3: not all treasure map cards discarded\n");
      marker++;
    }
  }
  for (i = 0; i < game1->deckCount[player1]; i++){
    if (game1->deck[player1][i] == gold){
      num_gold++;
    }
  }
  if (num_gold != 4){
    printf("Test failed unittest3: wrong number of gold cards added to deck\n");
    marker++;
  }
  if (marker == 0){
    printf("All tests passed unittest3\n");
  }
  return 0;

}
