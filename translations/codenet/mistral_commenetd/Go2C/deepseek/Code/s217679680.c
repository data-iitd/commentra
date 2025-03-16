#include <stdio.h>
#include <stdlib.h>

// Function to read an array of integers from stdin and return it
int* scanArrayInt() {
    // Initialize an array to store the integers
    int* ret = (int*)malloc(100 * sizeof(int));
    int i = 0;
    // Read the input line from stdin
    while (scanf("%d", &ret[i]) != EOF) {
        i++;
    }
    // Return the array of integers
    return ret;
}

// Function to initialize variables and start the main logic
int main() {
    // Read the array of integers from stdin
    int* arr = scanArrayInt();
    // Initialize variables a and b with the first two elements of the array
    int a = arr[0];
    int b = arr[1];
    // Initialize variables tap and consent with default values
    int tap = 0;
    int consent = 1;
    // Loop until consent is greater than or equal to b
    while (consent < b) {
        // Increment consent by the sum of a and consent minus one
        consent = consent + a - 1;
        // Increment tap by one for each iteration
        tap++;
    }
    // Print the result, i.e., the number of taps required
    printf("%d\n", tap);
    // Free the allocated memory
    free(arr);
    return 0;
}
