
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    // Read the number of rows/columns for the square matrix
    int n;
    scanf("%d", &n);

    // Initialize an empty list to store the input strings
    char** s = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        s[i] = (char*)malloc(n * sizeof(char));
        scanf("%s", s[i]);
    }

    // Initialize a flag variable (not used in this code)
    int flag = 0;

    // Initialize lists to store diagonal elements
    char* d1 = (char*)malloc(n * sizeof(char));  // Primary diagonal
    char* d2 = (char*)malloc(n * sizeof(char));  // Secondary diagonal

    // Initialize a set to store non-diagonal elements
    char** rem = (char**)malloc(n * sizeof(char*));
    int rem_count = 0;

    // Iterate through the matrix to populate the diagonals and non-diagonal elements
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // If it's a primary diagonal element
            if (i == j) {
                strcpy(d1 + i, s[i]);
            }
            // If it's a secondary diagonal element
            if (i == n - j - 1) {
                strcpy(d2 + i, s[i]);
            }
            // If it's a non-diagonal element
            if (i!= j && i!= n - j - 1) {
                rem[rem_count] = s[i];
                rem_count++;
            }
        }
    }

    // Check conditions to determine the output
    // If the number of unique non-diagonal elements is not 1
    if (rem_count!= 1) {
        printf("NO\n");
    }
    // If the primary and secondary diagonals are not equal
    else if (strcmp(d1, d2)!= 0) {
        printf("NO\n");
    }
    // If the primary diagonal does not consist of the same element
    else if (strlen(set(d1))!= 1) {
        printf("NO\n");
    }
    // If the unique element in the primary diagonal is also in the non-diagonal set
    else if (strstr(rem, d1)!= NULL) {
        printf("NO\n");
    }
    // If all conditions are satisfied, print 'YES'
    else {
        printf("YES\n");
    }

    // Free dynamically allocated memory
    for (int i = 0; i < n; i++) {
        free(s[i]);
    }
    free(s);
    free(d1);
    free(d2);
    for (int i = 0; i < rem_count; i++) {
        free(rem[i]);
    }
    free(rem);

    return 0;
}
