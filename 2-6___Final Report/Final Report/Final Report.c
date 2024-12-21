#include <stdio.h>
#include <math.h>
#include <string.h>

// Instructions for use when starting the program (���α׷� ���� �� ����� �ȳ�)
void calculator()
{
    printf("==========================================================================\n");
    printf("|                    Bernoulli Equation Calculator                       |\n");
    printf("==========================================================================\n");
    printf("|   This program calculates fluid velocity using Bernoulli's equation.   |\n");
    printf("|   Please input the pressures, density, velocities, and heights.        |\n");
    printf("==========================================================================\n\n\n");
}

// Function declarations
double calculate_velocity(double pressure1, double pressure2, double density, double velocity1, double height1, double height2);
// Calculates the velocity at the second point using Bernoulli's equation with height difference (�������� �������� �̿��Ͽ� �� ��° ������ �ӵ��� ���)

int main() {
    double pressure[2], density, velocity1, velocity2, height1, height2;
    // Variables to store inputs and results for the calculation (����� ���� �Է°� �� ��� ���� ����)

    int user_option; // Variable to store the user's choice (������� ������ ������ ����)

    calculator(); // Display the welcome message when the program starts (���α׷� ���� �� ȯ�� �޽��� ���)

    while (1) {
        // Infinite loop until the user decides to exit (����ڰ� ������ ������ ���� ����)
        printf("Choose an option : To run the calculator �� Enter 1 / To exit the calculator �� Enter 2\n");
        scanf("%d", &user_option);

        if (user_option == 2) {
            // If the user chooses to exit (����ڰ� ���Ḧ ������ ���)
            printf("Exiting the program... \n");
            break; // Exit the loop and end the program (������ �����ϰ� ���α׷� ����)
        }
        else if (user_option != 1) {
            // Handle invalid input (�߸��� �Է� ó��)
            printf("Invalid choice! Please enter 1 or 2.\n\n");
            continue; // Return to the start of the loop (���� ó������ ���ư�)
        }

        printf("=== [Fluid Calculation] ===\n");

        printf("Enter the pressure at the first point (Pa): ");
        scanf("%lf", &pressure[0]);

        printf("Enter the pressure at the second point (Pa): ");
        scanf("%lf", &pressure[1]);

        printf("Enter the fluid density (kg/m��): ");
        scanf("%lf", &density);

        printf("Enter the fluid velocity at the first point (m/s): ");
        scanf("%lf", &velocity1);

        printf("Enter the height at the first point (m): ");
        scanf("%lf", &height1);

        printf("Enter the height at the second point (m): ");
        scanf("%lf", &height2);

        velocity2 = calculate_velocity(pressure[0], pressure[1], density, velocity1, height1, height2);

        printf("\nResults:\n");

        if (velocity2 >= 0) {
            printf("The velocity at the second point is %.2f m/s.\n\n\n", velocity2);
        }
        else {
            printf("Error: Unable to calculate the velocity due to invalid input values.\n");
        }
    }

    return 0;
}

// Function to calculate velocity using Bernoulli's equation
double calculate_velocity(double pressure1, double pressure2, double density, double velocity1, double height1, double height2) {
    double velocity2_squared;

    // Rearrange Bernoulli's equation: v2�� = (P1 - P2 + ��g(h1 - h2)) / (0.5 * ��) + v1��
    double g = 9.81; // Gravitational acceleration (m/s��)
    velocity2_squared = (pressure1 - pressure2 + density * g * (height1 - height2)) / (0.5 * density) + pow(velocity1, 2);

    if (velocity2_squared < 0) {
        return -1; // Return error value if the calculation is invalid (����� ��ȿ���� ���� ��� ���� �� ��ȯ)
    }

    return sqrt(velocity2_squared); // Return the velocity at the second point (�� ��° ������ �ӵ��� ��ȯ)
}