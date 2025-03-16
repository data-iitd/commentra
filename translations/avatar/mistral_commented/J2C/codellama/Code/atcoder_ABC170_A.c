
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Declaring and initializing variables
    char *input_array[100];
    int i = 0, result = 0;

    // Reading input array from the console
    while (scanf("%s", input_array[i]) != EOF)
    {
        // Incrementing result variable for each non-zero string encountered
        if (strcmp(input_array[i], "0") != 0)
        {
            result++;
        }
        // Breaking the loop if a zero string is encountered
        else
        {
            break;
        }
        i++;
    }

    // Writing the result to the console
    printf("%d\n", result);

    // Closing the input stream
    fclose(stdin);

    // Closing the output stream
    fclose(stdout);

    // Ending the program
    return 0;
}

