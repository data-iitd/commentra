// Including necessary C libraries for this program
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declaring a variable to store the user input
    int x;

    // Reading an integer value from the user input
    scanf("%d", &x);

    // Determining a boolean value based on the condition x equals to 1
    int bool = x == 1 ? 1 : 0;

    // Calculating the result based on the boolean value
    int result = !bool ? 1 : 0;

    // Writing the result to the standard output
    printf("%d\n", result);

    // Flushing the output buffer to ensure the output is written immediately
    fflush(stdout);

    // Closing the input stream to release system resources
    fclose(stdin);

    // Closing the output stream to release system resources
    fclose(stdout);

    // Ending the program
    return 0;
}

