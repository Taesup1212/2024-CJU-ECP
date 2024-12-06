#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// Function to print the array
void PrintArray(float* arr, int size, const char* message)
{
    printf("%s\n", message);
    for (int i = 0; i < size; i++)
    {
        printf("%.2f  /  ", arr[i]);
    }
    printf("\n");
}

// Function to sort the array in ascending or descending order
void CalcSortArray(float* arr, int size, int order)
{
    // Sorting in ascending order (order == 1)
    if (order == 1)
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (arr[i] > arr[j])
                {
                    // Swap arr[i] and arr[j]
                    float temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    // Sorting in descending order (order == 0)
    else if (order == 0)
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (arr[i] < arr[j])
                {
                    // Swap arr[i] and arr[j]
                    float temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
}

int main()
{
    int size = SIZE; // Array size
    float* arr = (float*)malloc(size * sizeof(float));  // Dynamic memory allocation

    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;  // Exit if memory allocation fails
    }

    // Seed for random number generation
    srand(time(NULL));

    // Generate random numbers between -100.0 and 100.0
    for (int i = 0; i < size; i++)
    {
        arr[i] = (rand() % 201 - 100) + (rand() % 100) / 100.0f;  // Range: -100.0 to 100.0
    }

    // Print the array before sorting
    PrintArray(arr, size, "[Original Array]");

    // Ask user for sorting order
    int order;
    printf("\n\n\nEnter sorting order (1 for Ascending, 0 for Descending): ");
    char input[10];
    fgets(input, sizeof(input), stdin);  // Using fgets to read input safely
    sscanf(input, "%d", &order);  // Convert input to integer

    // Call CalcSortArray function to sort the array based on user input
    CalcSortArray(arr, size, order);

    // Print the sorted array
    if (order == 1)
    {
        PrintArray(arr, size, "\n\n[Ascending Array]");
    }
    else
    {
        PrintArray(arr, size, "\n\n[Descending Array]");
    }

    // Free dynamically allocated memory
    free(arr);

    return 0;
}