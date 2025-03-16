#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Utility function to read the next token
char* next_token() {
    char* token = NULL;
    size_t size = 0;
    if (getline(&token, &size, stdin) == -1) {
        free(token);
        return NULL;
    }
    return token;
}

// Utility function to read the next integer
int next_int() {
    char* token = next_token();
    int value = 0;
    if (token != NULL) {
        value = atoi(token);
        free(token);
    }
    return value;
}

// Utility function to read the next long
long next_long() {
    char* token = next_token();
    long value = 0;
    if (token != NULL) {
        value = atol(token);
        free(token);
    }
    return value;
}

// Utility function to read the next double
double next_double() {
    char* token = next_token();
    double value = 0.0;
    if (token != NULL) {
        value = atof(token);
        free(token);
    }
    return value;
}

int main() {
    // Read the number of integers
    int n = next_int();

    // Create a hash map to store the frequency of each integer
    // For simplicity, we use a fixed-size array to simulate a hash map
    int map[100001] = {0};

    // Read n integers and update their counts in the hash map
    for (int i = 0; i < n; i++) {
        int val = next_int();
        map[val]++;
    }

    // Initialize max to the smallest possible integer value
    int max = 0;

    // Iterate through the hash map to find the maximum count
    for (int i = 0; i < 100001; i++) {
        if (map[i] > max) {
            max = map[i];
        }
    }

    // Print the maximum count and the size of the hash map
    printf("%d %lu\n", max, (unsigned long)n);

    return 0;
}
