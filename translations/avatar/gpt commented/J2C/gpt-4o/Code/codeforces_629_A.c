#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the number of strings to be processed
    int num;
    scanf("%d", &num);
    
    // Initialize counters for occurrences of 'C' and the total fine
    int counter = 0;
    int fine = 0;
    
    // Create a 2D array to store the input strings
    char **arr = (char **)malloc(num * sizeof(char *));
    for (int i = 0; i < num; i++) {
        arr[i] = (char *)malloc((num + 1) * sizeof(char)); // +1 for null terminator
        scanf("%s", arr[i]);
    }
    
    // Calculate fines based on occurrences of 'C' in each column
    for (int i = 0; i < num; i++) {
        counter = 0; // Reset counter for each column
        for (int k = 0; k < num; k++) {
            // Count occurrences of 'C' in the current column
            if (arr[k][i] == 'C') {
                counter++;
            }
        }
        // Update the fine based on the number of 'C's found in this column
        fine += (counter * (counter - 1)) / 2;
    }
    
    // Calculate fines based on occurrences of 'C' in each row
    for (int i = 0; i < num; i++) {
        counter = 0; // Reset counter for each row
        for (int k = 0; k < num; k++) {
            // Count occurrences of 'C' in the current row
            if (arr[i][k] == 'C') {
                counter++;
            }
        }
        // Update the fine based on the number of 'C's found in this row
        fine += (counter * (counter - 1)) / 2;
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

// <END-OF-CODE>
