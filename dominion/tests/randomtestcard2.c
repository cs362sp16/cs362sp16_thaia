#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "../dominion.h"
#include "../rngs.h"
#include "../interface.h"

// Random Test Smithy

int failed = 0;

void assertTF(int b, char *msg){
  if (b == 0){
    printf("FAILED ASSERTION: %s", msg);
    failed = 1;
  }
}

void checkasserts(){
  if (!failed){
    printf("TESTS COMPLETED\n\n");
  }
}

int runthru(struct gameState *g, int handSz, int deckSz, int who){
  int val;

  val = g->handCount[who];
  assertTF(val != handSz, "Number of cards in hand has changed\n");
  val = g->deckCount[who];
  assertTF(val != deckSz, "Number of cards in deck has changed\n");

  if (failed){
    printf("FAILURE FOUND\n\n");
  }
  failed = 0;
  return 0;
}

int main(int argc, char *argv[]){
  int j, numplayers, randSeed, runt, volte, handSz, deckSz;
  int k[10] = {smithy, adventurer, gardens, embargo, cutpurse, mine, ambassador,
               outpost, baron, tribute};
  int choice[4];
  srand(time(NULL)); // Seed rng

  struct gameState g;

  printf("``smithy`` -- RANDOM TESTS START \n");

  if (argc >= 2){
    randSeed = atoi(argv[1]);
  }else{
    randSeed = rand();
  }
  volte = rand() % 1000;
  printf("Tests run: %d\n", (volte));

  for (runt = 0; runt < volte; runt++){
    numplayers = rand() % 3 + 2;
    initializeGame(numplayers, k, randSeed, &g);
    g.handCount[0] = rand() % 10; // gen random hand count for player i
    for (j = 0; j < 3; j++){
      choice[j] = rand() % 3 + 1;
      choice[j] = 0;
    }
    g.hand[0][0] = smithy;  // set first card for player i, to be smithy
    handSz = g.handCount[0];
    deckSz = g.deckCount[0]; 

    playCard(0, choice[0], choice[1], choice[2], &g);
    runthru(&g, handSz, deckSz, 0);
  }
  printf("``smithy`` -- RANDOM TESTING COMPLETE \n");
  checkasserts();
  return 0;
}
