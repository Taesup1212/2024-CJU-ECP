// Report #2-3-A


#include <stdio.h>

int main(void)
{
    float s; // s = score

    // Input a score
    printf("Input a score (0.0 ~ 100.0): ");
    scanf("%f", &s);

    // Check if the input is within the valid range
    if (s < 0.0 || s > 100.0)
    {
        printf("Invalid s. Please enter a value between 0.0 and 100.0.\n");
        return 1; // Exit the program if the input is out of range
    }

    // Use if-else conditions to determine the grade
    if (s >= 90.0)
    {
        printf("Grade: A\n");
    }
    else if (s >= 80.0)
    {
        printf("Grade: B\n");
    }
    else if (s >= 70.0)
    {
        printf("Grade: C\n");
    }
    else if (s >= 60.0)
    {
        printf("Grade: D\n");
    }
    else
    {
        printf("Grade: F\n");
    }

    return 0;
}