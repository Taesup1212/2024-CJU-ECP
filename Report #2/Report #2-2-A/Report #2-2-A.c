// Report #2-2-A


#include <stdio.h>

int main(void)
{
    int n1, n2; // n1 = number 1, n2 = number 2

    // Input two integers
    printf("Enter the first integer: ");
    scanf("%d", &n1);

    printf("Enter the second integer: ");
    scanf("%d", &n2);

    // Check if the second integer is not zero and if num1 is a multiple of num2
    if (n2 != 0)
    {
        if (n1 % n2 == 0)
        {
            printf("%d is a multiple of %d.\n", n1, n2);
        }
        else
        {
            printf("%d is not a multiple of %d.\n", n1, n2);
        }
    }

    else
    {
        printf("The second integer cannot be 0.\n");
    }

    return 0;
}

