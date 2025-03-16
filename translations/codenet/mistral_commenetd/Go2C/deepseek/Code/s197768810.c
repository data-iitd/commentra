#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

// Function to read an integer from standard input
int readInt() {
    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, stdin);
    return atoi(line);
}

// Function to read a float64 from standard input
double readFloat64() {
    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, stdin);
    return atof(line);
}

// Function to read a string from standard input
char* readString() {
    char *line = NULL;
    size_t size = 0;
    getline(&line, &size, stdin);
    return line;
}

// Main function
int main() {
    // Read the number of elements n and the number of queries m from standard input
    int n = readInt();
    int m = readInt();
    // Allocate an array a of size n
    int *a = (int*)malloc(m * sizeof(int));
    // Initialize a variable sum to keep track of the sum of elements in the array
    int sum = 0;
    // Process each query
    for (int i = 0; i < m; i++) {
        // Read an integer from standard input and add it to the array a
        a[i] = readInt();
        // Add the current element to the sum
        sum += a[i];
        // Check if the sum is greater than the size of the array
        if (sum > n) {
            // If so, print -1 and exit the program
            printf("-1\n");
            free(a);
            return 0;
        }
    }
    // Print the result, which is the difference between the size of the array and the sum of its elements
    printf("%d\n", n - sum);
    // Free the allocated memory
    free(a);
    return 0;
}
