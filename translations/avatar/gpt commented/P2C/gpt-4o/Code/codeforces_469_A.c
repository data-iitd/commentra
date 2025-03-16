#include <stdio.h>
#include <stdlib.h>

#define MAX_LEVEL 100

int main() {
    int max_level;
    scanf("%d", &max_level);

    int x[MAX_LEVEL], y[MAX_LEVEL];
    int x_count, y_count;

    // Read levels completed by player X
    scanf("%d", &x_count);
    for (int i = 0; i < x_count; i++) {
        scanf("%d", &x[i]);
    }

    // Read levels completed by player Y
    scanf("%d", &y_count);
    for (int i = 0; i < y_count; i++) {
        scanf("%d", &y[i]);
    }

    // Remove duplicates using a simple array to track completed levels
    int completed[MAX_LEVEL] = {0};

    // Process player X's levels
    for (int i = 0; i < x_count; i++) {
        if (x[i] != 0) {
            completed[x[i]] = 1;
        }
    }

    // Process player Y's levels
    for (int i = 0; i < y_count; i++) {
        if (y[i] != 0) {
            completed[y[i]] = 1;
        }
    }

    // Check if level 0 was completed
    if (completed[0]) {
        completed[0] = 0; // Remove level 0 if completed
    }

    // Count unique levels completed
    int unique_count = 0;
    for (int i = 0; i < max_level; i++) {
        if (completed[i]) {
            unique_count++;
        }
    }

    // Check if all levels were completed
    if (unique_count != max_level) {
        printf("Oh, my keyboard!\n");
    } else {
        printf("I become the guy.\n");
    }

    return 0;
}
