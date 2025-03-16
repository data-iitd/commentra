#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Buffer to read input
    char buffer[1000];
    // Read the first line of input (not used)
    fgets(buffer, sizeof(buffer), stdin);
    // Read the second line of input which contains space-separated integers
    fgets(buffer, sizeof(buffer), stdin);

    // Tokenize the input string
    char *token = strtok(buffer, " ");
    int dn[1000]; // Array to hold the integers
    int count = 0; // Counter for the number of integers

    // Tokenize the input string and convert to integers
    while (token != NULL) {
        dn[count] = atoi(token);
        token = strtok(NULL, " ");
        count++;
    }

    // Initialize a variable to hold the sum of products
    int sum = 0;
    // Calculate the sum of products of all unique pairs of integers
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            sum += dn[i] * dn[j]; // Multiply the pair and add to sum
        }
    }

    // Output the final sum of products
    printf("%d\n", sum);

    return 0;
}
