#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "../dominion.h"
#include "../rngs.h"

// Random Test Adventurer

int main(){
  int i, j, numplayers, randSeed;
  int k[10] = {smithy, adventurer, gardens, embargo, cutpurse, mine, ambassador,
               outpost, baron, tribute};
  srand(time(NULL)); // Seed rng

  struct gameState g;

  printf("``adventurer`` -- RANDOM TESTS START \n");

  for (j = 0; j < 250; j++){ // picked an arbitrary number of tests
    numplayers = rand() % MAX_PLAYERS;
    randSeed = rand();
    initializeGame(numplayers, k, randSeed, &g);

    for (i = 0; i < numplayers; i++){
      g.deckCount[i] = rand() % MAX_DECK;
      g.handCount[i] = rand() % MAX_HAND;
      g.discardCount[i] = rand() % MAX_HAND;
    }
  }

  //playCard(handPos, choice1, choice2, choice3, &g);
  playCard(0, 1, 1, 1, &g);

  printf("``adventurer`` -- RANDOM TESTING COMPLETE \n");
  return 0;
}
