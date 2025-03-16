#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Function to read an integer from input
int readInt() {
    char line[MAX_LINE_LENGTH];
    fgets(line, sizeof(line), stdin);
    return atoi(line);
}

// Function to read a float64 from input
double readFloat64() {
    char line[MAX_LINE_LENGTH];
    fgets(line, sizeof(line), stdin);
    return atof(line);
}

// Function to read a string from input
char* readString() {
    char *line = NULL;
    size_t size = 0;
    getline(&line, &size, stdin);
    return line;
}

int main() {
    // Read two integers n and m from input
    int n = readInt();
    int m = readInt();

    // Initialize a variable to hold the sum of the integers read
    int sum = 0;

    // Initialize a array to hold m integers
    int a[m];

    // Read m integers from input and calculate their sum
    for (int i = 0; i < m; i++) {
        a[i] = readInt(); // Read an integer and store it in the array
        sum += a[i]; // Add the integer to the sum
    }

    // Check if the sum of the integers exceeds n
    if (sum > n) {
        printf("-1\n"); // Print -1 if the sum is greater than n
        return 0; // Exit the function
    }

    // Print the difference between n and the sum of the integers
    printf("%d\n", n - sum);

    return 0;
}
