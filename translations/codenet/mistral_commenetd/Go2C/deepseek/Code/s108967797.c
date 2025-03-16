#include <stdio.h>
#include <stdlib.h>

// Function to read an integer from standard input
int ri() {
    int n = 0;
    char ch;
    while ((ch = getchar_unlocked()) >= '0' && ch <= '9') {
        n = (n << 3) + (n << 1) + ch - '0';
    }
    return n;
}

// Function to calculate the average of an array of float numbers
float ave(float *s, int size) {
    float sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += s[i];
    }
    return sum / size;
}

// Function to calculate the difference between two float numbers
float diff(float a, float b) {
    return (a > b) ? (a - b) : (b - a);
}

// Main function
int main() {
    // Read the number of elements in the array from standard input
    int n = ri();

    // Allocate memory for an array of float numbers with the given size
    float *a = (float *)malloc(n * sizeof(float));

    // Read each element of the array from standard input and store it in the corresponding index
    for (int i = 0; i < n; i++) {
        a[i] = ri();
    }

    // Calculate the average of the array elements
    float ave_val = ave(a, n);

    // Initialize variables to store the minimum difference and the index of the element with the minimum difference
    float minDiff = 999999.9;
    int ansIndex = -1;

    // Iterate through each element of the array and find the one with the minimum difference from the average
    for (int i = 0; i < n; i++) {
        float diff_val = diff(a[i], ave_val);
        if (diff_val < minDiff) {
            minDiff = diff_val;
            ansIndex = i;
        }
    }

    // Print the index of the element with the minimum difference from the average
    printf("%d\n", ansIndex);

    // Free the allocated memory
    free(a);

    // End of the code
    return 0;
}
