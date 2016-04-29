#include <stdio.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "test_helpers.h"

int main(int arc, char *argv[]) {
  printf("Running unit test for function \"intializeGame()\"...\n");

  struct gameState G1;
  struct gameState *p1 = &G1;
  struct gameState G2;
  struct gameState *p2 = &G2;
  struct gameState G3;
  struct gameState *p3 = &G3;
  struct gameState G4;
  struct gameState *p4 = &G4;
  struct gameState G5;
  struct gameState *p5 = &G5;
  struct gameState Gbad;
  struct gameState *pbad = &Gbad;

  int seed = 123456789;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};
  int kBad[10] = {adventurer, adventurer, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

  assertTrue(initializeGame(1, k, seed, p1) == -1, "initializeGame(1, k, seed, p1) == -1");
  assertTrue(initializeGame(3, k, seed, p3) == 0, "initializeGame(3, k, seed, p3) == 0");
  assertTrue(initializeGame(4, k, seed, p4) == 0, "initializeGame(4, k, seed, p4) == 0");
  assertTrue(initializeGame(5, k, seed, p5) == -1, "initializeGame(5, k, seed, p5) == -1");
  assertTrue(initializeGame(2, kBad, seed, pbad) == -1, "initializeGame(2, kBad, seed, pbad) == -1");
  
  //initializeGame(2, k, seed, p);
  assertTrue(initializeGame(2, k, seed, p2) == 0, "initializeGame(2, k, seed, p2) == 0");
  assertTrue(p2->numPlayers == 2, "p2->numPlayers == 2");
  assertTrue(p2->supplyCount[curse] == 10, "p2->supplyCount[curse] == 10");
  assertTrue(p2->supplyCount[estate] == 8, "p2->supplyCount[estate] == 8");
  assertTrue(p2->supplyCount[duchy] == 8, "p2->supplyCount[duchy] == 8");
  assertTrue(p2->supplyCount[province] == 8, "p2->supplyCount[province] == 8");
  assertTrue(p2->supplyCount[copper] == 46, "p2->supplyCount[copper] == 46");
  assertTrue(p2->supplyCount[silver] == 40, "p2->supplyCount[silver] == 40");
  assertTrue(p2->supplyCount[gold] == 30, "p2->supplyCount[gold] == 30");
  assertTrue(p2->embargoTokens[0] == 0, "p2->embargoTokens[0] == 0)");

  assertTrue(p2->deckCount[0] == 5, "p2->deckCount[0] == 5"); //10 cards originally but drew 5 cards
  assertTrue(p2->deckCount[1] == 5, "p2->deckCount[1] == 10"); 
  assertTrue(p2->deckCount[2] == 0, "p2->deckCount[2] == 0");

  return 0;
}
