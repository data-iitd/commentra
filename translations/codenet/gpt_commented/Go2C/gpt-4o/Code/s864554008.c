#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold the dimensions and images
typedef struct {
    int n, m;          // n: number of rows in the first image, m: number of rows in the second image
    char **nImg, **mImg; // nImg: first image as a pointer to an array of strings, mImg: second image
} Data;

// Function to create a new Data instance and check for the existence of a match
Data newData() {
    Data d;
    scanf("%d %d", &d.n, &d.m); // Read the dimensions of the images from standard input

    // Allocate memory for the images
    d.nImg = (char **)malloc(d.n * sizeof(char *));
    d.mImg = (char **)malloc(d.m * sizeof(char *));
    for (int i = 0; i < d.n; i++) {
        d.nImg[i] = (char *)malloc(100 * sizeof(char)); // Assuming max length of each string is 100
    }
    for (int i = 0; i < d.m; i++) {
        d.mImg[i] = (char *)malloc(100 * sizeof(char)); // Assuming max length of each string is 100
    }

    // Load the first image and the second image based on the dimensions
    for (int i = 0; i < d.n; i++) {
        scanf("%s", d.nImg[i]);
    }
    for (int i = 0; i < d.m; i++) {
        scanf("%s", d.mImg[i]);
    }

    return d; // Return the data instance containing the dimensions and images
}

// Function to check if the second image exists within the first image
int exist(Data d) {
    // Iterate over possible starting positions in the first image
    for (int i = 0; i <= d.n - d.m; i++) {
        for (int j = 0; j <= d.n - d.m; j++) {
            // Check if the second image matches the first image at the current position
            if (match(d, i, j)) {
                return 1; // Return true if a match is found
            }
        }
    }
    return 0; // Return false if no match is found after checking all positions
}

// Function to check if the second image matches the first image at a specific position
int match(Data d, int x, int y) {
    // Iterate over each cell of the second image
    for (int i = 0; i < d.m; i++) {
        for (int j = 0; j < d.m; j++) {
            // Compare the corresponding cells of the two images
            if (d.nImg[x + i][y + j] != d.mImg[i][j]) {
                return 0; // Return false if any cell does not match
            }
        }
    }
    return 1; // Return true if all cells match
}

// Main function
int main() {
    Data d = newData(); // Create a new data instance
    if (exist(d)) {
        printf("Yes\n"); // Print "Yes" if a match exists
    } else {
        printf("No\n");  // Print "No" if no match is found
    }

    // Free allocated memory
    for (int i = 0; i < d.n; i++) {
        free(d.nImg[i]);
    }
    for (int i = 0; i < d.m; i++) {
        free(d.mImg[i]);
    }
    free(d.nImg);
    free(d.mImg);

    return 0;
}

// <END-OF-CODE>
