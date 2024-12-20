#include <stdio.h>

int main(void)
{
    int A[3] = { 1, 2, 3 };     // Initialized array A
    int B[10];                  // Uninitialized array B
    int i;

    // Loop to fill the B array with values from the A array
    for (i = 0; i < 10; i++)
    {
        B[i] = A[i % 3];        // Use modulo operator to cycle through A's indices (0, 1, 2)
    }

    // Loop to print the elements of B array
    for (i = 0; i < 10; i++)
    {
        printf("%d  ", B[i]);   // Print each element of B with double spaces
    }
    return 0;
}