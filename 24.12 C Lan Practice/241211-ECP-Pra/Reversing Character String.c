#include <stdio.h>
#include <string.h>

// Function to reverse individual words in a string
void reverseWords(char* str)
{
    int start = 0, end = 0, len = strlen(str);

    while (end <= len)
    {
        if (str[end] == ' ' || str[end] == '\0')
        {
            int i = start, j = end - 1;
            while (i < j)
            {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
                i++;
                j--;
            }
            start = end + 1;
        }
        end++;
    }
}

int main()
{
    char input[100];

    // Prompt user for input
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Print string before removing newline
    printf("\n\nBefore removing newline: \"%s\"\n", input);

    // Remove newline character
    input[strcspn(input, "\n")] = '\0';

    // Print string after removing newline
    printf("After removing newline: \"%s\"\n", input);

    // Reverse words in the string
    reverseWords(input);

    // Print the result
    printf("\n\n[Reversed string]\n%s\n\n\n", input);

    return 0;
}