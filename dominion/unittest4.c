#include <stdio.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "test_helpers.h"

#define TRUE 1
#define FALSE 0

int compareCards(struct gameState state1, struct gameState state2, int player, int deckCount) {
  int i;
  for(i = 0; i < deckCount; i++){
    if(state1.deck[player][i] != state2.deck[player][i]) {

      return TRUE;
    }
  }
  return FALSE;
}

int main(int argc, char *argv[]) {
  printf("Running unit test for function \"shuffle()\"...\n");

  int seed1 = 123456789;
  int seed2 = 987654321;
  int deckCount = 10;
  int player1 = 0;
  int player2 = 1;
  int player3 = 2;
  int player4 = 3;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
    sea_hag, tribute, smithy};

  struct gameState originalState;
  struct gameState shuffledState;

  assertTrue(initializeGame(1, k, seed1, &shuffledState) == -1, "initializeGame(1, k, seed1, &shuffledState) == -1");

  // Test shuffle for max players
  initializeGame(4, k, seed1, &originalState);
  initializeGame(4, k, seed1, &shuffledState);

  shuffle(player1, &shuffledState);
  assertTrue(compareCards(originalState, shuffledState, player1, deckCount) == TRUE, "compareCards(originalState, shuffledState, player1, deckCount) == TRUE");

  shuffle(player2, &shuffledState);
  assertTrue(compareCards(originalState, shuffledState, player1, deckCount) == TRUE, "compareCards(originalState, shuffledState, player2, deckCount) == TRUE");

  shuffle(player3, &shuffledState);
  assertTrue(compareCards(originalState, shuffledState, player1, deckCount) == TRUE, "compareCards(originalState, shuffledState, player3, deckCount) == TRUE");

  shuffle(player4, &shuffledState);
  assertTrue(compareCards(originalState, shuffledState, player1, deckCount) == TRUE, "compareCards(originalState, shuffledState, player4, deckCount) == TRUE");

  // Test shuffle for max players
  initializeGame(4, k, seed2, &originalState);
  initializeGame(4, k, seed2, &shuffledState);

  shuffle(player1, &shuffledState);
  assertTrue(compareCards(originalState, shuffledState, player1, deckCount) == TRUE, "compareCards(originalState, shuffledState, player1, deckCount) == TRUE");

  shuffle(player2, &shuffledState);
  assertTrue(compareCards(originalState, shuffledState, player1, deckCount) == TRUE, "compareCards(originalState, shuffledState, player2, deckCount) == TRUE");

  shuffle(player3, &shuffledState);
  assertTrue(compareCards(originalState, shuffledState, player1, deckCount) == TRUE, "compareCards(originalState, shuffledState, player3, deckCount) == TRUE");

  shuffle(player4, &shuffledState);
  assertTrue(compareCards(originalState, shuffledState, player1, deckCount) == TRUE, "compareCards(originalState, shuffledState, player4, deckCount) == TRUE");

  return 0;
}
