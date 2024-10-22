// Report #2-1-B


#include <stdio.h>

int main(void)
{
    int n; // n = number

    printf("Inpur integer: "); // Input an integer from the user
    scanf("%d", &n);

    // Determining even or odd

    switch (n % 2)
    {
    case 0:
        printf("%d is even.\n", n);
        break;

    default: // Including negative numbers
        printf("%d is odd.\n", n);
        break;
    }

    return 0;
}