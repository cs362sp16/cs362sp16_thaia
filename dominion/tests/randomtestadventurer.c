#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "../dominion.h"
#include "../rngs.h"

// Random Test Adventurer

int failed = 0;

void assertTF(int b, char *msg){
  if (b == 0){
    printf("FAILED ASSERTION: %s\n", msg);
    failed = 1;
  }
}

void checkasserts(){
  if (!failed){
    printf("TEST SUCCESSFULLY COMPLETED.\n\n");
  }
}

int main(){
  int i, j, r, numplayers, randSeed;
  int k[10] = {smithy, adventurer, gardens, embargo, cutpurse, mine, ambassador,
               outpost, baron, tribute};
  int choice[4];
  srand(time(NULL)); // Seed rng
  
  struct gameState g;

  printf("``adventurer`` -- RANDOM TESTS START \n");

  numplayers = rand() % 2 + 2;
  randSeed = rand();
  initializeGame(numplayers, k, randSeed, &g);

  for (i = 0; i < numplayers; i++){
    g.deckCount[i] = rand() % MAX_DECK;
    g.handCount[i] = rand() % MAX_HAND;
    g.discardCount[i] = rand() % MAX_HAND;
    // Randomly generating choices to be played in cardEffect
    for (j = 0; j < 3; j++){
      choice[j] = rand() % 2 + 1;
    }
    r = cardEffect(adventurer, choice[0], choice[1], choice[2], &g, 0, 0);
    assertTF(r == 0, "Adventurer played successfully\n");
  }
  printf("``adventurer`` -- RANDOM TESTING COMPLETE \n");
  
  checkasserts();
}
