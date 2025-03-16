#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int num, counter = 0, fine = 0;
    scanf("%d", &num); // Read the size of the grid
    char **arr = (char **)malloc(num * sizeof(char *));
    for (int i = 0; i < num; i++) {
        arr[i] = (char *)malloc((num + 1) * sizeof(char));
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
    printf("%d\n", fine);

    // Free allocated memory
    for (int i = 0; i < num; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
