#include <stdio.h>

int main(void)
{
	double ft, in, slug, m, kg = 0.0;

	printf("Input values : (ft to m, m to ft, in to m, m to in, slug to kg, kg to slug)\n");
	scanf_s("%lf %lf %lf %lf %lf %lf", &ft, &m, &in, &m, &slug, &kg);
	printf("%.2lfm, %.2lfft, %.2lfm, %.2lfin, %.2lfkg, %.2lfslug", 0.3048 * ft, 3.2808 * m, 0.0254 * in, 39.3701 * m, 14.5939 * slug, 0.0685 * kg);

	return 0;
}