/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
 *      gcc -o testUpdateCoins -g  testUpdateCoins.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "interface.h"
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
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount;
    int bonus;
    int k[10] = {estate, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState G;
    G.coins = 0;
    int maxHandCount = 10;
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



    printf ("TESTING Baron:\n");

    int it = 0;
    int failure = 0;
    int pass = 0;

    int runs = randNum(10000,1000000);
    for(int count = 0; count <runs; count++)
    {
        seed = randNum(10,1000);
        memset(&G, 23, sizeof(struct gameState)); // set the game state
        r = initializeGame(2, k, seed, &G); 
        int init = G.supplyCount[1];
        it++;
        int choice1 = randNum(0,1);
        int p = randNum(0,10);
        

        playCardBaron(baron, choice1, &G, p, 0);
        printf("Iteration: %d ", it);
        if((choice1 == 0) && 
        (supplyCount(1, &G) > 0) && 
        (supplyCount(1, &G) == (init-1)))
        {
            failure++;
            printf("Expected cards: %d supply count: %d TEST FAILURE # %d\n",(init-1), supplyCount(1, &G), failure);
        }

        else
        {
            pass++;            
            printf("Expected cards: %d supply count: %d TEST PASS # %d\n",init, supplyCount(1, &G), pass);
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