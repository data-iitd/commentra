
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold the data for the images
typedef struct {
    int n, m;       // Dimensions of the images and their slices
    char **nImg, **mImg; // Slices to hold the image data
} data;

int main() {
    // Create a new data instance
    data d = newData();
    
    // Check if the smaller image exists within the larger image and print the result
    if (d.exist) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}

// Function to initialize a new data instance by reading image dimensions and data from standard input
data newData() {
    int n, m;
    scanf("%d %d", &n, &m); // Read the dimensions of the images
    
    // Load the images from standard input
    char **nImg = load(n);
    char **mImg = load(m);
    
    // Return a new data instance with the loaded images and dimensions
    data d = {n: n, m: m, nImg: nImg, mImg: mImg};
    return d;
}

// Function to read a specified number of strings from standard input and return them as a slice of strings
char **load(int cnt) {
    char **ret = (char **)malloc(cnt * sizeof(char *));
    for (int i = 0; i < cnt; i++) {
        ret[i] = (char *)malloc(100 * sizeof(char)); // Assuming each string is at most 100 characters long
        scanf("%s", ret[i]); // Read each string from standard input
    }
    return ret;
}

// Method to check if the smaller image exists within the larger image
int exist(data d) {
    // Iterate over all possible positions where the smaller image could fit within the larger image
    for (int i = 0; i <= d.n - d.m; i++) {
        for (int j = 0; j <= d.n - d.m; j++) {
            if (match(d, i, j)) { // Check if the smaller image matches the corresponding part of the larger image at the current position
                return 1;
            }
        }
    }
    return 0;
}

// Method to check if the smaller image matches the corresponding part of the larger image at a given position
int match(data d, int x, int y) {
    // Iterate over each pixel in the smaller image and compare it with the corresponding pixel in the larger image
    for (int i = 0; i < d.m; i++) {
        for (int j = 0; j < d.m; j++) {
            if (strcmp(d.nImg[x + i], d.mImg[i][j])!= 0) { // If any pixel does not match, return false
                return 0;
            }
        }
    }
    return 1; // If all pixels match, return true
}

// END-OF-CODE