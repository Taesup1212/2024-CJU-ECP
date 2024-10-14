#include <stdio.h>

int main(void)
{
	double l = 0.0;

	printf("input values : (l)\n");
	scanf_s("%lf", &l);
	printf("area of diagram : (A: %.2lf, B: %.2lf, C: %.2lf, D: %.2lf, E: %.2lf)\n", 0.433 * l * l, l * l, 3.141 * l * l, 4.188 * l * l * l, 12.566 * l * l);

	return 0;
}

/*
A = Area of Triangle / B = Area of Square / C = Area of Circle / D = S of Sphere / E = V of Sphere / l = Corner or Radius
*/