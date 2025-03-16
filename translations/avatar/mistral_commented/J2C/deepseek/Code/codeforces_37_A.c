#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read the next integer from standard input
int readInt() {
    int num;
    scanf("%d", &num);
    return num;
}

// Main function is the entry point of the C application
int main() {
    int n = readInt(); // Read the number of integers from the standard input

    // Initialize an empty hash map with Integer keys and Integer values
    int* map = (int*)calloc(1000001, sizeof(int));
    int max = 0;

    // Iterate through the given number of integers and add each integer to the hash map with its count
    for (int i = 0; i < n; i++) {
        int val = readInt(); // Read the next integer from the standard input
        map[val]++; // Increment the count of the integer in the hash map
        if (map[val] > max) {
            max = map[val]; // Update the maximum value if the current count is greater than the maximum value
        }
    }

    // Count the number of unique integers in the hash map
    int uniqueCount = 0;
    for (int i = 0; i < 1000001; i++) {
        if (map[i] > 0) {
            uniqueCount++;
        }
    }

    // Print the maximum value and the size of the hash map
    printf("%d %d\n", max, uniqueCount);

    // Free the allocated memory for the hash map
    free(map);

    return 0;
}
