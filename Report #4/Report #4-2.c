#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TOTAL_NUMBERS 100 // Total numbers to generate
#define SELECT_COUNT 10   // Number of integers to select

// Function to calculate the sum of an array
long long CalSum(long long* array, int size) // Calculate Sum
{
    long long sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum;
}

// Function to calculate the variance of an array
double CalVar(long long* array, int size, double mean) // Calculate Variance
{
    double variance = 0.0;
    for (int i = 0; i < size; i++)
    {
        variance += pow(array[i] - mean, 2);
    }
    return variance / size;
}

// Function to calculate the standard deviation
double CalStaDev(double variance) // Calculate Standard Deviation
{
    return sqrt(variance);
}

int main()
{
    long long numbers[TOTAL_NUMBERS] = { 0 };
    long long selected[SELECT_COUNT] = { 0 };
    long long SI, BI; // SI: Small Integer, BI: Big Integer
    long long sum = 0;
    double mean, variance, sd; // sd: Standard Deviation

    srand(time(NULL));

    // Input the range for selecting numbers
    do
    {
        printf("[Mean / Variance / Standard Deviation Calculator]\nInput small integer first, and then input big integer. (Negative integers can be used.)\n");
        printf("\n\nInput small integer: ");
        scanf("%lld", &SI);
        printf("Input big integer: ");
        scanf("%lld", &BI);
        if (SI > BI)
        {
            printf("\nInvalid range. Please input the small integer first.\n====================================================\n");
        }
    } while (SI > BI);

    // Generate 100 random integers within the specified range
    printf("\n[Generated numbers]\n");
    for (int i = 0; i < TOTAL_NUMBERS; i++)
    {
        numbers[i] = (rand() % (BI - SI + 1)) + SI; // Generate numbers within [SI, BI]
        printf("%lld ", numbers[i]);
        if ((i + 1) % 10 == 0)
        {
            printf("\n");
        }
    }

    // Select 10 numbers randomly from the generated numbers
    printf("\n\n[Selected numbers]\n");
    for (int i = 0; i < SELECT_COUNT; i++)
    {
        int index = rand() % TOTAL_NUMBERS;
        selected[i] = numbers[index];
        printf("%lld", selected[i]);
    }

    sum = CalSum(selected, SELECT_COUNT); // Calculate sum
    mean = (double)sum / SELECT_COUNT; // Calculate mean
    variance = CalVar(selected, SELECT_COUNT, mean); // Calculate variance
    sd = CalStaDev(variance); // Calculate standard deviation

    printf("\nSum: %lld", sum);
    printf("\nMean: %.2f", mean);
    printf("\nVariance: %.2f", variance);
    printf("\nStandard Deviation: %.2f\n", sd);

    return 0;
}