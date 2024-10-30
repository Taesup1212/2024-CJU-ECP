// 241030-ECP_Celsius_Fahrenheit


#include <stdio.h>

double Fa(double c) // Fa = Fahrenheit / Convert Celsius to Fahrenheit
{
	double f;
	f = 1.8 * c + 32;

	return f;
}

double Ce(double f) // Ce = Celsius / Convert Fahrenheit to Celsius

{
	double c;
	c = (f - 32) / 1.8;

	return c;
}

int main(void)
{

	int cof; // cof = Celsius or Fahrenheit
	double input;

	printf("Celsius Input 1, Fahrenheit Input 2 : ");
	scanf_s("%d", &cof);
	printf("\n");

	if (cof == 1)
	{
		printf("Input Celsius : ");
		scanf_s("%lf", &input);
		printf("Fahrenheit Converted : %f\n\n", Fa(input));
	}

	else if (cof == 2)
	{
		printf("Input Fahrenheit : ");
		scanf_s("%lf", &input);
		printf("Celsius Converted : %f\n\n", Ce(input));
	}

	return 0;
}

