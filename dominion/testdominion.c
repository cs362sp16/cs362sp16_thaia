#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

#include <math.h>
#include <time.h>

/* PART 1 
 *
 * Write a random tester that plays, given a seed as an argument, a complete
 * game of Dominion w/ a random number of players (from 2-4) and a random set
 * of kingdom cards
 *
 * KEEP IN MIND - Implementation should work, AI does not have to be "good"
 *
 */

// Print pointer to array
void printArr(int *ptr, size_t length){
  //for statement to print values using array
  size_t i = 0;
  printf("cards:");
  for (i = 0; i < length; ++i){
    printf(" %d ", ptr[i]);
  }
  printf("\n");
}

// Print pointer to string
/*void printString(const char *ptr){
  for ( ; *ptr != NULL; ++ptr){
    printf("%c", *ptr);
  }
  printf("\n");
}*/

int genCard(){
  return rand() % (treasure_map + 1);
}

int main (int argc, char** argv) {
  int i, j, card, dup, randSeed;
  struct gameState g;
  struct gameState *p = &g;

  int k[10];  // declare hand

  // Seed the game
  if (argc >= 2){
    randSeed = atoi(argv[1]);
  }else{
    printf("Invalid number of arguments\n");
    exit(EXIT_FAILURE);
  }

  srand(time(NULL));

  // Populate players' hand
  for (i = 0; i < 10; i++){
    do{
      card = genCard();
      // 'feast' and 'tribute' are broken so I'm not gonna deal until I get
      // around to fixing them
      if (card == feast || card == tribute) continue;
      dup = 0;
      for (j = 0; j < 10; j++){
        if (k[j] == card){
          dup++;
        }
      }
    }while(dup != 0);
    k[i] = card;
  }
  printArr(k, 10);  // Check that unique cards are unique
  printf ("Starting game.\n");
  
  initializeGame(2, k, atoi(argv[1]), p);

  // Game ends when either a stack of Province cards is emptied OR
  // three supply piles are at zero

  while(!isGameOver(p)){

  }

  /*
  int money = 0;
  int smithyPos = -1;
  int adventurerPos = -1;
  int i=0;

  int numSmithies = 0;
  int numAdventurers = 0;

  while (!isGameOver(p)) {
    money = 0;
    smithyPos = -1;
    adventurerPos = -1;
    for (i = 0; i < numHandCards(p); i++) {
      if (handCard(i, p) == copper)
    money++;
      else if (handCard(i, p) == silver)
    money += 2;
      else if (handCard(i, p) == gold)
    money += 3;
      else if (handCard(i, p) == smithy)
    smithyPos = i;
      else if (handCard(i, p) == adventurer)
    adventurerPos = i;
    }

    if (whoseTurn(p) == 0) {
      if (smithyPos != -1) {
        printf("0: smithy played from position %d\n", smithyPos); 
	playCard(smithyPos, -1, -1, -1, p); 
	printf("smithy played.\n");
	money = 0;
	i=0;
	while(i<numHandCards(p)){
	  if (handCard(i, p) == copper){
	    playCard(i, -1, -1, -1, p);
	    money++;
	  }
	  else if (handCard(i, p) == silver){
	    playCard(i, -1, -1, -1, p);
	    money += 2;
	  }
	  else if (handCard(i, p) == gold){
	    playCard(i, -1, -1, -1, p);
	    money += 3;
	  }
	  i++;
	}
      }

      if (money >= 8) {
        printf("0: bought province\n"); 
        buyCard(province, p);
      }
      else if (money >= 6) {
        printf("0: bought gold\n"); 
        buyCard(gold, p);
      }
      else if ((money >= 4) && (numSmithies < 2)) {
        printf("0: bought smithy\n"); 
        buyCard(smithy, p);
        numSmithies++;
      }
      else if (money >= 3) {
        printf("0: bought silver\n"); 
        buyCard(silver, p);
      }

      printf("0: end turn\n");
      endTurn(p);
    }
    else {
      if (adventurerPos != -1) {
        printf("1: adventurer played from position %d\n", adventurerPos);
	playCard(adventurerPos, -1, -1, -1, p); 
	money = 0;
	i=0;
	while(i<numHandCards(p)){
	  if (handCard(i, p) == copper){
	    playCard(i, -1, -1, -1, p);
	    money++;         
	  }
	  else if (handCard(i, p) == silver){
	    playCard(i, -1, -1, -1, p);
	    money += 2;
	  }
	  else if (handCard(i, p) == gold){
	    playCard(i, -1, -1, -1, p);
	    money += 3;
	  }
	  i++;
	}
      }

      if (money >= 8) {
        printf("1: bought province\n");
        buyCard(province, p);
      }
      else if ((money >= 6) && (numAdventurers < 2)) {
        printf("1: bought adventurer\n");
	buyCard(adventurer, p);
	numAdventurers++;
      }else if (money >= 6){
        printf("1: bought gold\n");
	    buyCard(gold, p);
        }
      else if (money >= 3){
        printf("1: bought silver\n");
	    buyCard(silver, p);
      }
      printf("1: endTurn\n");
      
      endTurn(p);      
    }

      printf ("Player 0: %d\nPlayer 1: %d\n", scoreFor(0, p), scoreFor(1, p));
	    
  } // end of While*/

  printf ("Finished game.\n");
  printf ("Player 0: %d\nPlayer 1: %d\n", scoreFor(0, p), scoreFor(1, p));

  return 0;
}
