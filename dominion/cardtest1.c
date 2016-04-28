#include <stdio.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "test_helpers.h"

int main() {
  printf("Running unit test for card \"council_room\"...\n");

  struct gameState G;
  struct gameState *p = &G;

  int seed = 123456789;
  int numBuysBefore;
  int numHandCardsBefore;
  int k[10] = {council_room, gardens, embargo, village, minion, mine, cutpurse, 
    sea_hag, tribute, smithy};

  initializeGame(2, k, seed, p);
  numBuysBefore = p->numBuys;
  numHandCardsBefore = numHandCards(p);

  p->hand[0][0] = council_room;

  assertTrue(playCard(0, 0, 0, 0, p) == 0, "playCard(0, 0, 0, 0, p) == 0");
  assertTrue(numHandCards(p) == numHandCardsBefore + 4 - 1, "numHandCards(p) == numHandCardsBefore + 4 - 1");  //Starting cards + 4 drawn - 1 discard
                                                          //FORCED BUG from assignment 1
  assertTrue(p->numBuys == numBuysBefore + 1, "p->numBuys == numBuysBefore + 1");

  endTurn(p);
  assertTrue(numHandCards(p) == 5 + 1, "numHandCards(p) == 5 + 1"); //Starting cards + 1 drawn
                                     //BUG: should be 5 + 1

  return 0;
}
