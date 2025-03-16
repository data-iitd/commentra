#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    double input;
    double countOdd;
    double result;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    // Create a BufferedReader to read input from the console
    // Read a line of input and parse it as a double
    read = getline(&line, &len, stdin);
    if (read == -1)
    {
        printf("Error reading input\n");
        exit(1);
    }
    input = atof(line);

    // Calculate the count of odd numbers based on the input
    countOdd = round(input / 2);

    // Create a BigDecimal to hold the result of the division
    result = countOdd / input;

    // Set the scale of the result to 10 decimal places, rounding half up
    result = round(result * 1000000000) / 1000000000;

    // Print the result to the console
    printf("%f\n", result);

    // Free the memory allocated by getline
    free(line);

    // End of code
    printf("