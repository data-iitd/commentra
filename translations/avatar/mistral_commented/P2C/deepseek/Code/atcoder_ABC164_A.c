#include <stdio.h>

// Define the main function that takes no arguments and returns nothing
void main(void) {

    // Declare two integer variables S and W
    int S, W;

    // Get the input as a list of two integers, S and W, using the scanf function
    scanf("%d %d", &S, &W);

    // Check if the condition S <= W is true or false and print the corresponding message
    if (S <= W) {
        printf("unsafe\n");
    } else {
        printf("safe\n");
    }
}

