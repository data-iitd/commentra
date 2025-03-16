

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Set the split function for the scanner to words
    char input[100];
    fgets(input, 100, stdin);

    // Read the first integer from input
    int a = atoi(input);
    // Read the second integer from input
    fgets(input, 100, stdin);
    int b = atoi(input);

    // Perform addition of the two integers
    int ret = a + b;

    // Check if the result is less than the difference between the two integers
    if (ret < (a - b)) {
        ret = a - b;
    }
    // Check if the updated result is less than the product of the two integers
    if (ret < (a * b)) {
        ret = a * b;
    }

    // Print the final result
    printf("%d\n", ret);

    return 0;
}
