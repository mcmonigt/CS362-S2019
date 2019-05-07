#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

// testing great_hall case statement within cardEffect function
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
  // dummy variables not used but needed to be initialized for cardEffect
  int choice1 = 0;
  int choice2 = 0;
  int choice3 = 0;
  int bonus[2] = {0 , 1};

  int marker = 0;
  int i;
  for (i = 1; i <= 10; i++){
    cardEffect(great_hall, choice1, choice2, choice3, game1, handPos, bonus);
    // adds 1 card to deck to make sure the player doesn't run out of cards
    gainCard(i, game1, 1, player1);
    printf("player 0 should have %d cards in hand and has %d\n", 5, game1->handCount[player1]);
    printf("player 0 should have %d actions and has %d\n", 1 + i, game1->numActions);
    if (5 != game1->handCount[player1]){
      marker++;
    }
    if (1 + i != game1->numActions){
      marker++;
    }
  }
  if (marker == 0){
    printf("All tests passed cardtest4\n");
  }
  else {
    printf("%d out of 20 test failed cardtest4\n", marker);
  }
  return 0;
}
