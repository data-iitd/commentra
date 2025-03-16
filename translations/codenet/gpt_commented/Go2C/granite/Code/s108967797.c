
#include <stdio.h>
#include <stdlib.h>

// Function to read an integer from input
int ri() {
    int n;
    scanf("%d", &n);
    return n;
}

// Function to calculate the average of a slice of float numbers
float ave(float *s, int n) {
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += s[i];
    }
    return sum / n;
}

// Function to calculate the absolute difference between two float numbers
float diff(float a, float b) {
    if (a > b) {
        return a - b;
    }
    return b - a;
}

int main() {
    int n = ri(); // Read the number of elements
    float *a = (float *)malloc(n * sizeof(float)); // Create a slice to hold the float numbers
    for (int i = 0; i < n; i++) {
        a[i] = ri(); // Read each integer and convert it to float
    }
    // printf("%f\n", ave(a, n)); // Uncomment to print the average of the numbers

    // Calculate the average of the numbers
    float ave = ave(a, n);

    // Initialize variables to track the minimum difference and the corresponding index
    float minDiff = 999999.9;
    int ansIndex = -1;
    for (int i = 0; i < n; i++) { // Iterate over the slice to find the closest value to the average
        float diff = diff(a[i], ave); // Calculate the difference between the current value and the average
        if (diff < minDiff) { // Check if the current difference is less than the minimum difference found so far
            minDiff = diff; // Update the minimum difference
            ansIndex = i; // Update the index of the closest value
        }
    }
    // Print the index of the value closest to the average
    printf("%d\n", ansIndex);

    free(a); // Free the memory allocated for the array of float numbers
    return 0;
}
