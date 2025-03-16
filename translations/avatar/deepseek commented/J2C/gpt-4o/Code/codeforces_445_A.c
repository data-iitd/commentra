#include <stdio.h> // Including standard input/output library
#include <stdlib.h> // Including standard library for memory allocation and conversion

int main() {
    int n, m; // Variables to store the dimensions
    scanf("%d %d", &n, &m); // Reading the dimensions n and m

    char ans[n][m + 1]; // Array to store the resulting strings, +1 for null terminator

    for (int i = 0; i < n; i++) { // Looping through each row
        char str[m + 1]; // Array to store the current row string, +1 for null terminator
        scanf("%s", str); // Reading the current row as a string

        for (int j = 0; j < m; j++) { // Looping through each character in the row
            if (str[j] == '-') { // Checking if the character is a '-'
                ans[i][j] = '-'; // Assigning '-' to the result
            } else {
                if ((i + j) % 2 == 1) { // Checking if the sum of indices is odd
                    ans[i][j] = 'W'; // Assigning 'W' if the sum is odd
                } else {
                    ans[i][j] = 'B'; // Assigning 'B' if the sum is even
                }
            }
        }
        ans[i][m] = '\0'; // Null-terminating the string for the current row
    }

    for (int i = 0; i < n; i++) { // Looping through each row again to print the results
        printf("%s\n", ans[i]); // Printing the resulting string for the current row
    }

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
