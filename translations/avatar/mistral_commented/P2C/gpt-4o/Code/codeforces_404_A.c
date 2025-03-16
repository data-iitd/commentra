#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main() {
    // Take the number of rows as input
    int n;
    scanf("%d", &n);

    // Initialize a 2D array to store the rows
    char s[MAX_SIZE][MAX_SIZE][MAX_SIZE]; // Assuming max length of each element is MAX_SIZE
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%s", s[i][j]);
        }
    }

    // Initialize flags and empty arrays for diagonals
    char d1[MAX_SIZE][MAX_SIZE];
    char d2[MAX_SIZE][MAX_SIZE];
    int rem[MAX_SIZE * MAX_SIZE] = {0}; // To store unique elements
    int rem_count = 0;

    // Iterate through each element in the array 's'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // If the current indices are the same, append the element to 'd1'
            if (i == j) {
                strcpy(d1[i], s[i][j]);
            }
            // If the current indices are reverse of each other, append the element to 'd2'
            if (i == n - j - 1) {
                strcpy(d2[i], s[i][j]);
            }
            // If the current indices are not same and not reverse, add the element to 'rem'
            if (i != j && i != n - j - 1) {
                int found = 0;
                for (int k = 0; k < rem_count; k++) {
                    if (strcmp(rem[k], s[i][j]) == 0) {
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    strcpy(rem[rem_count++], s[i][j]);
                }
            }
        }
    }

    // Check if the size of 'rem' is not equal to 1
    if (rem_count != 1) {
        printf("NO\n");
        return 0;
    }

    // Check if 'd1' and 'd2' arrays are equal
    for (int i = 0; i < n; i++) {
        if (strcmp(d1[i], d2[i]) != 0) {
            printf("NO\n");
            return 0;
        }
    }

    // Check if all elements in 'd1' are the same
    for (int i = 1; i < n; i++) {
        if (strcmp(d1[0], d1[i]) != 0) {
            printf("NO\n");
            return 0;
        }
    }

    // Check if all elements in 'd1' are present in 'rem'
    if (strcmp(d1[0], rem[0]) != 0) {
        printf("NO\n");
        return 0;
    }

    // If all the above conditions are false, print 'YES'
    printf("YES\n");
    return 0;
}

// <END-OF-CODE>
