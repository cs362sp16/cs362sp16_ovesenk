#include <stdio.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "test_helpers.h"

int main(int argc, char *argv[]) {
  printf("Running unit test for function \"isGameOver()\"...\n");

  struct gameState G;
  struct gameState *p = &G;

  int seed = 123456789;
  int i;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
    sea_hag, tribute, smithy};

  initializeGame(2, k, seed, p);
  assert(isGameOver(p) != 1);

  p->supplyCount[0] = 0;
  p->supplyCount[1] = 0;
  p->supplyCount[2] = 0;
  p->supplyCount[3] = 0;
  p->supplyCount[4] = 0;
  assertTrue(isGameOver(p) == 1, "assert(isGameOver(p) == 1");

  initializeGame(2, k, seed, p);
  for (i = 0; i < 4; i++) { 
    p->supplyCount[i] = 0;
    if (i < 2) {
      assertTrue(isGameOver(p) == 0, "assert(isGameOver(p) == 0");
    } else {
      assertTrue(isGameOver(p) == 1, "assert(isGameOver(p) == 1");
    }
  }

  return 0;
}
