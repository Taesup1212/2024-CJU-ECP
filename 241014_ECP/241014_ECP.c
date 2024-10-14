#include <stdio.h>

int main(void) 
{
    char n; // Specify '+, -, /, *' as the character
    int a, b;

    printf("Input the formula (ex: 5+5) : ");
    scanf_s("%d %c %d", &a, &n, 1, &b);

    if (n == '+') 
    {
        printf("\n%d", a + b);
    }
    else if (n == '-') 
    {
        printf("\n%d", a - b);
    }
    else if (n == '/') 
    {
        printf("\n%d", a / b);
    }
    else if (n == '*') 
    {
        printf("\n%d", a * b);
    }
    else 
    {
        printf("Wrong Input");
    }

    return 0;
}


