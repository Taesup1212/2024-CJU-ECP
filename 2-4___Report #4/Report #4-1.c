#include <stdio.h>

// Function to calculate cross product of two 3D vectors
void CP(float* vec1, float* vec2, float* result) // CP = Cross Product
{
    result[0] = vec1[1] * vec2[2] - vec1[2] * vec2[1];
    result[1] = vec1[2] * vec2[0] - vec1[0] * vec2[2];
    result[2] = vec1[0] * vec2[1] - vec1[1] * vec2[0];
}

// Function to calculate dot product of two 3D vectors
float DP(float* vec1, float* vec2) // DP = Dot Product
{
    return vec1[0] * vec2[0] + vec1[1] * vec2[1] + vec1[2] * vec2[2];
}

int main()
{
    // Declare two 3D vectors
    float vector1[3], vector2[3];
    float CPR[3]; // CPR = Cross Product Result
    float DPR; // DPR = Dot Product Result

    // Input values for the first vector
    printf("Enter the components of the first vector (x, y, z) (ex. 1 2 3): ");
    scanf("%f %f %f", &vector1[0], &vector1[1], &vector1[2]);

    // Input values for the second vector
    printf("Enter the components of the second vector (x, y, z) (ex. 1 2 3): ");
    scanf("%f %f %f", &vector2[0], &vector2[1], &vector2[2]);

    // Calculate dot product
    DPR = DP(vector1, vector2);

    // Calculate cross product
    CP(vector1, vector2, CPR);

    // Print results
    printf("\n\n\nCross Product: (%.2f, %.2f, %.2f)\n\n", CPR[0], CPR[1], CPR[2]);
    printf("\nDot Product: %.2f\n\n\n", DPR);

    return 0;
}