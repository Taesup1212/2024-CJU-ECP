// 241023-ECP-GCD_LCM_while

#include <stdio.h>

int main(void)
{
    // i1 = integer 1, i2 integer 2
    // g = greatest common divisor, l = least common multiple
    int i1, i2, g, l, a, b;

    // Input two integers
    printf("Input two integers: ");
    scanf("%d %d", &i1, &i2);

    // Setting variables to maintain initial values
    a = i1;
    b = i2;

    // Calculate greatest common divisor
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    g = a;  // Set least common multiple

    // Calculate least common multiple
    l = (i1 * i2) / g;

    // Output result
    printf("\nGreatest common divisor : %d\n", g);
    printf("Least common multiple :  %d\n", l);

    return 0;
}

