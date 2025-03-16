#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n); // Reading the size of the matrix
    char arr[n][n]; // Initializing the 2D character array
    char str[n][100]; // Initializing the string array to store input strings

    // Reading n strings and storing them in the str array
    for (int i = 0; i < n; i++) {
        scanf("%s", str[i]);
    }

    // Populating the 2D character array from the strings
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = str[i][j];
        }
    }

    // Comparing the first two characters to determine a and b
    char a = arr[0][0];
    char b = arr[0][1];

    // If the characters are the same, print "NO" and exit
    if (a == b) {
        printf("NO\n");
    } else {
        int res = 1; // Initialize result as true

        // Iterating through the matrix to validate the pattern
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || i + j == n - 1) { // Check diagonal elements
                    if (arr[i][j] != a) { // If diagonal element is not a, set res to false
                        res = 0;
                        break;
                    }
                } else { // Check off-diagonal elements
                    if (arr[i][j] != b) { // If off-diagonal element is not b, set res to false
                        res = 0;
                        break;
                    }
                }
            }
        }

        // Printing the result
        if (res) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

