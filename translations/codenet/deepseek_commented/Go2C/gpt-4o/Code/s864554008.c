#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold the data for the images
typedef struct {
    int n, m;          // Dimensions of the images and their slices
    char **nImg, **mImg; // Arrays to hold the image data
} Data;

// Function to create a new data instance by reading image dimensions and data from standard input
Data newData() {
    Data d;
    scanf("%d %d", &d.n, &d.m); // Read the dimensions of the images

    // Allocate memory for the images
    d.nImg = (char **)malloc(d.n * sizeof(char *));
    d.mImg = (char **)malloc(d.m * sizeof(char *));
    for (int i = 0; i < d.n; i++) {
<<<<<<< HEAD
        d.nImg[i] = (char *)malloc(100 * sizeof(char)); // Assuming max length of each image row is 100
        scanf("%s", d.nImg[i]); // Read each string from standard input
    }
    for (int i = 0; i < d.m; i++) {
        d.mImg[i] = (char *)malloc(100 * sizeof(char)); // Assuming max length of each image row is 100
=======
        d.nImg[i] = (char *)malloc((d.m + 1) * sizeof(char)); // +1 for null terminator
        scanf("%s", d.nImg[i]); // Read each string from standard input
    }
    for (int i = 0; i < d.m; i++) {
        d.mImg[i] = (char *)malloc((d.m + 1) * sizeof(char)); // +1 for null terminator
>>>>>>> 98c87cb78a (data updated)
        scanf("%s", d.mImg[i]); // Read each string from standard input
    }

    return d;
}

// Function to check if the smaller image exists within the larger image
int exist(Data d) {
    // Iterate over all possible positions where the smaller image could fit within the larger image
    for (int i = 0; i <= d.n - d.m; i++) {
        for (int j = 0; j <= d.n - d.m; j++) {
            if (match(d, i, j)) { // Check if the smaller image matches the corresponding part of the larger image at the current position
                return 1; // Return true
            }
        }
    }
    return 0; // Return false
}

// Function to check if the smaller image matches the corresponding part of the larger image at a given position
int match(Data d, int x, int y) {
    // Iterate over each pixel in the smaller image and compare it with the corresponding pixel in the larger image
    for (int i = 0; i < d.m; i++) {
        for (int j = 0; j < d.m; j++) {
            if (d.nImg[x + i][y + j] != d.mImg[i][j]) { // If any pixel does not match, return false
                return 0; // Return false
            }
        }
    }
    return 1; // If all pixels match, return true
}

<<<<<<< HEAD
// Main function
=======
// Function to free allocated memory
void freeData(Data d) {
    for (int i = 0; i < d.n; i++) {
        free(d.nImg[i]);
    }
    free(d.nImg);
    for (int i = 0; i < d.m; i++) {
        free(d.mImg[i]);
    }
    free(d.mImg);
}

>>>>>>> 98c87cb78a (data updated)
int main() {
    // Create a new data instance
    Data d = newData();
    
    // Check if the smaller image exists within the larger image and print the result
    if (exist(d)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    // Free allocated memory
<<<<<<< HEAD
    for (int i = 0; i < d.n; i++) {
        free(d.nImg[i]);
    }
    free(d.nImg);
    for (int i = 0; i < d.m; i++) {
        free(d.mImg[i]);
    }
    free(d.mImg);

=======
    freeData(d);
    
>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
