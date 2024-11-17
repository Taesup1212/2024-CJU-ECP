#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number for the computer
int generateRandomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

// Function to get a number input from the user
int getUserGuess()
{
    int guess;
    printf("Enter a number: ");
    scanf("%d", &guess);
    return guess;
}

// Up/Down game logic
void playGame(int target, int maxAttempts)
{
    int attempts = 0;
    int guess;

    while (attempts < maxAttempts)
    {
        printf("\n[Attempt %d] ", attempts + 1);
        guess = getUserGuess();
        attempts++;

        if (guess < target)
        {
            printf("Up! Enter a larger number.");
        }
        else if (guess > target)
        {
            printf("Down! Enter a smaller number.");
        }
        else
        {
            printf("Correct! You guessed it in %d attempts!\n", attempts);
            return;
        }
    }

    printf("\nYou've used all your attempts. The correct number was %d.\n", target);
}

int main()
{
    const int min = 1, max = 100; // Range of numbers
    const int maxAttempts = 10;  // Maximum number of attempts
    int target;

    // Initialize random seed
    srand(time(NULL));

    // Computer generates a number
    target = generateRandomNumber(min, max);
    printf("The computer has generated a number! (Range: %d ~ %d)\n", min, max);

    // Start the game
    playGame(target, maxAttempts);

    return 0;
}