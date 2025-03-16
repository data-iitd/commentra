#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *input_array[100];
    int i, result = 0;

    // Reading input and splitting it into an array of strings
    for (i = 0; i < 100; i++)
    {
        input_array[i] = (char *)malloc(100 * sizeof(char));
        scanf("%s", input_array[i]);
    }

    // Iterating through the array and updating the result
    for (i = 0; i < 100; i++)
    {
        result += 1;  // Incrementing the result for each element
        if (strcmp(input_array[i], "0") == 0) break;  // Breaking the loop if a zero is encountered
    }

    printf("%d\n", result);  // Printing the result to the console

    // Freeing the memory allocated for the array
    for (i = 0; i < 100; i++)
    {
        free(input_array[i]);
    }

    return 0;
}

