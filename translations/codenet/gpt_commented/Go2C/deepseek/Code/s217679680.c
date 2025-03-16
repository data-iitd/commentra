#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to scan an array of integers from standard input
int* scanArrayInt() {
    // Allocate memory for 100 integers
    int* ret = (int*)malloc(100 * sizeof(int));
    int index = 0;
    char buffer[100];
    
    // Read a line from standard input
    fgets(buffer, sizeof(buffer), stdin);
    
    // Tokenize the input line
    char* token = strtok(buffer, " ");
    while (token != NULL) {
        // Convert the token to an integer and store it in the array
        ret[index++] = atoi(token);
        token = strtok(NULL, " ");
    }
    
    // Return the array of integers
    return ret;
}

int main() {
    // Read an array of integers from standard input
    int* arr = scanArrayInt();
    // Assign the first two elements of the array to variables a and b
    int a = arr[0];
    int b = arr[1];
    // Initialize the number of taps needed to 0
    int tap = 0;
    // Initialize the consent variable to 1 (the starting point)
    int consent = 1;
    
    // Loop until the consent value is less than b
    while (consent < b) {
        // Update consent by adding (a - 1) to it
        consent = consent + a - 1;
        // Increment the tap count
        tap++;
    }
    
    // Print the total number of taps needed
    printf("%d\n", tap);
    
    // Free the allocated memory
    free(arr);
    
    return 0;
}
