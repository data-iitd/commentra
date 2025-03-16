#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Aliasing heapq functions for convenience
#define hpop(heap) (*heap = *heap + 1)
#define hpush(heap, value) (*heap = *heap + 1)

// Counter data structure
typedef struct {
    int *keys;
    int *values;
    int size;
    int capacity;
} Counter;

// Counter functions
Counter *counter_new(int capacity) {
    Counter *counter = malloc(sizeof(Counter));
    counter->keys = malloc(capacity * sizeof(int));
    counter->values = malloc(capacity * sizeof(int));
    counter->size = 0;
    counter->capacity = capacity;
    return counter;
}

void counter_free(Counter *counter) {
    free(counter->keys);
    free(counter->values);
    free(counter);
}

void counter_add(Counter *counter, int key, int value) {
    if (counter->size == counter->capacity) {
        counter->capacity *= 2;
        counter->keys = realloc(counter->keys, counter->capacity * sizeof(int));
        counter->values = realloc(counter->values, counter->capacity * sizeof(int));
    }
    counter->keys[counter->size] = key;
    counter->values[counter->size] = value;
    counter->size++;
}

int counter_get(Counter *counter, int key) {
    for (int i = 0; i < counter->size; i++) {
        if (counter->keys[i] == key) {
            return counter->values[i];
        }
    }
    return 0;
}

// Solution function
void solution() {
    // Read the first line of input which represents the colors bought
    char *line = malloc(100 * sizeof(char));
    fgets(line, 100, stdin);
    // Count the occurrences of each color bought using Counter
    Counter *bought_count = counter_new(100);
    char *token = strtok(line, " ");
    while (token != NULL) {
        int key = atoi(token);
        int value = counter_get(bought_count, key) + 1;
        counter_add(bought_count, key, value);
        token = strtok(NULL, " ");
    }
    
    // Read the second line of input which represents the colors made
    fgets(line, 100, stdin);
    // Count the occurrences of each color made using Counter
    Counter *made_count = counter_new(100);
    token = strtok(line, " ");
    while (token != NULL) {
        int key = atoi(token);
        int value = counter_get(made_count, key) + 1;
        counter_add(made_count, key, value);
        token = strtok(NULL, " ");
    }
    
    // Initialize the result variable to store the total count of matched colors
    int res = 0;
    
    // Iterate through each color in the made_count
    for (int i = 0; i < made_count->size; i++) {
        // If a color made is not found in the bought colors, return -1
        if (counter_get(bought_count, made_count->keys[i]) == 0) {
            printf("-1\n");
            return;
        }
        // Add the minimum of the bought and made counts for each color to the result
        res += min(counter_get(bought_count, made_count->keys[i]), made_count->values[i]);
    }
    
    // Print the total count of matched colors
    printf("%d\n", res);
    
    // Free the memory allocated for the Counter data structures
    counter_free(bought_count);
    counter_free(made_count);
}

// Entry point of the program
int main() {
    // Set the number of test cases (currently set to 1)
    int t = 1;
    // Loop through each test case
    for (int i = 0; i < t; i++) {
        solution();
    }
    return 0;
}

