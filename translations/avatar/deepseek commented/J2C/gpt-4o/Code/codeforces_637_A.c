#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

// Structure to hold the frequency of elements
typedef struct {
    int value;
    int count;
} Element;

int main() {
    int n;
    scanf("%d", &n); // Read the number of elements

    int ara[MAX_SIZE]; // Array to store elements
    Element map[MAX_SIZE]; // Array to count occurrences of each element
    int mapSize = 0; // Size of the map

    // Populate the array and the map with element counts
    for (int i = 0; i < n; i++) {
        int v;
        scanf("%d", &v);
        ara[i] = v;

        // Check if the element is already in the map
        int found = 0;
        for (int j = 0; j < mapSize; j++) {
            if (map[j].value == v) {
                map[j].count++; // Increment count for existing element
                found = 1;
                break;
            }
        }
        if (!found) {
            // Initialize count for new element
            map[mapSize].value = v;
            map[mapSize].count = 1;
            mapSize++;
        }
    }

    int max = 0; // Initialize max to track the highest frequency
    // Find the maximum frequency in the map
    for (int i = 0; i < mapSize; i++) {
        if (map[i].count > max) {
            max = map[i].count;
        }
    }

    // Find the most frequent element
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < mapSize; j++) {
            if (ara[i] == map[j].value && map[j].count == max) {
                printf("%d\n", ara[i]); // Print the most frequent element
                return 0; // Exit the program after finding the most frequent element
            }
        }
    }

    return 0; // Return success
}

// <END-OF-CODE>
