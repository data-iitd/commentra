#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main() {
    int n;
    char s[MAX_SIZE][MAX_SIZE];
    char d1[MAX_SIZE], d2[MAX_SIZE];
    int rem[256] = {0};
    int i, j;
    int flag = 0;

    // Read the number of rows/columns for the square matrix
    scanf("%d", &n);

    // Read n strings from input and store them in the matrix s
    for (i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }

    // Initialize the diagonals and non-diagonal elements
    for (i = 0; i < n; i++) {
        d1[i] = s[i][i];
        d2[i] = s[i][n - i - 1];
        for (j = 0; j < n; j++) {
            if (i != j && i != n - j - 1) {
                rem[(int)s[i][j]]++;
            }
        }
    }
    d1[n] = '\0';
    d2[n] = '\0';

    // Check conditions to determine the output
    // If the number of unique non-diagonal elements is not 1
    int unique_count = 0;
    for (i = 0; i < 256; i++) {
        if (rem[i] > 0) {
            unique_count++;
        }
    }
    if (unique_count != 1) {
        printf("NO\n");
        return 0;
    }

    // If the primary and secondary diagonals are not equal
    if (strcmp(d1, d2) != 0) {
        printf("NO\n");
        return 0;
    }

    // If the primary diagonal does not consist of the same element
    int same_element = 1;
    for (i = 1; i < n; i++) {
        if (d1[i] != d1[0]) {
            same_element = 0;
            break;
        }
    }
    if (same_element == 0) {
        printf("NO\n");
        return 0;
    }

    // If the unique element in the primary diagonal is also in the non-diagonal set
    for (i = 0; i < n; i++) {
        if (d1[0] != s[i][i] && d1[0] != s[i][n - i - 1]) {
            printf("NO\n");
            return 0;
        }
    }

    // If all conditions are satisfied, print 'YES'
    printf("YES\n");
    return 0;
}
