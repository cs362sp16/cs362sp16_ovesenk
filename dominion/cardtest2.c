#include <stdio.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "test_helpers.h"

int main() {
  printf("Running unit test for card \"steward\"...\n");

  struct gameState G;
  struct gameState *p = &G;

  int seed = 123456789;
  int coinsBefore;
  int numHandCardsBefore;
  int k[10] = {steward, gardens, embargo, village, minion, mine, cutpurse, 
    sea_hag, tribute, smithy};
  
  initializeGame(2, k, seed, p);
  p->hand[0][0] = steward;
  coinsBefore = p->coins;
  assertTrue(playCard(0, 0, 0, 0, p) == 0, "playCard(0, 0, 0, 0, p) == 0");
  assertTrue(p->coins == coinsBefore + 2, "p->coins == coinsBefore + 2");  //BUG: coin values not updating

  initializeGame(2, k, seed, p);
  p->hand[0][0] = steward;
  numHandCardsBefore = numHandCards(p);
  assertTrue(playCard(0, 1, 0, 0, p) == 0, "playCard(0, 1, 0, 0, p) == 0");
  assertTrue(numHandCards(p) == numHandCardsBefore + 2 - 1, "numHandCards(p) == numHandCardsBefore + 2 - 1");

  initializeGame(2, k, seed, p);
  p->hand[0][0] = steward;
  numHandCardsBefore = numHandCards(p);
  assertTrue(playCard(0, 2, 0, 0, p) == 0, "playCard(0, 2, 0, 0, p) == 0");
  assertTrue(numHandCards(p) == numHandCardsBefore - 3 , "numHandCards(p) == numHandCardsBefore - 3");

  return 0;
}
