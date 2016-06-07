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

int runthru(struct gameState *g, int handSz, int who){
  int val;

  val = g->handCount[who];
  printf("player: %d\n", who);
  printf("old hand count: %d\n", handSz);
  printf("new hand count: %d\n", val);
  assertTF(val != handSz, "Number of cards in hand has changed\n");
  //val = g->deckCount[who];
  //assertTF(val != deckSz, "Number of cards in deck has changed\n");
  //val = g->coins;
  //assertTF(val != currcoins, "Number of coins in hand has changed\n");
  //val = g->discardCount[who];
  //assertTF(val != nDiscard, "Card(s) have been discarded\n");

  if (failed){
    printf("FAILURE FOUND\n\n");
  }
  else{
    printf("TEST PASSED\n\n");
  }

  failed = 0;
  return 0;
}

int main(int argc, char *argv[]){
  int i, j, numplayers, randSeed, runt, volte, handSz;
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

  //numplayers = rand() % 3 + 2;
  //initializeGame(numplayers, k, randSeed, &g);

  volte = rand() % 1000;
  printf("Tests run: %d\n", (volte));

  for (runt = 0; runt < volte; runt++){
      numplayers = rand() % 3 + 2;
      initializeGame(numplayers, k, randSeed, &g);
    //for (i = 0; i < numplayers; i++){
      //i = 0;
      g.handCount[0] = rand() % 10; // gen random hand count for player i
      /*for (j = 0; j < 3; j++){
        choice[j] = rand() % 3 + 1;
        choice[j] = 0;
      }*/
      g.hand[0][0] = smithy;  // set first card for player i, to be smithy
      handSz = g.handCount[0];
      printf("Player's hand before turn\n");
      printHand(0, &g);
      printf("Before play: %d\n", handSz);
 
      //playCard(handPos, choice1, choice2, choice3, gameState) 
      //playCard(i, choice[0], choice[1], choice[2], &g);
      //if (g.hand[i][0] == smithy){
      playCard(0, 0, 0, 0, &g);
        //j = cardEffect(smithy, 0, 0, 0, &g, 0, 0);
        //assertTF(j == 0, "Smithy played\n");
      printf("After play: %d\n", g.handCount[0]);
      runthru(&g, handSz, 0);
      printf("Player's hand after turn\n");
      printHand(0, &g);
      //}
      //else{
      //  printf("Fuck everything\n");
      //}
    //}
  }
  printf("``smithy`` -- RANDOM TESTING COMPLETE \n");
  checkasserts();
  return 0;
}
