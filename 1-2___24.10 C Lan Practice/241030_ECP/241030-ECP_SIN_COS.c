// 241030-ECP_SIN_COS


#include <stdio.h>
#include <math.h>
#define PI 3.14159265

// SIN value calculation function
double calculateSin(double degree)
{
    return sin(degree * PI / 180.0);  // Convert degree to radian
}

// COS value calculation function
double calculateCos(double degree)
{
    return cos(degree * PI / 180.0);  // Convert degree to radian
}

int main()
{
    double degree;

    printf("Input degree 0 to 180 : ");
    scanf("%lf", &degree);

    // Check if input value is between 0 to 180
    if (degree < 0 || degree > 180)
    {
        printf("Wrong Input. Input degree 0 to 180.\n");
    }
    else
    {
        double sinValue = calculateSin(degree);
        double cosValue = calculateCos(degree);

        printf("sin(%.2lf) = %.4lf\n", degree, sinValue);
        printf("cos(%.2lf) = %.4lf\n", degree, cosValue);
    }

    return 0;
}

