#include <stdio.h>
#include <stdlib.h>

int main() {
    int max_level;
    scanf("%d", &max_level);

    int x[100], y[100];
    int x_size = 0, y_size = 0;

    // Read the first list (not used, so discard it)
    scanf("%*d");
    for (int i = 0; i < max_level; i++) {
        scanf("%d", &x[i]);
        if (x[i] != 0) {
            x_size++;
        }
    }

    // Read the second list (not used, so discard it)
    scanf("%*d");
    for (int i = 0; i < max_level; i++) {
        scanf("%d", &y[i]);
        if (y[i] != 0) {
            y_size++;
        }
    }

    // Create sets for x and y
    int x_set[x_size], y_set[y_size];
    int x_index = 0, y_index = 0;

    for (int i = 0; i < max_level; i++) {
        if (x[i] != 0) {
            x_set[x_index++] = x[i];
        }
        if (y[i] != 0) {
            y_set[y_index++] = y[i];
        }
    }

    // Combine both sets into a new set z
    int z[100];
    int z_size = 0;

    // Add elements from x_set to z
    for (int i = 0; i < x_size; i++) {
        int is_duplicate = 0;
        for (int j = 0; j < z_size; j++) {
            if (z[j] == x_set[i]) {
                is_duplicate = 1;
                break;
            }
        }
        if (!is_duplicate) {
            z[z_size++] = x_set[i];
        }
    }

    // Add elements from y_set to z
    for (int i = 0; i < y_size; i++) {
        int is_duplicate = 0;
        for (int j = 0; j < z_size; j++) {
            if (z[j] == y_set[i]) {
                is_duplicate = 1;
                break;
            }
        }
        if (!is_duplicate) {
            z[z_size++] = y_set[i];
        }
    }

    // Check if the size of the combined set is equal to the maximum level
    if (z_size != max_level) {
        // If not, print an error message
        printf("Oh, my keyboard!\n");
    } else {
        // Else, print a success message
        printf("I become the guy.\n");
    }

    return 0;
}
