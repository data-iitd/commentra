#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to read an integer from input
<<<<<<< HEAD
int ri() {
=======
int read_integer() {
>>>>>>> 98c87cb78a (data updated)
    int n;
    scanf("%d", &n); // Read an integer from standard input
    return n; // Return the read integer
}

// Function to calculate the average of an array of float numbers
<<<<<<< HEAD
double ave(double *s, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) { // Iterate over each value in the array
        sum += s[i]; // Accumulate the sum of the values
=======
double average(double *arr, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) { // Iterate over each value in the array
        sum += arr[i]; // Accumulate the sum of the values
>>>>>>> 98c87cb78a (data updated)
    }
    return sum / size; // Return the average
}

// Function to calculate the absolute difference between two double numbers
<<<<<<< HEAD
double diff(double a, double b) {
=======
double difference(double a, double b) {
>>>>>>> 98c87cb78a (data updated)
    return fabs(a - b); // Return the absolute difference
}

int main() {
<<<<<<< HEAD
    int n = ri(); // Read the number of elements
    double *a = (double *)malloc(n * sizeof(double)); // Allocate memory for the array of double numbers
    for (int i = 0; i < n; i++) {
        a[i] = (double)ri(); // Read each integer and convert it to double
    }

    // Calculate the average of the numbers
    double average = ave(a, n);
=======
    int n = read_integer(); // Read the number of elements
    double *a = (double *)malloc(n * sizeof(double)); // Allocate memory for the array of float numbers
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp); // Read each integer
        a[i] = (double)temp; // Convert it to double and store it in the array
    }

    // Calculate the average of the numbers
    double avg = average(a, n);
>>>>>>> 98c87cb78a (data updated)

    // Initialize variables to track the minimum difference and the corresponding index
    double minDiff = 999999.9;
    int ansIndex = -1;
    for (int i = 0; i < n; i++) { // Iterate over the array to find the closest value to the average
<<<<<<< HEAD
        double currentDiff = diff(a[i], average); // Calculate the difference between the current value and the average
        if (currentDiff < minDiff) { // Check if the current difference is less than the minimum difference found so far
            minDiff = currentDiff; // Update the minimum difference
=======
        double diff = difference(a[i], avg); // Calculate the difference between the current value and the average
        if (diff < minDiff) { // Check if the current difference is less than the minimum difference found so far
            minDiff = diff; // Update the minimum difference
>>>>>>> 98c87cb78a (data updated)
            ansIndex = i; // Update the index of the closest value
        }
    }
    // Print the index of the value closest to the average
    printf("%d\n", ansIndex);

    free(a); // Free the allocated memory
    return 0; // Return success
}

// <END-OF-CODE>
