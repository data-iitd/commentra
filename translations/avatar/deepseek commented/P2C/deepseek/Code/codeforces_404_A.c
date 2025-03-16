#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);  // Take the size of the square matrix as input
    char **s = (char **)malloc(n * sizeof(char *));  // Initialize a pointer to store the matrix elements
    for (int i = 0; i < n; i++) {
        s[i] = (char *)malloc(n * sizeof(char));  // Allocate memory for each row
    }

    // Take n inputs, each representing a row of the matrix, and store these in the matrix
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }

    int flag = 0;  // Initialize flag to 0
    char *d1 = (char *)malloc(n * sizeof(char));  // Initialize an array to store the diagonal elements from top-left to bottom-right
    char *d2 = (char *)malloc(n * sizeof(char));  // Initialize an array to store the diagonal elements from top-right to bottom-left
    char rem[256] = {0};  // Initialize an array to store the non-diagonal elements

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
                rem[(int)s[i][j]]++;
            }
        }
    }

    // Check the conditions and print 'NO' or 'YES' based on the conditions
    int rem_count = 0;
    char rem_char = 0;
    for (int i = 0; i < 256; i++) {
        if (rem[i] > 0) {
            rem_count++;
            rem_char = (char)i;
        }
    }

    if (rem_count != 1) {
        printf("NO\n");  // Print 'NO' if the set of non-diagonal elements does not have a single unique element
    } else if (strcmp(d1, d2) != 0) {
        printf("NO\n");  // Print 'NO' if the two diagonals are not equal
    } else if (rem_count_unique(d1) != 1) {
        printf("NO\n");  // Print 'NO' if the diagonal elements do not all have the same value
    } else if (rem_char == d1[0]) {
        printf("NO\n");  // Print 'NO' if the set of diagonal elements is equal to the set of non-diagonal elements
    } else {
        printf("YES\n");  // Print 'YES' if all conditions are met
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(s[i]);
    }
    free(s);
    free(d1);
    free(d2);

    return 0;
}
