#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate sum, average, variance, and standard deviation
void calculate_statistics(int arr[], int n, double* sum, double* avg, double* variance, double* std_dev)
{
    *sum = 0;
    *avg = 0;
    *variance = 0;
    *std_dev = 0;

    for (int i = 0; i < n; i++)
    {
        *sum += arr[i];
    }

    *avg = *sum / n;

    for (int i = 0; i < n; i++)
    {
        *variance += (arr[i] - *avg) * (arr[i] - *avg);
    }

    *variance = *variance / n;
    *std_dev = sqrt(*variance);
}

int main()
{
    int n, m;

    // Step 1: Input the size of the initial array
    printf("Enter the size of the initial integer array: ");
    scanf("%d", &n);

    // Step 2: Create the array and input values (in one line)
    int* array = (int*)malloc(n * sizeof(int));  // Dynamically allocate memory for the array

    printf("Enter %d integers separated by spaces: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    // Step 3: Calculate statistics for the initial array
    double initial_sum, initial_avg, initial_variance, initial_std_dev;
    calculate_statistics(array, n, &initial_sum, &initial_avg, &initial_variance, &initial_std_dev);

    // Display the statistics for the initial array
    printf("\n[Initial Array Statistics]\n");
    printf("Sum: %.2f\n", initial_sum);
    printf("Average: %.2f\n", initial_avg);
    printf("Variance: %.2f\n", initial_variance);
    printf("Standard Deviation: %.2f\n", initial_std_dev);

    // Step 4: Input the number of additional elements
    printf("\nEnter the number of additional integers to add: ");
    scanf("%d", &m);

    // Resize the array dynamically
    array = (int*)realloc(array, (n + m) * sizeof(int));

    printf("Enter %d additional integers separated by spaces: ", m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &array[n + i]);
    }

    // Step 5: Calculate statistics for the updated array
    int total_size = n + m;
    double updated_sum, updated_avg, updated_variance, updated_std_dev;
    calculate_statistics(array, total_size, &updated_sum, &updated_avg, &updated_variance, &updated_std_dev);

    // Display the statistics for the updated array
    printf("\n[Updated Array Statistics]\n");
    printf("Sum: %.2f\n", updated_sum);
    printf("Average: %.2f\n", updated_avg);
    printf("Variance: %.2f\n", updated_variance);
    printf("Standard Deviation: %.2f\n", updated_std_dev);

    // Free the dynamically allocated memory
    free(array);

    return 0;
}