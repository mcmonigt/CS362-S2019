#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

// test for actionCouncil_room function
int main(){
  int player1 = 0;
  // random hand position just for the purpose of checking if a card was discarded
  int handPos = 1;
  struct gameState* game1 = newGame();
  // struct gameState* game2 = newGame();
  int game_initialized;
  int cards[10] = { adventurer, village, smithy, council_room, feast, gardens, mine, minion, treasure_map };
  game_initialized = initializeGame(2, cards, 3, game1);
  if (game_initialized != 0){
    perror("game not intialized correctly\n");
    exit(1);
  }
  // game_initialized = initializeGame(2, cards, 3, game2);
  // if (game_initialized != 0){
  //   perror("game not intialized correctly\n");
  //   exit(1);
  // }

  // // THE FOLLOWING MANUALLY DOES 2 OF THE THINGS actionCouncil_room should do
  // // WITH player1
  // // adds +4 cards to player1
  // int i;
  // for (i = 0; i < 4; i++){
  //   drawCard(player1, game1);
  // }
  // // increase numBuys
  // game1->numBuys++;
  // // other player must draw a card
  // for (i = 0; i < game1->numPlayers; i++){
  //   if ( i != player1 ){
  //     drawCard(i, game1);
  //   }
  // }
  // //put played card in played card pile
  // discardCard(handPos, player1, game1, 0);
  int i;
  int marker = 0;
  for (i = 1; i <= 10; i++){
    actionCouncil_room(player1, game1, handPos);
    int j;
    // adds 4 cards to deck to make sure there are enough cards to draw again
    for (j = 0; j < 10; j++){
      gainCard(i, game1, 1, player1);
    }
    printf("player 0 should have %d cards in hand and has %d\n", 5 + (i*3), game1->handCount[player1]);
    printf("player 0 should have %d number of buys left and has %d\n", 1 + i, game1->numBuys);
    if ((5+(i*3)) != game1->handCount[player1]){
      marker++;
    }
    if (1 + i != game1->numBuys){
      marker++;
    }
    if (marker == 0){
      printf("All tests passed unittest1\n");
    }
    else {
      printf("%d out of 20 tests failed unittest1\n", marker);
    }
  }

  // int marker = 0;
  // // Checks the results
  // if (game1->handCount[player1] != game2->handCount[player1]){
  //   printf("Test failed unittest1: error in drawCard call\n");
  //   marker++;
  // }
  // if (game1->hand[player1][handPos] != game2->hand[player1][handPos]){
  //   printf("Test failed unittest1: error in discardCard call\n");
  //   marker++;
  // }
  // if (game1->numBuys != game2->numBuys){
  //   printf("Test failed unittest1: numbuys not incremented correctly\n");
  //   marker++;
  // }
  // if (marker == 0){
  //   printf("All tests passed for unittest1\n");
  // }
  return 0;
}
