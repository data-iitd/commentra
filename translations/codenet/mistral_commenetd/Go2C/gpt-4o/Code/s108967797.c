#include <stdio.h>
#include <stdlib.h>

// Function to read an integer from standard input
int ri() {
    int n;
    scanf("%d", &n); // Read an integer from standard input
    return n; // Return the read integer
}

// Function to calculate the average of an array of float numbers
double ave(double *s, int size) {
    double sum = 0.0; // Initialize a variable to store the sum of numbers in the array
    for (int i = 0; i < size; i++) { // Iterate through each number in the array
        sum += s[i]; // Add the current number to the sum
    }
    return sum / size; // Calculate and return the average
}

// Function to calculate the difference between two float numbers
double diff(double a, double b) {
    return (a > b) ? (a - b) : (b - a); // Return the absolute difference
}

// Main function
int main() {
    // Read the number of elements in the array from standard input
    int n = ri();

    // Allocate memory for an array of double numbers with the given size
    double *a = (double *)malloc(n * sizeof(double));

    // Read each element of the array from standard input and store it in the corresponding index
    for (int i = 0; i < n; i++) {
        a[i] = (double)ri(); // Read an integer from standard input and convert it to a double
    }

    // Calculate the average of the array elements
    double average = ave(a, n);

    // Initialize variables to store the minimum difference and the index of the element with the minimum difference
    double minDiff = 999999.9;
    int ansIndex = -1;

    // Iterate through each element of the array and find the one with the minimum difference from the average
    for (int i = 0; i < n; i++) {
        double currentDiff = diff(a[i], average); // Calculate the difference between the current element and the average
        if (currentDiff < minDiff) { // Check if the difference is smaller than the current minimum difference
            minDiff = currentDiff; // If so, update the minimum difference
            ansIndex = i; // and the index of the answer
        }
    }

    // Print the index of the element with the minimum difference from the average
    printf("%d\n", ansIndex);

    // Free the allocated memory
    free(a);

    return 0; // End of the program
}

// <END-OF-CODE>
