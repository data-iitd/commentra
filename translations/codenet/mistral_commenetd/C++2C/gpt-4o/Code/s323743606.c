#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5001

// Structure to represent a key-value pair in the map
typedef struct {
    int key;
    int value;
} Pair;

// Function to find the index of a key in the array
int findIndex(Pair *map, int size, int key) {
    for (int i = 0; i < size; i++) {
        if (map[i].key == key) {
            return i;
        }
    }
    return -1; // Not found
}

int main() {
    Pair m[MAX_SIZE]; // Array to store key-value pairs
    int size = 0; // Current size of the map

    // Iterate through all possible indices 'i' that satisfy the condition i*200 < 5001
    for (int i = 0; i * 200 < 5001; i++) {
        // Iterate through all possible indices 'j' that satisfy the condition j*300 < 5001
        for (int j = 0; j * 300 < 5001; j++) {
            // Iterate through all possible indices 'k' that satisfy the condition k*500 < 5001
            for (int k = 0; k * 500 < 5001; k++) {
                // Calculate the composite index 'w'
                int w = i * 200 + j * 300 + k * 500;

                // Calculate the potential value 'p' for the given index 'w'
                int p = (i / 5) * 5 * 380 * 0.8 + (i % 5) * 380
                      + (j / 4) * 4 * 550 * 0.85 + (j % 4) * 550
                      + (k / 3) * 3 * 850 * 0.88 + (k % 3) * 850;

                // Check if the map already contains the index 'w'
                int index = findIndex(m, size, w);
                if (index != -1) {
                    // Update the value with the minimum of the current potential value and the existing one
                    if (m[index].value > p) {
                        m[index].value = p;
                    }
                } else {
                    // If not found, add it to the map
                    m[size].key = w;
                    m[size].value = p;
                    size++;
                }
            }
        }
    }

    // Read integers from the standard input and print their corresponding potential values from the map
    int n;
    while (scanf("%d", &n) && n) {
        int index = findIndex(m, size, n);
        if (index != -1) {
            printf("%d\n", m[index].value);
        } else {
            printf("0\n"); // If not found, print 0 (or handle as needed)
        }
    }

    return 0;
}

// <END-OF-CODE>
