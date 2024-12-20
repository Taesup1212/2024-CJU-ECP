#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Coin flipping function (returns 0: Tails, 1: Heads)
int flipCoin()
{
    return rand() % 2;
}

int main()
{
    const int totalFlips = 10000;   // Number of flips
    int heads = 0;   // Count of heads
    int tails = 0;   // Count of tails

    srand(time(NULL));   // Initialize random seed

    // Use a loop to simulate coin flips
    for (int i = 0; i < totalFlips; i++)
    {
        int result = flipCoin();
        if (result == 1)
        {
            heads++;  // Increment count if it's heads
        }
        else
        {
            tails++;  // Increment count if it's tails
        }
    }

    // Calculate probabilities
    double headProbability = (double)heads / totalFlips * 100;
    double tailProbability = (double)tails / totalFlips * 100;

    // Print results
    printf("Total flips: %d\n", totalFlips);
    printf("Heads: %d times (%.2f%%)\n", heads, headProbability);
    printf("Tails: %d times (%.2f%%)\n", tails, tailProbability);

    return 0;
}