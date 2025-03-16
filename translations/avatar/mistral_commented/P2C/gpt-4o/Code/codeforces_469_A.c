#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int max_level;
    scanf("%d", &max_level);

    int x[MAX_SIZE], y[MAX_SIZE];
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

    // Remove the first element from both lists
    x_size--;
    y_size--;

    // Create a set to store unique elements
    int z[MAX_SIZE];
    int z_size = 0;

    // Function to add unique elements to the set
    void add_to_set(int *set, int *set_size, int value) {
        for (int i = 0; i < *set_size; i++) {
            if (set[i] == value) {
                return; // Value already in set
            }
        }
        set[(*set_size)++] = value; // Add value to set
    }

    // Process first list
    for (int i = 0; i < x_size; i++) {
        if (x[i] != 0) {
            add_to_set(z, &z_size, x[i]);
        }
    }

    // Process second list
    for (int i = 0; i < y_size; i++) {
        if (y[i] != 0) {
            add_to_set(z, &z_size, y[i]);
        }
    }

    // Check if the size of the combined set is equal to the maximum level
    if (z_size != max_level) {
        printf("Oh, my keyboard!\n");
    } else {
        printf("I become the guy.\n");
    }

    return 0;
}
