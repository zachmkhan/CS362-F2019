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
    int k[15] = {estate, gold, province , copper, silver, duchy, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
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


    printf ("TESTING Tribute:\n");
    printf("\n");

    int it = 0;
    int failure = 0;
    int pass = 0;
    int player1 = 0;
    int player2 = 1;
    int tributeRevealed[2] = {-1, -1};

    int runs = randNum(10000,1000000);
    for(int count = 0; count <runs; count++)
    {
        it++;
        seed = randNum(10,1000);
        memset(&G, 23, sizeof(struct gameState)); // set the game state
        r = initializeGame(2, k, seed, &G); 
        int init = G.coins;

        for(int count = 0; count < 4; count++)
        {
            //P1
            G.deck[0][count] = k[randNum(0,14)];
        }

        for(int count = 0; count < 4; count++)
        {
            //P2
            G.deck[1][count] = k[randNum(0,14)];
        }


        it++;

        playCardTribute(tribute, tributeRevealed, &G, 0, 0, 1);
        printf("Iteration: %d ", it);



        int flag = 0;
        for(int count = 0; count <=2; count++)
        {
            if((G.deck[0][count] == copper) ||
            (G.deck[0][count] == silver) ||
            (G.deck[0][count] == copper))
            {
                flag = 1;
            }
        }

        if(flag && (G.coins == init))
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



}

int randNum(int min, int max)
{
    return (rand()% (max - min + 1)) + min;
}