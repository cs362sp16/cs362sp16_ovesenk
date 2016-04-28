#include <stdio.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "test_helpers.h"

int main() {
  printf("Running unit test for card \"great_hall\"...\n");

  struct gameState G;
  struct gameState *p = &G;

  int seed = 123456789;
  int numActionsBefore;
  int numHandCardsBefore;
  int k[10] = {great_hall, gardens, embargo, village, minion, mine, cutpurse, 
    sea_hag, tribute, smithy};

  initializeGame(2, k, seed, p);
  numActionsBefore = p->numActions;
  numHandCardsBefore = numHandCards(p);

  p->hand[0][0] = great_hall;
  assertTrue(playCard(0, 0, 0, 0, p) == 0, "playCard(0, 0, 0, 0, p) == 0");
  assertTrue(numHandCards(p) == numHandCardsBefore, "numHandCards(p) == numHandCardsBefore");
  assertTrue(p->numActions == numActionsBefore + 1 - 1, "p->numActions == numActionsBefore + 1 - 1");  //Add actions and sub from playCard

  return 0;
}
