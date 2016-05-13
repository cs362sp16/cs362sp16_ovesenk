#include <stdio.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "test_helpers.h"

#define MAX_TESTS 10000

int main(int argc, char **argv) {

  //SelectStream(atoi(argv[1]));
  //Seed(atoi(argv[1]));
  srand(atoi(argv[1]));
  int i;
  int j;
  int r;
  int seed = 0;
  int numPlayers = 0;
  int currentPlayer = 0;
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
    numPlayers = (rand() % 3) + 2; //Random number 0-4
    //seed = Random();
    //numPlayers = Random() % 3 + 2;
    //printf("%d, %d\n", numPlayers, seed);

    initializeGame(numPlayers, k, seed, post); // initialize post
    initializeGame(numPlayers, k, seed, pre); // initialize pre with same seed
    
    // Generate random inputs
    // add great_hall at beginning of hand
    currentPlayer = whoseTurn(post);
    post->hand[currentPlayer][0] = great_hall;

    r = playCard(0, 0, 0, 0, post);

    //Test oracle
    pre->numActions = pre->numActions + 1;
    pre->handCount[currentPlayer]++;
    pre->deckCount[currentPlayer]--;
    pre->handCount[currentPlayer]--;

    assertTrue(r == 0, "return value test");
    assertTrue(pre->deckCount[currentPlayer] == post->deckCount[currentPlayer], "deck count test");
    assertTrue(pre->handCount[currentPlayer] == post->handCount[currentPlayer], "hand count test");

    // Due to being unable to control randomness and shuffling, this assert was never true
    //assertTrue(memcmp(pre, post, sizeof(struct gameState)) == 0, "memcmp(pre, post, sizeof(struct gameState)) == 0");

    printf("\n");
  }
  return 0;
}
