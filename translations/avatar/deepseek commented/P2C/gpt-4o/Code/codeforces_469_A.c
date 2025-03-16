#include <stdio.h>
#include <stdlib.h>

#define MAX_LEVEL 100

int main() {
    int max_level;
    scanf("%d", &max_level);

    int x[MAX_LEVEL], y[MAX_LEVEL];
    int x_size, y_size;

    // Read the first list
    scanf("%d", &x_size);
    for (int i = 0; i < x_size; i++) {
        scanf("%d", &x[i]);
    }

    // Read the second list
    scanf("%d", &y_size);
    for (int i = 0; i < y_size; i++) {
        scanf("%d", &y[i]);
    }

    // Create a set to store unique levels
    int levels[MAX_LEVEL] = {0};

    // Process the first list
    for (int i = 1; i < x_size; i++) {
        if (x[i] != 0) {
            levels[x[i]] = 1; // Mark level as achieved
        }
    }

    // Process the second list
    for (int i = 1; i < y_size; i++) {
        if (y[i] != 0) {
            levels[y[i]] = 1; // Mark level as achieved
        }
    }

    // Count the number of unique levels achieved
    int unique_levels_count = 0;
    for (int i = 1; i <= max_level; i++) {
        if (levels[i] == 1) {
            unique_levels_count++;
        }
    }

    // Check if the number of unique levels equals max_level
    if (unique_levels_count != max_level) {
        printf("Oh, my keyboard!\n");
    } else {
        printf("I become the guy.\n");
    }

    return 0;
}

// <END-OF-CODE>
