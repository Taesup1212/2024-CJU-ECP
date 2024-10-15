#include <stdio.h>

int main(void) 
{
    char n; // Specify '+, -, /, *' as the character
    int a, b;

    printf("Input the formula (ex: 5+5) : ");
    scanf_s("%d %c %d", &a, &n, 1, &b);

    switch (n) 
    {
    case '+':
        {
            printf("\n%d", a + b);
            break;
        }
    case '-':
        {
            printf("\n%d", a - b);
            break;
        }
    case '/':
        {
            printf("\n%d", a / b);
            break;
        }
    case '*':
        {
            printf("\n%d", a * b);
            break;
        }
    default:
        {
            printf("\nWrong Input");
            break;
        }
    }

    return 0;
}

