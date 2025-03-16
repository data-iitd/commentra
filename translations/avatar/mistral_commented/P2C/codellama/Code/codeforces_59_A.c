#include <stdio.h>
#include <string.h>

int main()
{
    // Get the text input from the user
    char txt[100];
    printf("Enter a string: ");
    scanf("%s", txt);

    // Initialize the count of uppercase and lowercase characters
    int cu = 0, cl = 0;

    // Iterate through each character in the text input
    for (int i = 0; i < strlen(txt); i++)
    {
        // If the character is lowercase, increment the lowercase count
        if (txt[i] >= 'a' && txt[i] <= 'z')
        {
            cl++;
        }
        // If the character is uppercase, increment the uppercase count
        else
        {
            cu++;
        }
    }

    // Determine the output based on the count of uppercase and lowercase characters
    if (cu > cl)
    {
        // If there are more uppercase characters than lowercase characters, convert the entire text to uppercase
        for (int i = 0; i < strlen(txt); i++)
        {
            if (txt[i] >= 'a' && txt[i] <= 'z')
            {
                txt[i] = txt[i] - 32;
            }
        }
    }
    else
    {
        // If there are more lowercase characters than uppercase characters, convert the entire text to lowercase
        for (int i = 0; i < strlen(txt); i++)
        {
            if (txt[i] >= 'A' && txt[i] <= 'Z')
            {
                txt[i] = txt[i] + 32;
            }
        }
    }

    // Print the output
    printf("The converted string is: %s\n", txt);

    return 0;
}

