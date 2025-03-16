#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n; // Initialize variable to store the number of elements
    scanf("%d", &n); // Read the number of elements
    int ara[n]; // Initialize array to store elements
    int map[n]; // Initialize array to count occurrences of each element

    // Populate the array and the map with element counts
    for (int i = 0; i < n; i++) {
        scanf("%d", &ara[i]);
        if (map[ara[i]] == 0) {
            map[ara[i]] = 1; // Initialize count for new element
        } else {
            map[ara[i]]++; // Increment count for existing element
        }
    }

    int max = 0; // Initialize max to track the highest frequency
    // Find the maximum frequency in the map
    for (int i = 0; i < n; i++) {
        if (map[i] > max) {
            max = map[i];
        }
    }

    int mm[n]; // Initialize array to track occurrences as elements appear
    // Find the most frequent element
    for (int i = 0; i < n; i++) {
        if (mm[ara[i]] == 0) {
            mm[ara[i]] = 1; // Initialize count for new element
            if (mm[ara[i]] == max) {
                printf("%d\n", ara[i]); // Print the most frequent element
                break; // Exit the loop after finding the most frequent element
            }
        } else {
            mm[ara[i]]++; // Increment count for existing element
            if (mm[ara[i]] == max) {
                printf("%d\n", ara[i]); // Print the most frequent element
                break; // Exit the loop after finding the most frequent element
            }
        }
    }

    return 0;
}

