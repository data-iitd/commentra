#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold the dimensions and images
typedef struct {
    int n, m; // n: number of rows in the first image, m: number of rows in the second image
    char **nImg, **mImg; // nImg: first image as a 2D array of characters, mImg: second image as a 2D array of characters
} data;

// Function to read input dimensions and images, returning a data instance
data newData() {
    data d;
    // Read the dimensions of the images from standard input
    scanf("%d %d", &d.n, &d.m);
    // Load the first image and the second image based on the dimensions
    d.nImg = load(d.n);
    d.mImg = load(d.m);

    return d;
}

// Function to load an image of given count from standard input
char **load(int cnt) {
    char **ret = (char **)malloc(cnt * sizeof(char *)); // Create an array to hold the image strings
    for (int i = 0; i < cnt; i++) {
        // Read each line of the image into the array
        ret[i] = (char *)malloc(100 * sizeof(char)); // Allocate memory for each line
        scanf("%s", ret[i]);
    }

    return ret;
}

// Method to check if the second image exists within the first image
int exist(data d) {
    // Iterate over possible starting positions in the first image
    for (int i = 0; i <= d.n - d.m; i++) {
        for (int j = 0; j <= d.n - d.m; j++) {
            // Check if the second image matches the first image at the current position
            if (match(d, i, j)) {
                return 1; // Return 1 if a match is found
            }
        }
    }

    // Return 0 if no match is found after checking all positions
    return 0;
}

// Method to check if the second image matches the first image at a specific position
int match(data d, int x, int y) {
    // Iterate over each cell of the second image
    for (int i = 0; i < d.m; i++) {
        for (int j = 0; j < d.m; j++) {
            // Compare the corresponding cells of the two images
            if (d.nImg[x + i][y + j] != d.mImg[i][j]) {
                return 0; // Return 0 if any cell does not match
            }
        }
    }

    // Return 1 if all cells match
    return 1;
}

int main() {
    // Create a new data instance and check for the existence of a match
    data d = newData();
    if (exist(d)) {
        printf("Yes\n"); // Print "Yes" if a match exists
    } else {
        printf("No\n");  // Print "No" if no match is found
    }

    // Free allocated memory
    for (int i = 0; i < d.n; i++) {
        free(d.nImg[i]);
    }
    free(d.nImg);
    for (int i = 0; i < d.m; i++) {
        free(d.mImg[i]);
    }
    free(d.mImg);

    return 0;
}
