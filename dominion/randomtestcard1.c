// Council Room Random Tester

#include <stdio.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "test_helpers.h"

#define MAX_TESTS 10000

int main(int argc, char **argv) {
  
  srand(atoi(argv[1]));
  int i;
  int j;
  int r;
  int seed = 0;
  int numPlayers = 0;
  int currentPlayer = 0;
  //char playerStr[20];
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

    initializeGame(numPlayers, k, seed, post); // initialize post
    initializeGame(numPlayers, k, seed, pre); // initialize pre with same seed

    //Generate random inputs
    currentPlayer = whoseTurn(post);
    post->hand[currentPlayer][0] = council_room;

    r = playCard(0, 0, 0, 0, post);

    //Test oracle
    pre->numBuys++;
    pre->handCount[currentPlayer] = pre->handCount[currentPlayer] + 4 - 1;
    for (j = 0; j <= numPlayers; j++) {
      if (j != currentPlayer) {
        pre->handCount[j] = pre->handCount[j] + 1;
      }
    }

    assertTrue(r == 0, "return value test");
    assertTrue(pre->numBuys == post->numBuys, "numBuys test");
    //sprintf(playerStr, "current player (%d) hand count test", currentPlayer + 1);
    //assertTrue(pre->handCount[currentPlayer] == post->handCount[currentPlayer], playerStr);
    assertTrue(pre->handCount[currentPlayer] == post->handCount[currentPlayer], "current player hand count");
    for (j = 0; j < numPlayers; j++) {
      if (j != currentPlayer) {
        //sprintf(playerStr, "player %d hand count test", j + 1);
        //printf("%d, %d\n", pre->handCount[j], post->handCount[j]);
        assertTrue(pre->handCount[j] == post->handCount[j], "waiting player hand count");
      }
    }

    //assertTrue(memcmp(pre, post, sizeof(struct gameState)) == 0, "memcmp(pre, post, sizeof(struct gameState)) == 0");
    printf("\n");

  }
  return 0;
}
