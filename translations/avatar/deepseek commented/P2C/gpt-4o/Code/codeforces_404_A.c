#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);  // Take the size of the square matrix as input
    char s[n][n + 1];  // Initialize a 2D array to store the matrix elements

    // Take n inputs, each representing a row of the matrix, and store these in the array s
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }

    int flag = 0;  // Initialize flag to 0
    char d1[n];    // Array to store the diagonal elements from top-left to bottom-right
    char d2[n];    // Array to store the diagonal elements from top-right to bottom-left
    int rem[256] = {0};  // Array to count occurrences of non-diagonal elements (ASCII size)

    int rem_count = 0;  // Count of unique non-diagonal elements

    // Iterate through the matrix to populate d1, d2, and rem with the appropriate elements
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {  // Check if the element is on the diagonal from top-left to bottom-right
                d1[i] = s[i][j];
            }
            if (i == n - j - 1) {  // Check if the element is on the diagonal from top-right to bottom-left
                d2[i] = s[i][j];
            }
            if (i != j && i != n - j - 1) {  // Check if the element is not on the diagonals
                if (rem[s[i][j]] == 0) {
                    rem_count++;  // New unique element found
                }
                rem[s[i][j]]++;  // Count the occurrence of the non-diagonal element
            }
        }
    }

    // Check the conditions and print 'NO' or 'YES' based on the conditions
    if (rem_count != 1) {
        printf("NO\n");  // Print 'NO' if the count of unique non-diagonal elements is not 1
    } else if (memcmp(d1, d2, n) != 0) {
        printf("NO\n");  // Print 'NO' if the two diagonals are not equal
    } else {
        int all_same = 1;  // Flag to check if all diagonal elements are the same
        for (int i = 1; i < n; i++) {
            if (d1[i] != d1[0]) {
                all_same = 0;  // Found a different element in the diagonal
                break;
            }
        }
        if (!all_same) {
            printf("NO\n");  // Print 'NO' if the diagonal elements do not all have the same value
        } else if (rem[d1[0]] == rem_count) {
            printf("NO\n");  // Print 'NO' if the set of diagonal elements is equal to the set of non-diagonal elements
        } else {
            printf("YES\n");  // Print 'YES' if all conditions are met
        }
    }

    return 0;
}
