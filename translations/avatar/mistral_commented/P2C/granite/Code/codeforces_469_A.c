
#include <stdio.h>
#include <stdlib.h>

int main() {
    // User inputs the maximum level of the set
    int max_level;
    scanf("%d", &max_level);

    // User inputs two lists, x and y, separated by a newline
    int x_size, y_size;
    scanf("%d", &x_size);
    int *x = (int *)malloc(x_size * sizeof(int));
    for (int i = 0; i < x_size; i++) {
        scanf("%d", &x[i]);
    }
    scanf("%d", &y_size);
    int *y = (int *)malloc(y_size * sizeof(int));
    for (int i = 0; i < y_size; i++) {
        scanf("%d", &y[i]);
    }

    // Remove the first element from both lists, as they are not part of the sets
    x_size--;
    y_size--;

    // Convert both lists to sets for faster set operations
    int *x_set = (int *)malloc(x_size * sizeof(int));
    int x_set_size = 0;
    for (int i = 0; i < x_size; i++) {
        if (x[i]!= 0) {
            x_set[x_set_size++] = x[i];
        }
    }
    int *y_set = (int *)malloc(y_size * sizeof(int));
    int y_set_size = 0;
    for (int i = 0; i < y_size; i++) {
        if (y[i]!= 0) {
            y_set[y_set_size++] = y[i];
        }
    }

    // Combine both sets into a new set z
    int *z = (int *)malloc((x_set_size + y_set_size) * sizeof(int));
    int z_size = 0;
    for (int i = 0; i < x_set_size; i++) {
        z[z_size++] = x_set[i];
    }
    for (int i = 0; i < y_set_size; i++) {
        z[z_size++] = y_set[i];
    }

    // Check if the size of the combined set is equal to the maximum level
    if (z_size!= max_level) {
        // If not, print an error message
        printf("Oh, my keyboard!\n");
    }
    // Else, print a success message
    else {
        printf("I become the guy.\n");
    }

    // Free memory
    free(x);
    free(y);
    free(x_set);
    free(y_set);
    free(z);

    return 0;
}
