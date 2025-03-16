#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom data structure
typedef struct {
    int n, m; // dimensions of the images
    char **nImg, **mImg; // image data as strings
} Data;

// Function to initialize a new data object
Data newData() {
    Data d;
    // Read dimensions from user input
    scanf("%d %d", &d.n, &d.m);
    
    // Allocate memory for image data
    d.nImg = (char **)malloc(d.n * sizeof(char *));
    d.mImg = (char **)malloc(d.m * sizeof(char *));
    
    for (int i = 0; i < d.n; i++) {
        d.nImg[i] = (char *)malloc(100 * sizeof(char)); // Assuming max length of each image string is 100
        scanf("%s", d.nImg[i]);
    }
    
    for (int i = 0; i < d.m; i++) {
        d.mImg[i] = (char *)malloc(100 * sizeof(char)); // Assuming max length of each image string is 100
        scanf("%s", d.mImg[i]);
    }

    return d;
}

// Function to check if data already exists in the larger image
int exist(Data d) {
    // Iterate through all possible positions in larger image
    for (int i = 0; i <= d.n - d.m; i++) {
        for (int j = 0; j <= d.n - d.m; j++) {
            // Check if current position matches the smaller image
            if (match(d, i, j)) {
                // If match is found, return true
                return 1; // true
            }
        }
    }
    // If no match is found, return false
    return 0; // false
}

// Function to check if smaller image matches at current position in larger image
int match(Data d, int x, int y) {
    // Iterate through each pixel in smaller image
    for (int i = 0; i < d.m; i++) {
        for (int j = 0; j < d.m; j++) {
            // Check if corresponding pixel in larger image matches
            if (d.nImg[x + i][y + j] != d.mImg[i][j]) {
                // If mismatch is found, return false
                return 0; // false
            }
        }
    }
    // If all pixels match, return true
    return 1; // true
}

// Main function
int main() {
    // Initialize a new data object
    Data d = newData();
    // Check if data already exists
    if (exist(d)) {
        printf("Yes\n");
    } else {
        printf("No\n");
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

// <END-OF-CODE>
