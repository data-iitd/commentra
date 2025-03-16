
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a new scanner to read input from standard input (stdin)
    FILE *fp = stdin;
    char word[10];
    int c[3][3], a[3], b[3];

    // Read 3x3 integers from input and populate the array 'c'
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            fscanf(fp, "%s", word);
            c[i][j] = atoi(word);
        }
    }

    // Calculate the first differences based on the first row of 'c'
    b[0] = c[0][0];
    b[1] = c[0][1];
    b[2] = c[0][2];

    // Calculate the differences for the second and third rows based on the first row
    a[1] = c[1][0] - c[0][0];
    a[2] = c[2][0] - c[0][0];

    // Check if the calculated differences are consistent across the matrix
    if (a[1] == c[1][1] - c[0][1] && a[1] == c[1][2] - c[0][2] &&
        a[2] == c[2][1] - c[0][1] && a[2] == c[2][2] - c[0][2]) {
        // If the conditions are met, print "Yes"
        printf("Yes\n");
    } else {
        // If the conditions are not met, print "No"
        printf("No\n");
    }

    return 0;
}
