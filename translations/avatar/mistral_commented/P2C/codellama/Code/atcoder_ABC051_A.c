
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input_string[100];
    char modified_string[100];
    int i, j;

    // Read a line from input using the input function
    fgets(input_string, 100, stdin);

    // Replace all commas with spaces in the input string
    for (i = 0, j = 0; input_string[i] != '\0'; i++)
    {
        if (input_string[i] != ',')
        {
            modified_string[j] = input_string[i];
            j++;
        }
        else
        {
            modified_string[j] = ' ';
            j++;
        }
    }
    modified_string[j] = '\0';

    // Print the modified string to the console
    printf("%s", modified_string);

    return 0;
}

