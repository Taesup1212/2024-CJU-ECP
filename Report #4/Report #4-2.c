#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TOTAL_NUMBERS 100 // Total numbers to generate
#define SELECT_COUNT 10   // Number of integers to select

// Function to calculate the sum of an array
long long CalSum(long long* array, int size)  // Calculate Sum
{
    long long sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum;
}

// Function to calculate the variance of an array
double CalVar(long long* array, int size, double mean)  // Calculate Variance
{
    double variance = 0.0;
    for (int i = 0; i < size; i++)
    {
        variance += pow(array[i] - mean, 2);
    }
    return variance / size;
}

// Function to calculate the standard deviation
double CalStaDev(double variance)  // Calculate Standard Deviation 
{
    return sqrt(variance);
}

int main()
{
    long long numbers[TOTAL_NUMBERS]; // Array to store 100 random integers
    long long selected[SELECT_COUNT]; // Array to store 10 selected integers
    long long SI, BI; // Variables to store range,  // SI : Small Integer, BI : Big Integer
    long long sum = 0;
    double mean, variance, sd;  // sd: Standard Deviation

    // Initialize random number generator
    srand(time(NULL));

    // Input the range for selecting numbers
    do {
        printf("[Mean / Variance / Standard Deviation Calculator]\nInput small integer first, and then input big integer. (Negative integers can be used.)\n");
        printf("\n\nInput small integer: ");
        scanf("%lld", &SI);
        printf("\nInput big integer: ");
        scanf("%lld", &BI);
        if (SI > BI)
        {
            printf("\n\nInvalid range. Please input the small integer first.\n\n\n");
        }
    } while (SI > BI);

    // Generate 100 random integers, ensuring at least 10 are in the range
    int guaranteedCount = 0;
    for (int i = 0; i < TOTAL_NUMBERS; i++)
    {
        if (guaranteedCount < SELECT_COUNT)
        {
            // Ensure at least 10 numbers are within the range
            numbers[i] = (rand() % (BI - SI + 1)) + SI;
            guaranteedCount++;
        }
        else
        {
            // Generate numbers in the broader range [-50000, 50000]
            numbers[i] = (rand() % 100001) - 50000;
        }
    }

    // Select numbers within the specified range
    int count = 0;
    for (int i = 0; i < TOTAL_NUMBERS && count < SELECT_COUNT; i++)
    {
        if (numbers[i] >= SI && numbers[i] <= BI)
        {
            selected[count] = numbers[i];
            count++;
        }
    }

    // Calculate sum
    sum = CalSum(selected, SELECT_COUNT);

    // Calculate mean
    mean = (double)sum / SELECT_COUNT;

    // Calculate variance
    variance = CalVar(selected, SELECT_COUNT, mean);

    // Calculate standard deviation
    sd = CalStaDev(variance);

    // Display results
    printf("\n\n\nSelected numbers: ");
    for (int i = 0; i < SELECT_COUNT; i++)
    {
        printf("%lld ", selected[i]);
    }
    printf("\nSum: %lld", sum);
    printf("\nMean: %.2f", mean);
    printf("\nVariance: %.2f", variance);
    printf("\nStandard Deviation: %.2f\n", sd);

    return 0;
}