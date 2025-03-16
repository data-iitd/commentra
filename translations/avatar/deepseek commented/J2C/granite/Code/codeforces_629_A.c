

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int num;
    scanf("%d", &num); // Read the size of the grid
    int counter = 0; // Counter for the number of 'C's
    int fine = 0; // Fine amount to be calculated
    char **arr = (char **)malloc(num * sizeof(char *)); // Dynamically allocate memory for the grid rows

    // Read num strings representing the grid rows
    for (int i = 0; i < num; i++) {
        arr[i] = (char *)malloc(num * sizeof(char));
        scanf("%s", arr[i]);
    }

    // Calculate the fine for each column
    for (int i = 0; i < num; i++) {
        for (int k = 0; k < num; k++) {
            if (arr[k][i] == 'C') {
                counter++;
            }
        }
        fine += (counter * (counter - 1)) / 2; // Calculate the fine for the column
        counter = 0; // Reset the counter for the next column
    }

    // Calculate the fine for each row
    for (int i = 0; i < num; i++) {
        for (int k = 0; k < num; k++) {
            if (arr[i][k] == 'C') {
                counter++;
            }
        }
        fine += (counter * (counter - 1)) / 2; // Calculate the fine for the row
        counter = 0; // Reset the counter for the next row
    }

    // Print the total fine
    printf("%d", fine);

    // Free the dynamically allocated memory
    for (int i = 0; i < num; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
