// 241023-ECP-GCD_LCM_do_while

#include <stdio.h>

int main(void)
{
    // n1 = integer 1, n2 = integer 2
    // g = GCD (greatest common divisior) / l = LCM (least common multiple)
    // a (n1), b (n2) - (Setting variables to maintain initial values)
    int n1, n2, g, l, a, b;

    // Input two integers
    printf("Input two integers: ");
    scanf("%d %d", &n1, &n2);

    a = n1;
    b = n2;

    // Calculate GCD
    do
    {
        int temp = b;
        b = a % b;
        a = temp;
    } 
    
    while (b != 0);
    g = a;  // Set LCM

    // Calculate LCM
    l = (n1 * n2) / g;

    // Output result
    printf("GCD: %d\n", g);
    printf("LCM: %d\n", l);

    return 0;
}

