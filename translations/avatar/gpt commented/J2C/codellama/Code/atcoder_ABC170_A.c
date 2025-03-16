#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Create a BufferedReader to read input from the standard input stream
    char *input_array[100];
    int i = 0;
    while (1)
    {
        char *str = (char *)malloc(sizeof(char) * 100);
        scanf("%s", str);
        if (strcmp(str, "0") == 0)
        {
            break;
        }
        input_array[i] = str;
        i++;
    }

    // Initialize a counter to keep track of the number of non-zero inputs
    int result = 0;

    // Iterate through each string in the input array
    for (int j = 0; j < i; j++)
    {
        // Increment the counter for each input
        result += 1;

        // If the input is "0", break out of the loop
        if (strcmp(input_array[j], "0") == 0)
        {
            break;
        }
    }

    // Print the result, which is the count of non-zero inputs before the first "0"
    printf("%d\n", result);

    // Close the BufferedReader to free up resources
    // Close the PrintWriter to ensure all output is flushed and resources are freed
    return 0;
}

