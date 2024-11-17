#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SIZE 10 // Define size as a macro

void generateRandomNumbers(int arr[], int size, int min, int max) 
{
    for (int i = 0; i < size; i++) 
    {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

int calculateSum(int arr[], int size) 
{
    int sum = 0;
    for (int i = 0; i < size; i++) 
    {
        sum += arr[i];
    }
    return sum;
}

double calculateMean(int sum, int size) 
{
    return (double)sum / size;
}

double calculateVariance(int arr[], int size, double mean) 
{
    double variance = 0.0;
    for (int i = 0; i < size; i++) 
    {
        double diff = arr[i] - mean;
        variance += diff * diff;
    }
    return variance / size;
}

double calculateStandardDeviation(double variance) 
{
    return sqrt(variance);
}

int main() 
{
    int numbers[SIZE];
    int min, max;
    int sum;
    double mean, variance, stddev;

    srand(time(NULL));

    printf("Enter the minimum value: ");
    scanf("%d", &min);
    printf("Enter the maximum value: ");
    scanf("%d", &max);

    if (min > max) 
    {
        printf("Invalid range. Minimum should be less than or equal to Maximum.\n");
        return 1;
    }

    generateRandomNumbers(numbers, SIZE, min, max);

    printf("\nGenerated numbers: ");
    for (int i = 0; i < SIZE; i++) 
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    sum = calculateSum(numbers, SIZE);
    mean = calculateMean(sum, SIZE);
    variance = calculateVariance(numbers, SIZE, mean);
    stddev = calculateStandardDeviation(variance);

    printf("\nSum: %d\n", sum);
    printf("Mean: %.2f\n", mean);
    printf("Variance: %.2f\n", variance);
    printf("Standard Deviation: %.2f\n", stddev);

    return 0;
}
