#include <stdio.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "test_helpers.h"

int main(int arc, char *argv[]) {
  printf("Running unit test for function \"intializeGame()\"...\n");

  struct gameState G;
  struct gameState *p = &G;

  int seed = 123456789;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};
  int kBad[10] = {adventurer, adventurer, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

  assertTrue(initializeGame(2, k, seed, p) == 0, "initializeGame(2, k, seed, p) == 0");
  assertTrue(p->numPlayers == 2, "p->numPlayers == 2");
  assertTrue(p->supplyCount[curse] == 10, "p->supplyCount[curse] == 10");
  assertTrue(p->supplyCount[estate] == 8, "p->supplyCount[estate] == 8");
  assertTrue(p->supplyCount[duchy] == 8, "p->supplyCount[duchy] == 8");
  assertTrue(p->supplyCount[province] == 8, "p->supplyCount[province] == 8");
  assertTrue(p->supplyCount[copper] == 46, "p->supplyCount[copper] == 46");
  assertTrue(p->supplyCount[silver] == 40, "p->supplyCount[silver] == 40");
  assertTrue(p->supplyCount[gold] == 30, "p->supplyCount[gold] == 30");
  assertTrue(p->embargoTokens[0] == 0, "p->embargoTokens[0] == 0)");
  assertTrue(p->deckCount[0] == 5, "p->deckCount[0] == 5"); //10 cards originally but drew 5 cards
  assertTrue(p->deckCount[1] == 10, "p->deckCount[1] == 10"); 
  assertTrue(p->deckCount[2] == 0, "p->deckCount[2] == 0");

  assertTrue(initializeGame(1, k, seed, p) == -1, "initializeGame(1, k, seed, p) == -1");
  assertTrue(initializeGame(3, k, seed, p) == 0, "initializeGame(3, k, seed, p) == 0");
  assertTrue(initializeGame(4, k, seed, p) == 0, "initializeGame(4, k, seed, p) == 0");
  assertTrue(initializeGame(5, k, seed, p) == -1, "initializeGame(5, k, seed, p) == -1");
  assertTrue(initializeGame(2, kBad, seed, p) == -1, "initializeGame(2, kBad, seed, p) == -1");
  

  return 0;
}
