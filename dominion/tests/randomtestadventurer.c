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
    printf("FAILED ASSERTION: %s", msg);
    failed = 1;
  }
}

void checkasserts(){
  if (!failed){
    printf("TESTS COMPLETED.\n\n");
  }
}

int runthru(struct gameState *g, int handSz, int deckSz, int currcoins,
            int nDiscard, int who){
  int val;

  val = g->handCount[who];
  assertTF(val != handSz, "Number of cards in hand has changed\n");
  val = g->deckCount[who];
  assertTF(val != deckSz, "Number of cards in deck has changed\n");
  val = g->coins;
  assertTF(val != currcoins, "Number of coins in hand has changed\n");
  val = g->discardCount[who];
  assertTF(val != nDiscard, "Card(s) have been discarded\n");

  if (failed){
    printf("FAILURE FOUND\n\n");
  }

  failed = 0;
  return 0;
}

int main(int argc, char *argv[]){
  int j, numplayers, randSeed, runt, volte;
  int handSz, deckSz, nDiscard, currcoins;
  int k[10] = {smithy, adventurer, gardens, embargo, cutpurse, mine, ambassador,
               outpost, baron, tribute};
  int choice[4];
  srand(time(NULL)); // Seed rng
  
  struct gameState g;

  printf("``adventurer`` -- RANDOM TESTS START \n");

  if (argc >= 2){
    randSeed = atoi(argv[1]);
  }
  else{
    randSeed = rand();
  }

  //numplayers = rand() % 3 + 2;
  //initializeGame(numplayers, k, randSeed, &g);

  volte = rand() % 1000;
  printf("Tests run: %d\n", (volte));

  for (runt = 0; runt < volte; runt++){
    numplayers = rand() % 3 + 2;
    initializeGame(numplayers, k, randSeed, &g);
    g.deckCount[0] = rand() % MAX_DECK;
    g.handCount[0] = rand() % MAX_HAND;
    g.discardCount[0] = rand() % MAX_HAND;
    // Randomly generating choices to be made
    for (j = 0; j < 3; j++){
      choice[j] = rand() % 3 + 1;
    }
    //handPos = rand() % g.handCount[i];
    g.hand[0][0] = adventurer;
    deckSz = g.deckCount[0];
    handSz = g.handCount[0];
    nDiscard = g.discardCount[0];
    currcoins = g.coins;
  
    playCard(0, choice[0], choice[1], choice[2], &g);
    runthru(&g, handSz, deckSz, currcoins, nDiscard, 0); 
  }
  printf("``adventurer`` -- RANDOM TESTING COMPLETE \n\n");
  checkasserts();
  return 0;
}
