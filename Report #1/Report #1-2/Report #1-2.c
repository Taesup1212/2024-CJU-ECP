/*
I: money inputted / P: Price / C: Change
*/

#include <stdio.h>

int main()
{
    int I, P, C;
    int won_1000, won_500, won_100;

    // Entering the money inputted and the price of goods
    printf("Input: ");
    scanf("%d", &I);
    printf("Price of goods: ");
    scanf("%d", &P);

    // Calculating Change
    C = I - P;
    printf("\nRemaining amount: %d\n\n", C);

    // Calculating the number of 1000 won, 500 won, and 100 won
    won_1000 = C / 1000;
    C %= 1000;

    won_500 = C / 500;
    C %= 500;

    won_100 = C / 100;
    C %= 100;

    // Result Output
    printf("[Change]\n");
    printf("1000W Bill: %d / ", won_1000);
    printf("500W Coin: %d / ", won_500);
    printf("100W Coin: %d", won_100);

    return 0;
}

