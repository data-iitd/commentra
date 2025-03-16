#include <stdio.h>
<<<<<<< HEAD
#include <stdlib.h>
=======
>>>>>>> 98c87cb78a (data updated)

int main() {
    // Read the number of characters
    int n;
    scanf("%d", &n);

    // Read the sequence of characters
<<<<<<< HEAD
    char *s = (char *)malloc(n * sizeof(char));
    scanf("%s", s);

    // Create an array to hold the numeric representation of colors
    int *ns = (int *)malloc(n * sizeof(int));
=======
    char s[n + 1]; // +1 for null terminator
    scanf("%s", s);

    // Create an array to hold the numeric representation of colors
    int ns[n];
>>>>>>> 98c87cb78a (data updated)
    // Convert characters to their respective numeric values
    for (int i = 0; i < n; i++) {
        switch (s[i]) {
            case 'R':
                ns[i] = 0; // 'R' is represented as 0
                break;
            case 'G':
                ns[i] = 1; // 'G' is represented as 1
                break;
            case 'B':
                ns[i] = 2; // 'B' is represented as 2
                break;
        }
    }

    // Create a 2D array to hold cumulative counts of each color up to each index
<<<<<<< HEAD
    int **rgb = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        rgb[i] = (int *)malloc(3 * sizeof(int));
        if (i == 0) {
            rgb[i][0] = rgb[i][1] = rgb[i][2] = 0; // Initialize the first row with zero counts
        } else {
            for (int j = 0; j < 3; j++) {
                rgb[i][j] = rgb[i - 1][j]; // Carry forward the previous counts
            }
            rgb[i][ns[i - 1]]++; // Increment the count for the current color
        }
=======
    int rgb[n + 1][3];
    for (int j = 0; j < 3; j++) {
        rgb[0][j] = 0; // Initialize the first row with zero counts
    }

    // Populate the cumulative counts for each color
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            rgb[i][j] = rgb[i - 1][j]; // Carry forward the previous counts
        }
        rgb[i][ns[i - 1]]++; // Increment the count for the current color
>>>>>>> 98c87cb78a (data updated)
    }

    // Variable to hold the total count of valid triplets
    int sum = 0;

    // Iterate through all pairs of indices to find valid triplets
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            // Check if the colors at indices i and j are different
            if (ns[i] != ns[j]) {
                // Determine the third color that completes the triplet
                int tn = 3 - ns[i] - ns[j];
                // Count how many times the third color appears after index j
                sum += rgb[n][tn] - rgb[j + 1][tn];
                // Check if the third color appears at the position k
                int k = 2 * j - i;
                if (k < n && ns[k] == tn) {
                    sum--; // Adjust the count if the third color is at position k
                }
            }
        }
    }

    // Output the total count of valid triplets
    printf("%d\n", sum);

<<<<<<< HEAD
    // Free allocated memory
    free(s);
    free(ns);
    for (int i = 0; i <= n; i++) {
        free(rgb[i]);
    }
    free(rgb);

=======
>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
