#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main() {
    // Read the number of rows/columns for the square matrix
    int n;
    scanf("%d", &n);
    
    // Initialize an array to store the input strings
    char s[MAX_SIZE][MAX_SIZE];
    
    // Read n strings from input and store them in the array s
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    
    // Initialize arrays to store diagonal elements
    char d1[MAX_SIZE];  // Primary diagonal
    char d2[MAX_SIZE];  // Secondary diagonal
    int d1_count = 0, d2_count = 0;
    
    // Initialize a set to store non-diagonal elements
    char rem[MAX_SIZE * MAX_SIZE];
    int rem_count = 0;

    // Iterate through the matrix to populate the diagonals and non-diagonal elements
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // If it's a primary diagonal element
            if (i == j) {
                d1[d1_count++] = s[i][j];
            }
            // If it's a secondary diagonal element
            if (i == n - j - 1) {
                d2[d2_count++] = s[i][j];
            }
            // If it's a non-diagonal element
            if (i != j && i != n - j - 1) {
                // Check if the element is already in the rem array
                int found = 0;
                for (int k = 0; k < rem_count; k++) {
                    if (rem[k] == s[i][j]) {
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    rem[rem_count++] = s[i][j];
                }
            }
        }
    }

    // Check conditions to determine the output
    // If the number of unique non-diagonal elements is not 1
    if (rem_count != 1) {
        printf("NO\n");
    }
    // If the primary and secondary diagonals are not equal
    else if (memcmp(d1, d2, d1_count) != 0) {
        printf("NO\n");
    }
    // If the primary diagonal does not consist of the same element
    else {
        int unique = 1;
        for (int i = 1; i < d1_count; i++) {
            if (d1[i] != d1[0]) {
                unique = 0;
                break;
            }
        }
        if (!unique) {
            printf("NO\n");
        }
        // If the unique element in the primary diagonal is also in the non-diagonal set
        else if (rem[0] == d1[0]) {
            printf("NO\n");
        }
        // If all conditions are satisfied, print 'YES'
        else {
            printf("YES\n");
        }
    }

    return 0;
}
