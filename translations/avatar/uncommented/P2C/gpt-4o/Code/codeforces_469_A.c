#include <stdio.h>
#include <stdlib.h>

#define MAX_LEVEL 100

int main() {
    int max_level;
    scanf("%d", &max_level);

    int x[MAX_LEVEL], y[MAX_LEVEL];
    int x_count, y_count;

    // Read x levels
    scanf("%d", &x_count);
    for (int i = 0; i < x_count; i++) {
        scanf("%d", &x[i]);
    }

    // Read y levels
    scanf("%d", &y_count);
    for (int i = 0; i < y_count; i++) {
        scanf("%d", &y[i]);
    }

    // Create a set for levels
    int z[MAX_LEVEL] = {0}; // To track unique levels
    int z_count = 0;

    // Add levels from x to z
    for (int i = 0; i < x_count; i++) {
        if (x[i] != 0) {
            if (!z[x[i]]) {
                z[x[i]] = 1;
                z_count++;
            }
        }
    }

    // Add levels from y to z
    for (int i = 0; i < y_count; i++) {
        if (y[i] != 0) {
            if (!z[y[i]]) {
                z[y[i]] = 1;
                z_count++;
            }
        }
    }

    // Check if the number of unique levels is equal to max_level
    if (z_count != max_level) {
        printf("Oh, my keyboard!\n");
    } else {
        printf("I become the guy.\n");
    }

    return 0;
}

// <END-OF-CODE>
