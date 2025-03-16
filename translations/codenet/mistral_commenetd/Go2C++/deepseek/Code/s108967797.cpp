#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

// Function to read an integer from standard input
int ri() {
    string line;
    getline(cin, line);
    int n = 0;
    for (char c : line) {
        n = n * 10 + (c - '0');
    }
    return n;
}

// Function to calculate the average of a vector of float numbers
float ave(const vector<float>& s) {
    float sum = 0;
    for (float v : s) {
        sum += v;
    }
    return sum / s.size();
}

// Function to calculate the difference between two float numbers
float diff(float a, float b) {
    return abs(a - b);
}

// Main function
int main() {
    // Read the number of elements in the array from standard input
    int n = ri();

    // Allocate memory for a vector of float64 numbers with the given size
    vector<float> a(n);

    // Read each element of the array from standard input and store it in the corresponding index
    for (int i = 0; i < n; i++) {
        a[i] = ri();
    }

    // Calculate the average of the array elements
    float ave = ave(a);

    // Initialize variables to store the minimum difference and the index of the element with the minimum difference
    float minDiff = numeric_limits<float>::max();
    int ansIndex = -1;

    // Iterate through each element of the array and find the one with the minimum difference from the average
    for (int i = 0; i < n; i++) {
        float diff = diff(a[i], ave);
        if (diff < minDiff) {
            minDiff = diff;
            ansIndex = i;
        }
    }

    // Print the index of the element with the minimum difference from the average
    cout << ansIndex << endl;

    // End of the code
    return 0;
}

