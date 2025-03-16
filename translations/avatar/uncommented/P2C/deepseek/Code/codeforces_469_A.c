#include <stdio.h>
#include <stdlib.h>

int main() {
    int max_level;
    int x[100], y[100];
    int i, j;
    int x_size = 0, y_size = 0;
    int z_size;
    int z[200];

    scanf("%d", &max_level);

    // Read x array
    scanf("%*d"); // Skip the first element
    while (scanf("%d", &x[x_size]) == 1) {
        x_size++;
    }

    // Read y array
    scanf("%*d"); // Skip the first element
    while (scanf("%d", &y[y_size]) == 1) {
        y_size++;
    }

    // Remove the first element from x and y
    for (i = 0; i < x_size; i++) {
        x[i] = x[i + 1];
    }
    x_size--;
    for (i = 0; i < y_size; i++) {
        y[i] = y[i + 1];
    }
    y_size--;

    // Convert arrays to sets
    int x_set[100] = {0}, y_set[100] = {0};
    for (i = 0; i < x_size; i++) {
        x_set[x[i]] = 1;
    }
    for (i = 0; i < y_size; i++) {
        y_set[y[i]] = 1;
    }

    // Remove 0 from sets if present
    if (x_set[0] == 1) {
        x_set[0] = 0;
    }
    if (y_set[0] == 1) {
        y_set[0] = 0;
    }

    // Union of sets
    z_size = 0;
    for (i = 0; i <= max_level; i++) {
        if (x_set[i] == 1 || y_set[i] == 1) {
            z[z_size++] = i;
        }
    }

    // Check if the union set size is equal to max_level
    if (z_size != max_level) {
        printf("Oh, my keyboard!\n");
    } else {
        printf("I become the guy.\n");
    }

    return 0;
}
