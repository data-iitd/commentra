#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

// Function to read an integer from standard input
int ri() {
    int n;
    cin >> n; // Read an integer from input
    return n; // Return the read integer
}

// Function to calculate the average of a vector of double numbers
double ave(const vector<double>& s) {
    double sum = 0.0; // Initialize a variable to store the sum of numbers in the vector
    for (double v : s) { // Iterate through each number in the vector
        sum += v; // Add the current number to the sum
    }
    return sum / s.size(); // Calculate and return the average
}

// Function to calculate the difference between two double numbers
double diff(double a, double b) {
    return fabs(a - b); // Return the absolute difference
}

// Main function
int main() {
    // Read the number of elements in the array from standard input
    int n = ri();

    // Allocate memory for a vector of double numbers with the given size
    vector<double> a(n);

    // Read each element of the array from standard input and store it in the corresponding index
    for (int i = 0; i < n; i++) {
        a[i] = static_cast<double>(ri()); // Read an integer from standard input and convert it to a double
    }

    // Calculate the average of the array elements
    double average = ave(a);

    // Initialize variables to store the minimum difference and the index of the element with the minimum difference
    double minDiff = numeric_limits<double>::max();
    int ansIndex = -1;

    // Iterate through each element of the array and find the one with the minimum difference from the average
    for (int i = 0; i < n; i++) {
        double d = diff(a[i], average); // Calculate the difference between the current element and the average
        if (d < minDiff) { // Check if the difference is smaller than the current minimum difference
            minDiff = d; // If so, update the minimum difference
            ansIndex = i; // and the index of the answer
        }
    }

    // Print the index of the element with the minimum difference from the average
    cout << ansIndex << endl;

    return 0; // End of the program
}

// <END-OF-CODE>
