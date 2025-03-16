#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int num;
    scanf("%d", &num);

    // Dynamically allocate memory for the strings
    char **arr = (char **)malloc(num * sizeof(char *));
    for (int i = 0; i < num; i++) {
        arr[i] = (char *)malloc((num + 1) * sizeof(char));
    }

    // Read 'num' strings from input
    for (int i = 0; i < num; i++) {
        scanf("%s", arr[i]);
    }

    int counter = 0;
    int fine = 0;

    // Calculate fines based on occurrences of 'C' in each column
    for (int i = 0; i < num; i++) {
        for (int k = 0; k < num; k++) {
            // Count occurrences of 'C' in the current column
            if (arr[k][i] == 'C') {
                counter++;
            }
        }
        // Update the fine based on the number of 'C's found in this column
        fine += (counter * (counter - 1)) / 2;
        // Reset counter for the next column
        counter = 0;
    }

    // Calculate fines based on occurrences of 'C' in each row
    for (int i = 0; i < num; i++) {
        for (int k = 0; k < num; k++) {
            // Count occurrences of 'C' in the current row
            if (arr[i][k] == 'C') {
                counter++;
            }
        }
        // Update the fine based on the number of 'C's found in this row
        fine += (counter * (counter - 1)) / 2;
        // Reset counter for the next row
        counter = 0;
    }

    // Output the total fine calculated
    printf("%d\n", fine);

    // Free allocated memory
    for (int i = 0; i < num; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
