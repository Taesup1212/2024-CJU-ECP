// Report #2-3-B


#include <stdio.h>

int main(void)
{
    float s; // s = score
    int g; // g = grade

    // Input score
    printf("Input a score (0.0 ~ 100.0): ");
    scanf("%f", &s);

    // Check if the input is within the valid range
    if (s < 0.0 || s > 100.0)
    {
        printf("Invalid score. Please enter a value between 0.0 and 100.0.\n");
        return 1; // Exit the program if the input is out of range
    }

    // Determine the grade by dividing the score into blocks of 10
    g = (int)(s / 10); // Integer division for switch case

    // Use switch-case to determine the grade
    switch (g)
    {
    case 10: // Handle case for s = 100
    case 9:
        printf("Grade: A\n");
        break;

    case 8:
        printf("Grade: B\n");
        break;

    case 7:
        printf("Grade: C\n");
        break;

    case 6:
        printf("Grade: D\n");
        break;

    default:
        printf("Grade: F\n");
        break;
    }

    return 0;
}

