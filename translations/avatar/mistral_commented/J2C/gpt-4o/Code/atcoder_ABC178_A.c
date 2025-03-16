// Importing necessary C libraries for this program
#include <stdio.h>  // For input and output
#include <stdlib.h> // For converting strings to integers

int main() {
    // Variable to hold the user input
    int x;

    // Reading an integer value from the user input
    scanf("%d", &x);

    // Determining a boolean value based on the condition x equals to 1
    int bool = (x == 1) ? 1 : 0;

    // Calculating the result based on the boolean value
    int result = !bool ? 1 : 0;

    // Writing the result to the standard output
    printf("%d\n", result);

    return 0; // Indicating that the program ended successfully
}

// <END-OF-CODE>
