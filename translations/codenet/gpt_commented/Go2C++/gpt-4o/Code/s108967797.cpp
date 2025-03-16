#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

// Function to read an integer from input
int ri() {
    int n;
    cin >> n; // Read the next integer from input
    return n; // Return the integer
}

// Function to calculate the average of a vector of double numbers
double ave(const vector<double>& s) {
    double sum = 0.0;
    for (double v : s) { // Iterate over each value in the vector
        sum += v; // Accumulate the sum of the values
    }
    return sum / s.size(); // Return the average
}

// Function to calculate the absolute difference between two double numbers
double diff(double a, double b) {
    return fabs(a - b); // Return the absolute difference
}

int main() {
    int n = ri(); // Read the number of elements
    vector<double> a(n); // Create a vector to hold the double numbers
    for (int i = 0; i < n; i++) {
        a[i] = static_cast<double>(ri()); // Read each integer and convert it to double
    }

    // Calculate the average of the numbers
    double average = ave(a);

    // Initialize variables to track the minimum difference and the corresponding index
    double minDiff = numeric_limits<double>::max();
    int ansIndex = -1;
    for (int i = 0; i < n; i++) { // Iterate over the vector to find the closest value to the average
        double currentDiff = diff(a[i], average); // Calculate the difference between the current value and the average
        if (currentDiff < minDiff) { // Check if the current difference is less than the minimum difference found so far
            minDiff = currentDiff; // Update the minimum difference
            ansIndex = i; // Update the index of the closest value
        }
    }
    // Print the index of the value closest to the average
    cout << ansIndex << endl;

    return 0;
}

// <END-OF-CODE>
