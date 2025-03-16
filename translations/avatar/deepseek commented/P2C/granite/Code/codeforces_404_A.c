

#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);  // Take the size of the square matrix as input
    char s[n][n];  // Declare a 2D array to store the matrix elements

    // Take n inputs, each representing a row of the matrix, and store these in the array s
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }

    int flag = 0;  // Initialize flag to 0
    char d1[n];  // Declare an array to store the diagonal elements from top-left to bottom-right
    char d2[n];  // Declare an array to store the diagonal elements from top-right to bottom-left
    char rem[n * n];  // Declare an array to store the non-diagonal elements
    int k = 0;  // Initialize k to 0

    // Iterate through the matrix to populate d1, d2, and rem with the appropriate elements
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {  // Check if the element is on the diagonal from top-left to bottom-right
                d1[i] = s[i][j];
            }
            if (i == n - j - 1) {  // Check if the element is on the diagonal from top-right to bottom-left
                d2[i] = s[i][j];
            }
            if (i!= j && i!= n - j - 1) {  // Check if the element is not on the diagonals
                rem[k++] = s[i][j];
            }
        }
    }

    // Check the conditions and print 'NO' or 'YES' based on the conditions
    if (k!= n * n - n) {
        printf("NO\n");  // Print 'NO' if the set of non-diagonal elements does not have a single unique element
    } else if (strcmp(d1, d2)!= 0) {
        printf("NO\n");  // Print 'NO' if the two diagonals are not equal
    } else if (k!= n) {
        printf("NO\n");  // Print 'NO' if the diagonal elements do not all have the same value
    } else if (strcmp(d1, rem) == 0) {
        printf("NO\n");  // Print 'NO' if the set of diagonal elements is equal to the set of non-diagonal elements
    } else {
        printf("YES\n");  // Print 'YES' if all conditions are met
    }

    return 0;
}
