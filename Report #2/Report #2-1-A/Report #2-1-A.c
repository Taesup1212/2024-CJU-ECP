// Report #2-1-A


#include <stdio.h>

int main(void)
{
    int n; // n = number

    printf("Input integer: ");  // Input an integer from the user
    scanf("%d", &n);

    // Determining even or odd

    if (n % 2 == 0)
    {
        printf("%d is even.\n", n);
    }
    else
    {
        printf("%d is odd.\n", n);
    }

    return 0;
}

