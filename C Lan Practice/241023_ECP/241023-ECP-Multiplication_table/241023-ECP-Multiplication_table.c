// 241023-ECP-Multiplication_table

#include <stdio.h>

int main(void)
{
    int i, j, ta; // ta = Multiplication table

    // Input table number
    printf("Input a table between 1 to 9 (if you input 0, output all tables) : ");
    scanf("%d", &ta);

    if (ta == 0)  // Output all multiplication table 
    {
        for (i = 1; i <= 9; i++)  // Table 1 to Table 9
        {
            printf("\n[Table %d]\n", i);
            for (j = 1; j <= 9; j++)
            {
                printf("%d * %d = %d\n", i, j, i * j);
            }
        }
    }

    else if (ta >= 1 && ta <= 9)  // Output only specific tables
    {
        printf("\n[Table %d]\n", ta);
        for (j = 1; j <= 9; j++)
        {
            printf("%d * %d = %d\n", ta, j, ta * j);
        }
    }

    else  // If inputted number is out of range
    {
        printf("Wrong Input, paste 1 to 9 (or 0). \n");
    }

    return 0;
}

