
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold the dimensions and images
typedef struct {
    int n, m;
    char **nImg, **mImg;
} data;

int main() {
    // Create a new data instance and check for the existence of a match
    data d = newData();
    if (d.exist) {
        printf("Yes\n"); // Print "Yes" if a match exists
    } else {
        printf("No\n");  // Print "No" if no match is found
    }
}

// Function to read input dimensions and images, returning a data instance
data newData() {
    int n, m;
    // Read the dimensions of the images from standard input
    scanf("%d %d", &n, &m);
    // Load the first image and the second image based on the dimensions
    char **nImg = load(n);
    char **mImg = load(m);

    // Return a data instance containing the dimensions and images
    data d = {n: n, m: m, nImg: nImg, mImg: mImg};
    return d;
}

// Function to load an image of given count from standard input
char **load(int cnt) {
    char **ret = (char **)malloc(cnt * sizeof(char *)); // Create a slice to hold the image strings
    for (int i = 0; i < cnt; i++) {
        ret[i] = (char *)malloc(100 * sizeof(char)); // Allocate memory for each image string
        // Read each line of the image into the slice
        scanf("%s", ret[i]);
    }

    // Return the loaded image
    return ret;
}

// Method to check if the second image exists within the first image
int exist(data d) {
    // Iterate over possible starting positions in the first image
    for (int i = 0; i <= d.n - d.m; i++) {
        for (int j = 0; j <= d.n - d.m; j++) {
            // Check if the second image matches the first image at the current position
            if (match(d, i, j)) {
                return 1; // Return true if a match is found
            }
        }
    }

    // Return false if no match is found after checking all positions
    return 0;
}

// Method to check if the second image matches the first image at a specific position
int match(data d, int x, int y) {
    // Iterate over each cell of the second image
    for (int i = 0; i < d.m; i++) {
        for (int j = 0; j < d.m; j++) {
            // Compare the corresponding cells of the two images
            if (strcmp(d.nImg[x + i], d.mImg[i])!= 0) {
                return 0; // Return false if any cell does not match
            }
        }
    }

    // Return true if all cells match
    return 1;
}

// END-OF-CODE