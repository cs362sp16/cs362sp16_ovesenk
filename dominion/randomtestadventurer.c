// Adventurer random tester

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "test_helpers.h"

#define MAX_TESTS 10000

int main(int argc, char **argv) {

  srand(atoi(argv[1]));
  int i;
  int r;
  int seed;
  int numPlayers;
  int currentPlayer;
  int treasureIn1 = 0;
  int treasureIn2 = 0;
  int preHandCount;
  struct gameState G;
  struct gameState *post = &G;
  struct gameState preG;
  struct gameState *pre= &preG;
  int k[10] = {
    adventurer, 
    gardens,
    embargo, 
    village, 
    minion, 
    mine, 
    cutpurse, 
    sea_hag, 
    tribute, 
    smithy, 
  };
  
  for (i = 1; i <= MAX_TESTS; i++) {
    
    seed = rand();
    numPlayers = (rand() % 3) + 2; //Random number between 0-4

    initializeGame(numPlayers, k, seed, post); // initialize post
    initializeGame(numPlayers, k, seed, pre); // initialize pre with same seed
    
    //Generate random inputs
    // add adventurer card in hand
    currentPlayer = whoseTurn(post);
    post->hand[currentPlayer][0] = adventurer;

    r = playCard(0, 0, 0, 0, post);

    //Test oracle
    preHandCount = pre->handCount[currentPlayer] + 2;
    pre->handCount[currentPlayer] = preHandCount;

    if (post->hand[currentPlayer][post->handCount[currentPlayer] - 1] == copper) {
      treasureIn1 = 1;
    } else if (post->hand[currentPlayer][post->handCount[currentPlayer] - 1] == silver) {
      treasureIn1 = 1;
    } else if (post->hand[currentPlayer][post->handCount[currentPlayer] - 1] == gold) {
      treasureIn1 = 1;
    }
    if (post->hand[currentPlayer][post->handCount[currentPlayer] - 2] == copper) {
      treasureIn2 = 1;
    } else if (post->hand[currentPlayer][post->handCount[currentPlayer] - 2] == silver) {
      treasureIn2 = 1;
    } else if (post->hand[currentPlayer][post->handCount[currentPlayer] - 2] == gold) {
      treasureIn2 = 1;
    }

    assertTrue(r == 0, "return value test");
    assertTrue(treasureIn1 && treasureIn2, "card treasure test");
    assertTrue(post->handCount[currentPlayer] == pre->handCount[currentPlayer], "hand count test");
    assertTrue(pre->deckCount[currentPlayer] - post->deckCount[currentPlayer] == post->discardCount[currentPlayer] + 2,
        "discard and deck count test"); 

    printf("\n");
  }
  return 0;
}
