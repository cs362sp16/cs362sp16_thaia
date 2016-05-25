#include "dominion.h"
#include "interface.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

#include <math.h>
#include <time.h>

// Print pointer to array
void printArr(int *ptr, size_t length){
  //for statement to print array values
  size_t i = 0;
  printf("cards:");
  for (i = 0; i < length; ++i){
    printf(" %d ", ptr[i]);
  }
  printf("\n");
}

int playerTurn(struct gameState *g, int num){
  int i, j, handPos, actionCards, choice1, choice2, choice3;

  actionCards = 0;

  //printHand(num, g);
  //printDeck(num, g);

  // ACTION PHASE
  for (i = 0; i < g->handCount[num]; i++){
    if (g->hand[num][i] > 6){  // cards with value 7+ are action cards
      actionCards++;
    }
  }
  printf("Number of action cards in hand: %d\n", actionCards);

  if (actionCards == 1){
    for (i = 0; i < g->handCount[num]; i++){
      if (g->hand[num][i] > 6){
        choice1 = rand() % g->handCount[num]; 
        choice2 = rand() % g->handCount[num];
        choice3 = rand() % g->handCount[num];
        playCard(i, choice1, choice2, choice3, g);
      }
    }
  }
  j = 0;
  
  if (actionCards > 1){
    printf("Playing a card\n");
    choice1 = rand() % g->handCount[num]; 
    choice2 = rand() % g->handCount[num];
    choice3 = rand() % g->handCount[num];

    while(g->numActions > 0){
      printf("In the while loop\n");
      j++;
      if (j > 25) break;  // Break out of loop after 25 unsuccessful tries
      handPos = rand() % g->handCount[num];
      playCard(handPos, choice1, choice2, choice3, g); 
    }
  }

  // BUY PHASE
  //printSupply(g);
  for (i = 0; i < 10; i++){
    handPos = rand() % (treasure_map + 1);
    if (-1 != buyCard(handPos, g))
      printf("Bought: %d\n", handPos);
  }
  //printDiscard(num, g);
  endTurn(g);

  return 0;
}

int main (int argc, char** argv) {
  int i, j, card, check, dup, randSeed, round;
  struct gameState g;
  struct gameState *p = &g;

  srand(time(NULL));

  int k[10];  // declare hand
  int numPlayers = rand() % 3 + 2;  // Generate random # of players

  // Seed the game
  if (argc >= 2){
    randSeed = atoi(argv[1]);
  }else{
    printf("Invalid number of arguments\n");
    exit(EXIT_FAILURE);
  }

  // Populate players' hand
  for (i = 0; i < 10; i++){
    do{
      card = rand() % (treasure_map + 1);
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
  // printArr(k, 10);  // Check that unique cards are unique
  printf ("Starting game.\n");
  
  check = initializeGame(numPlayers, k, randSeed, p);
  if (check != 0){
    printf("Error in initialization\n");
    exit(EXIT_FAILURE);
  } 
  printf("Number of players: %d\n", numPlayers);

  round = 0;
  // Game ends when either a stack of Province cards is emptied OR
  // three supply piles are at zero
  while(!isGameOver(p)){
    printf("\nROUND %d \n", round);
    round++;
    for (i = 0; i < numPlayers; i++){
      check = playerTurn(&g, i);
      printf("Player %d -- Score: %d\n", i, scoreFor(i, p));
    }
  }
  printf ("Finished game.\n\n");

  return 0;
}
