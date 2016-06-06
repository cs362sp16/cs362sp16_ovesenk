/*
 * testdominion.c
 * Adopted from playdom.c
 */

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int retVal = 0;

int main(int argc, char **argv) {
  if (argc != 2) {
    fputs("ERROR: Argument Mismatch\n", stderr);
    fputs("Useage\n  testdominion GAME_SEED\n", stderr);
    return -1;
  }
  
  srand(atoi(argv[1]));
  const char *cardStr[27];
  cardStr[0] = "curse";
  cardStr[1] = "estate";
  cardStr[2] = "duchy";
  cardStr[3] = "province";
  cardStr[4] = "copper";
  cardStr[5] = "silver";
  cardStr[6] = "gold";
  cardStr[7] = "adventurer";
  cardStr[8] = "council_room";
  cardStr[9] = "feast";
  cardStr[10] = "gardens";
  cardStr[11] = "mine";
  cardStr[12] = "remodel";
  cardStr[13] = "smithy";
  cardStr[14] = "village";
  cardStr[15] = "baron";
  cardStr[16] = "great_hall";
  cardStr[17] = "minion";
  cardStr[18] = "steward";
  cardStr[19] = "tribute";
  cardStr[20] = "ambassador"; 
  cardStr[21] = "cutpurse";
  cardStr[22] = "embargo"; 
  cardStr[23] = "outpost";
  cardStr[24] = "salvager"; 
  cardStr[25] = "sea_hag";
  cardStr[26] = "treasure_map";

  int seed = atoi(argv[1]);
  SelectStream(1);
  PutSeed(seed);

  int i, j;
  int money = 0;
  int cardAlreadyInK = 0;
  int numPlayers = ((int)(Random() * 100) % 3) + 2;
  int k[10];
  struct gameState G;
  struct gameState *p = &G;
  for(i = 0; i < 10; i++) { // Initalize k cards to impossible value
    k[i] = -1;
  }
  for(i = 0; i < 10; i++) {
    int randKCard = (((int)(Random() * 100000) % 20) + 7);

    for(j = 0; j < 10; j++) { // Check if random card is already in K
      if(randKCard == k[j]) { // to prevent duplicates
        cardAlreadyInK = 1;
        break;
      }
    }

    if(cardAlreadyInK) {
      cardAlreadyInK = 0;
      i--;
      continue;
    } else {
      k[i] = randKCard;
    }
  }

  //Print inputs
  printf("Kingdom cards: ");
  for(i = 0; i < 10; i++) {
    printf("%s ", cardStr[k[i]]);
  }
  printf("\nNumber of players %d\n", numPlayers);
  

  initializeGame(numPlayers, k, seed, p);

  printf("Starting game.\n");
  int currentPlayer;
  while (!isGameOver(p)) {
    currentPlayer = whoseTurn(p);
    money = 0;
    
    printf("\n\nPlayer %d Current hand: ", currentPlayer + 1);
    for(i = 0; i < numHandCards(p); i++) {
      printf("%s ", cardStr[handCard(i, p)]);
    }

    // Taken from playdom, keep track of the player's money.
    for (i = 0; i < numHandCards(p); i++) {
      if (handCard(i, p) == copper) {
        money++;
      } else if (handCard(i, p) == silver) {
        money += 2;
      } else if (handCard(i, p) == gold) {
        money += 3;
      }
    }

    int r;
    int choice1, choice2;
    int timeout = 0;
    int cardPos = ((int)(Random() * 100) % numHandCards(p)); // pick random card

    printf("\n");
    if(handCard(cardPos, p) > 7) {
      choice1 = -1;
      choice2 = -1;
      if(handCard(cardPos, p) == feast) { //Card is feast
        while(1) {
          i = ((int)(Random() * 100) % 10);
          if (getCost(k[i]) <= 5) {
              choice1 = k[i];
              break;
          }
        }
      } else if(handCard(cardPos, p) == mine) { //Card is mine
        for(i = 0; i < numHandCards(p); i++) {
          if(handCard(i, p) >= 4 && handCard(i, p) <= 6) {
            choice1 = i;
            break;
          }
        }
          
        choice2 = (((int)(Random() * 1000)% 3) + 4);
      } else if(handCard(cardPos, p) == remodel) {  //Card is remodel
        choice1 = cardPos;

        while(1) {
          i  = (((int)(Random() * 100000) % 20) + 7);
          if ((getCost(k[i]) - 1) < getCost(handCard(choice1, p))) {
              choice2 = k[i];
              break;
          }
        }
      } else if(handCard(cardPos, p) == baron) {  //Card is baron
        choice1 = ((int)(Random() * 1000) % 2); //random 1 or 2
      } else if(handCard(cardPos, p) == minion) { //Card is minion
        choice1 = ((int)(Random() * 1000) % 2); //random 1 or 2
        choice2 = ((int)(Random() * 1000) % 2); //random 1 or 2
      } else if(handCard(cardPos, p) == ambassador) { //Card is ambassador
        while((choice1 = ((int)(Random() * 100) % numHandCards(p))) == cardPos);
        choice2 = ((int)(Random() * 1000) % 2); //random 1 or 2
      }

      printf("Play card %s: ", cardStr[handCard(cardPos, p)]);
      r = playCard(cardPos, choice1, choice2, -1, p);
      if (r == -1) {
        //printf("Card play %s failed", cardStr[handCard(cardPos, p)]);
        printf("FAILED\n");
        retVal = r;
      } else {
        //printf("Card play %s successful", cardStr[handCard(cardPos, p)]); //STRAGE SEGFAULT
        printf("successful\n");
      }
      fflush(stdout);
    } 
    timeout++;
    if(timeout > 5000) {
      break;
    }

    timeout = 0;
    printf("Player money: %d\n", money);
    if((int)(Random() * 1000) % 2) {
      if(money >= 8) {
        r = buyCard(province, p);
        if (r != -1) {
          printf("Bought province: successful\n");
        }
      } else if(money >= 6) {
        r = buyCard(gold, p);
        if (r != -1) {
          printf("Bought gold: successful\n");
        }
      } else if(money >= 3) {
        r = buyCard(silver, p);
        if (r != -1) {
          printf("Bought silver: successful\n");
        }
      } else { 
        r = buyCard(copper, p);
        if (r != -1) {
          printf("Bought copper: successful\n");
        }
      }
    } else {
      if (money >= 2) {
        while(1) {
          int cardToBuy =((int)(Random() * 100000) % 20) + 7;

          if (getCost(cardToBuy) <= money) {
            r = buyCard(cardToBuy, p);
            if (r == -1) {
              //printf("Bought %s FAILED\n", cardStr[cardToBuy]);
              retVal = r;
            } else {
              printf("Bought %s: successful\n", cardStr[cardToBuy]);
              break;
            }
            timeout++;
            if(timeout > 5000) { //Timout just in case there are no more cards to buy
              break;
            }
          }
        }
      }
    }

    endTurn(p);
    for(i = 0; i < numPlayers; i++) {
      printf ("Player %d: %d\n", i + 1, scoreFor(i, p));
    }
  }

  printf ("Finished game.\n");
  int players[numPlayers];
  getWinners(players, p);
  return retVal;
}

