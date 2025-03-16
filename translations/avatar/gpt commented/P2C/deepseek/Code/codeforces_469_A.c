#include <stdio.h>
#include <stdlib.h>

int main() {
    int max_level;
    scanf("%d", &max_level);

    int x[100], y[100];
    int x_count, y_count;

    // Read the levels completed by player X
    scanf("%d", &x_count);
    for (int i = 0; i < x_count; i++) {
        scanf("%d", &x[i]);
    }

    // Read the levels completed by player Y
    scanf("%d", &y_count);
    for (int i = 0; i < y_count; i++) {
        scanf("%d", &y[i]);
    }

    // Remove the first element from both arrays, which represents the count of levels
    for (int i = 0; i < x_count; i++) {
        x[i] = x[i + 1];
    }
    for (int i = 0; i < y_count; i++) {
        y[i] = y[i + 1];
    }

    // Create a set to eliminate duplicates
    int x_set[100] = {0}, y_set[100] = {0};
    int x_size = 0, y_size = 0;

    // Add levels to the set for player X
    for (int i = 0; i < x_count - 1; i++) {
        int found = 0;
        for (int j = 0; j < x_size; j++) {
            if (x[i] == x_set[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            x_set[x_size++] = x[i];
        }
    }

    // Add levels to the set for player Y
    for (int i = 0; i < y_count - 1; i++) {
        int found = 0;
        for (int j = 0; j < y_size; j++) {
            if (y[i] == y_set[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            y_set[y_size++] = y[i];
        }
    }

    // Check if player X has completed level 0, if so, remove it from the set
    for (int i = 0; i < x_size; i++) {
        if (x_set[i] == 0) {
            for (int j = i; j < x_size - 1; j++) {
                x_set[j] = x_set[j + 1];
            }
            x_size--;
            break;
        }
    }

    // If player X has not completed level 0, check if player Y has, and remove it if present
    for (int i = 0; i < y_size; i++) {
        if (y_set[i] == 0) {
            for (int j = i; j < y_size - 1; j++) {
                y_set[j] = y_set[j + 1];
            }
            y_size--;
            break;
        }
    }

    // Create a union of both sets to combine all unique levels completed by both players
    int z[200] = {0};
    int z_size = 0;

    // Add levels from player X to the union set
    for (int i = 0; i < x_size; i++) {
        int found = 0;
        for (int j = 0; j < z_size; j++) {
            if (x_set[i] == z[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            z[z_size++] = x_set[i];
        }
    }

    // Add levels from player Y to the union set
    for (int i = 0; i < y_size; i++) {
        int found = 0;
        for (int j = 0; j < z_size; j++) {
            if (y_set[i] == z[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            z[z_size++] = y_set[i];
        }
    }

    // Check if the number of unique levels completed matches the maximum level
    if (z_size != max_level) {
        // If not, print a message indicating that not all levels were completed
        printf("Oh, my keyboard!\n");
    } else {
        // If all levels were completed, print a success message
        printf("I become the guy.\n");
    }

    return 0;
}
