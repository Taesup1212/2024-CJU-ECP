#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10
#define UNUSED_VALUE -1 // Marks unused index

// Function to separate even and odd numbers
void CalcEvenOddArray(int* arr, int* evenArr, int* oddArr)
{
    // Initialize evenArr and oddArr with UNUSED_VALUE
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        *(evenArr + i) = UNUSED_VALUE;
        *(oddArr + i) = UNUSED_VALUE;
    }

    int evenIndex = 0, oddIndex = 0;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (*(arr + i) % 2 == 0)
        {
            *(evenArr + evenIndex++) = *(arr + i);
        }
        else
        {
            *(oddArr + oddIndex++) = *(arr + i);
        }
    }
}

// Function to print an array with a message
void PrintArray(int* arr, const char* message)
{
    printf("%s\n", message);
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (*(arr + i) != UNUSED_VALUE)
        {
            printf("%d  /  ", *(arr + i));
        }
    }
    printf("\n");
}

int main()
{
    srand(time(NULL)); // Initialize random seed

    int arr[ARRAY_SIZE];
    int evenArr[ARRAY_SIZE];
    int oddArr[ARRAY_SIZE];

    // Generate random integers between 0 and 100
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        *(arr + i) = rand() % 101;
    }

    // Separate even and odd numbers
    CalcEvenOddArray(arr, evenArr, oddArr);

    // Print the original array
    PrintArray(arr, "[Array]");

    // Print even numbers
    PrintArray(evenArr, "\n\n\n[Even numbers]");

    // Print odd numbers
    PrintArray(oddArr, "\n[Odd numbers]");

    return 0;
}
