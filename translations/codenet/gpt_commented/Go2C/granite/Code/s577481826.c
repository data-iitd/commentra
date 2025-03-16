
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Set the scanner to split input by whitespace (words)
    char buf[1024];
    fgets(buf, sizeof(buf), stdin);
    char *token = strtok(buf, " \n");

    // Read two integers from input and convert them from string to int
    int a = atoi(token);
    token = strtok(NULL, " \n");
    int b = atoi(token);

    // Initialize ret with the sum of a and b
    int ret = a + b;

    // Check if ret is less than the difference of a and b
    if (ret < (a - b)) {
        ret = a - b; // Update ret to the difference if it's smaller
    }
    // Check if ret is less than the product of a and b
    if (ret < (a * b)) {
        ret = a * b; // Update ret to the product if it's smaller
    }

    // Print the final result
    printf("%d\n", ret);

    return 0;
}
