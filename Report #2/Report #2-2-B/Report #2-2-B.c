// Report #2-2-B


#include <stdio.h>

int main(void)
{
    int n1, n2, re; // n1 = number 1, n2 = number 2, re = remainder

    // Input two integers
    printf("Enter the first integer: ");
    scanf("%d", &n1);

    printf("Enter the second integer: ");
    scanf("%d", &n2);

    // Check if the second integer is not 0
    if (n2 == 0)
    {
        printf("The second integer cannot be 0.\n");
        return 1; // Exit the program if n2 is 0
    }

    // Calculate the re when n1 is divided by n2
    re = n1 % n2;

    // Use switch-case to check if the re is 0 (n1 is a multiple of n2)
    switch (re)
    {
    case 0:
        printf("%d is a multiple of %d.\n", n1, n2);
        break;

    default:
        printf("%d is not a multiple of %d.\n", n1, n2);
        break;
    }

    return 0;
}