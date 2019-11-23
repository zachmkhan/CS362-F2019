#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include<time.h> 
#include "rngs.h"



// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1
int randNum();

int main() {
    int i;
    int seed = 1000; //randNum(1,10000);
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount;
    int bonus;
    int k[10] = {estate, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState G;
    G.coins = 0;
    int maxHandCount = 5;
    // arrays of all coppers, silvers, and golds
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }




    printf ("TESTING minion:\n");
    printf("\n");

    int it = 0;
    int failure = 0;
    int pass = 0;

    int runs = randNum(10000,1000000);
    for(int count = 0; count <runs; count++)
    {
        seed = randNum(10,1000);
        memset(&G, 23, sizeof(struct gameState)); // set the game state
        //G.coins = 0;
        r = initializeGame(2, k, seed, &G); 
        int init = G.coins;
        it++;
        int choice1 = randNum(0,2);
        int choice2 = randNum(0,2);
        int handPos = randNum(0,numHandCards(&G));
        //printf(" Coins %d\n", G.coins);
        playCardMinion(minion, choice1, choice2, &G, handPos, 0);
        printf("Iteration: %d ", it);
        //printf("Coins %d\n", G.coins);
        //printf("Choice1 %d\n", choice1);
        if(G.coins == init && choice1 == 1)
        {
            failure++;
            printf("Coins = %d and should be %d TEST FAILURE # %d\n", G.coins, init+2, failure);

        }
        else
        {
            pass++;            
            printf("Coins = %d and should be %d TEST PASS # %d\n", G.coins, init, pass);
        }
    }
    printf("TOTAL PASS = %d\n", pass);
    printf("TOTAL FAIL = %d\n", failure);



    return 0;
}

int randNum(int min, int max)
{
    return (rand()% (max - min + 1)) + min;
}