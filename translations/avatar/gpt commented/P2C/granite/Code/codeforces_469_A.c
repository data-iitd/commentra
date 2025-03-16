
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the maximum level from user input
    int max_level;
    scanf("%d", &max_level);

    // Read the levels completed by player X and convert them to an array of integers
    int x_count;
    scanf("%d", &x_count);
    int x[x_count];
    for (int i = 0; i < x_count; i++) {
        scanf("%d", &x[i]);
    }

    // Read the levels completed by player Y and convert them to an array of integers
    int y_count;
    scanf("%d", &y_count);
    int y[y_count];
    for (int i = 0; i < y_count; i++) {
        scanf("%d", &y[i]);
    }

    // Remove the first element from both arrays, which represents the count of levels
    x_count--;
    y_count--;

    // Convert the arrays of levels into sets to eliminate duplicates
    int x_set[x_count];
    int y_set[y_count];
    int x_index = 0;
    int y_index = 0;
    for (int i = 0; i < x_count; i++) {
        if (x[i]!= 0) {
            x_set[x_index] = x[i];
            x_index++;
        }
    }
    for (int i = 0; i < y_count; i++) {
        if (y[i]!= 0) {
            y_set[y_index] = y[i];
            y_index++;
        }
    }

    // Create a union of both sets to combine all unique levels completed by both players
    int z_set[x_index + y_index];
    int z_index = 0;
    for (int i = 0; i < x_index; i++) {
        z_set[z_index] = x_set[i];
        z_index++;
    }
    for (int i = 0; i < y_index; i++) {
        z_set[z_index] = y_set[i];
        z_index++;
    }

    // Check if the number of unique levels completed matches the maximum level
    int z_count = z_index;
    if (z_count!= max_level) {
        // If not, print a message indicating that not all levels were completed
        printf("Oh, my keyboard!\n");
    } else {
        // If all levels were completed, print a success message
        printf("I become the guy.\n");
    }

    return 0;
}
