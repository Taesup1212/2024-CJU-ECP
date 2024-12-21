#include <stdio.h>
#include <math.h>
#include <string.h>

// Instructions for use when starting the program (프로그램 시작 시 사용방법 안내)
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
// Calculates the velocity at the second point using Bernoulli's equation with height difference (베르누이 방정식을 이용하여 두 번째 지점의 속도를 계산)

int main() {
    double pressure[2], density, velocity1, velocity2, height1, height2;
    // Variables to store inputs and results for the calculation (계산을 위한 입력값 및 결과 저장 변수)

    int user_option; // Variable to store the user's choice (사용자의 선택을 저장할 변수)

    calculator(); // Display the welcome message when the program starts (프로그램 시작 시 환영 메시지 출력)

    while (1) {
        // Infinite loop until the user decides to exit (사용자가 종료할 때까지 무한 루프)
        printf("Choose an option : To run the calculator → Enter 1 / To exit the calculator → Enter 2\n");
        scanf("%d", &user_option);

        if (user_option == 2) {
            // If the user chooses to exit (사용자가 종료를 선택한 경우)
            printf("Exiting the program... \n");
            break; // Exit the loop and end the program (루프를 종료하고 프로그램 종료)
        }
        else if (user_option != 1) {
            // Handle invalid input (잘못된 입력 처리)
            printf("Invalid choice! Please enter 1 or 2.\n\n");
            continue; // Return to the start of the loop (루프 처음으로 돌아감)
        }

        printf("=== [Fluid Calculation] ===\n");

        printf("Enter the pressure at the first point (Pa): ");
        scanf("%lf", &pressure[0]);

        printf("Enter the pressure at the second point (Pa): ");
        scanf("%lf", &pressure[1]);

        printf("Enter the fluid density (kg/m³): ");
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

    // Rearrange Bernoulli's equation: v2² = (P1 - P2 + ρg(h1 - h2)) / (0.5 * ρ) + v1²
    double g = 9.81; // Gravitational acceleration (m/s²)
    velocity2_squared = (pressure1 - pressure2 + density * g * (height1 - height2)) / (0.5 * density) + pow(velocity1, 2);

    if (velocity2_squared < 0) {
        return -1; // Return error value if the calculation is invalid (계산이 유효하지 않을 경우 오류 값 반환)
    }

    return sqrt(velocity2_squared); // Return the velocity at the second point (두 번째 지점의 속도를 반환)
}