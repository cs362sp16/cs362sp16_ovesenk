#include <stdio.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "test_helpers.h"

int main() {
  printf("Running unit test for card \"village\"...\n");

  struct gameState G;
  struct gameState *p = &G;

  int seed = 123456789;
  int numActionsBefore;
  int numHandCardsBefore;
  int k[10] = {village, gardens, embargo, adventurer, minion, mine, cutpurse, 
    sea_hag, tribute, smithy};

  initializeGame(2, k, seed, p);
  numActionsBefore = p->numActions;
  numHandCardsBefore = numHandCards(p);

  p->hand[0][0] = village;
  assertTrue(playCard(0, 0, 0, 0, p) == 0, "playCard(0, 0, 0, 0, p) == 0");
  assertTrue(numHandCards(p) == numHandCardsBefore, "numHandCards(p) == numHandCardsBefore");
  assertTrue(p->numActions == numActionsBefore + 2 - 1, "p->numActions == numActionsBefore + 2 - 1"); //BUG: Actions should increase by 2, not 1

  return 0;
}
