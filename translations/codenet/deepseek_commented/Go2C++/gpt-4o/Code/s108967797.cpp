#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

// Function to read an integer from standard input.
int ri() {
    int n;
    cin >> n;
    return n;
}

// Function to calculate the average of a vector of doubles.
double ave(const vector<double>& s) {
    double sum = 0.0;
    for (double v : s) {
        sum += v;
    }
    return sum / s.size();
}

// Function to calculate the absolute difference between two doubles.
double diff(double a, double b) {
    return fabs(a - b);
}

// Main function is the entry point of the program.
int main() {
    int n = ri(); // Reads the number of elements.
    vector<double> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = static_cast<double>(ri()); // Reads n integers into a double vector.
    }

    double average = ave(a); // Calculates the average of the vector.

    double minDiff = numeric_limits<double>::max();
    int ansIndex = -1;
    for (int i = 0; i < n; i++) {
        double d = diff(a[i], average); // Calculates the absolute difference between each element and the average.
        if (d < minDiff) {
            minDiff = d;
            ansIndex = i;
        }
    }
    cout << ansIndex << endl; // Outputs the index with the smallest difference.
}

// <END-OF-CODE>
