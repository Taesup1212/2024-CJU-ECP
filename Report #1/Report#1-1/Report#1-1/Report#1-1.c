#include <stdio.h>

double convert_angle(double angle)
{
    double result = (angle > 180) * (angle - 360) + (angle <= 180) * angle;
    return result;
}

int main()
{
    double angle;
    printf("Enter an angle in degrees: ");
    scanf_s("%lf", &angle);

    double converted_angle = convert_angle(angle);
    printf("Converted angle: %.2f\n", converted_angle);

    return 0;
}