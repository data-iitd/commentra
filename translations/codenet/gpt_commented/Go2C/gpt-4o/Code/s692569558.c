#include <stdio.h>  // For standard input and output
#include <stdlib.h> // For memory allocation and conversion functions
#include <string.h> // For string manipulation

int main() {
    // Read the first line of input (not used)
    char buffer[1000];
    fgets(buffer, sizeof(buffer), stdin);

    // Read the second line of input which contains space-separated integers
    fgets(buffer, sizeof(buffer), stdin);

    // Split the input string into tokens
    char *token;
    int dn[100]; // Assuming a maximum of 100 integers
    int count = 0;

    // Use strtok to split the string by spaces
    token = strtok(buffer, " ");
    while (token != NULL) {
<<<<<<< HEAD
        dn[count++] = atoi(token); // Convert string to integer and store it
=======
        dn[count++] = atoi(token); // Convert string to integer and store in array
>>>>>>> 98c87cb78a (data updated)
        token = strtok(NULL, " ");
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
<<<<<<< HEAD

// <END-OF-CODE>
=======
>>>>>>> 98c87cb78a (data updated)
