#include <stdio.h>
#include <ctype.h> // For character manipulation functions

int main(void)
{
    char input[256];  // Array to store the input sentence
    int count = 0;    // Variable to count the number of changes

    // Prompt the user to enter a sentence
    printf("문장 입력 : ");
    fgets(input, sizeof(input), stdin); // Read the input sentence

    // Loop through each character in the input string
    for (int i = 0; input[i] != '\0'; i++)
    {
        // Check if the character is an uppercase letter
        if (isupper(input[i]))
        {
            input[i] = tolower(input[i]); // Convert to lowercase
            count++; // Increment the counter
        }
    }
    // Print the modified sentence
    printf("바뀐 문장 : %s", input);
    // Print the number of changes made
    printf("바뀐 문자 수 : %d\n", count);

    return 0;
}