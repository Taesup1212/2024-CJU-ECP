#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the array
void PrintArray(float* arr, int size, const char* message)
{
    printf("%s\n", message);
    for (int i = 0; i < size; i++)
    {
        // If the value is an integer (no fractional part)
        if (arr[i] == (int)arr[i])
        {
            printf("%.0f  /  ", arr[i]);  // Print as integer (no decimal)
        }
        else
        {
            printf("%.2f  /  ", arr[i]);  // Print as float with 2 decimal places
        }
    }
    printf("\n");
}

// Function to invert the array (reverse the array order)
void CalcInverseArray(float* arr, int size)
{
    // Using two-pointer technique to reverse the array in-place
    for (int i = 0; i < size / 2; i++)
    {
        float temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

int main()
{
    int size = 10; // Array size
    float* arr = (float*)malloc(size * sizeof(float)); // Dynamic memory allocation

    // Check if memory allocation is successful
    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;  // Exit the program if memory allocation fails
    }

    // Seed for random number generation
    srand(time(NULL));

    // Generate random numbers between -100.0 and 100.0, both integers and floats
    for (int i = 0; i < size; i++)
    {
        // Randomly decide whether to generate an integer or float
        if (rand() % 2 == 0)  // 50% chance for integer or float
        {
            arr[i] = rand() % 201 - 100;  // Generate integer between -100 and 100
        }
        else
        {
            arr[i] = (rand() % 201 - 100) + ((rand() % 100) / 100.0f);  // Generate float between -100.0 and 100.0
        }
    }

    // Print the array before inversion
    PrintArray(arr, size, "[Original Array]");

    // Call CalcInverseArray function to invert the array
    CalcInverseArray(arr, size);

    // Print the array after inversion
    PrintArray(arr, size, "\n\n\n[Inverted Array]");

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}