#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Create a buffer to read input
    char buffer[1024];
    
    // Read the first line of input (which we will ignore)
    fgets(buffer, sizeof(buffer), stdin);
    
    // Read the second line of input
    fgets(buffer, sizeof(buffer), stdin);
    
    // Split the input string into tokens
    char *token;
    int dn[100]; // Assuming a maximum of 100 integers
    int count = 0;
    
    // Use strtok to split the string by spaces
    token = strtok(buffer, " ");
    while (token != NULL) {
<<<<<<< HEAD
        dn[count++] = atoi(token);
=======
        dn[count++] = atoi(token); // Convert to integer and store
>>>>>>> 98c87cb78a (data updated)
        token = strtok(NULL, " ");
    }
    
    // Initialize the sum variable to hold the result
    int sum = 0;
    
    // Calculate the sum of the products of all pairs of integers in the array
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            sum += dn[i] * dn[j];
        }
    }
    
    // Print the result
    printf("%d\n", sum);
    
    return 0;
}

// <END-OF-CODE>
