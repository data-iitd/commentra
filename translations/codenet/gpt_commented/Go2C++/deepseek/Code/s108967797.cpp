#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

// Function to read an integer from input
int readInt() {
    int n = 0;
    string line;
    getline(cin, line);
    for (char c : line) {
        n = n * 10 + (c - '0');
    }
    return n;
}

// Function to calculate the average of a vector of double numbers
double average(const vector<double>& v) {
    double sum = 0;
    for (double num : v) {
        sum += num;
    }
    return sum / v.size();
}

// Function to calculate the absolute difference between two double numbers
double absDiff(double a, double b) {
    return fabs(a - b);
}

int main() {
    vector<double> a;
    int n = readInt();
    for (int i = 0; i < n; ++i) {
        a.push_back(readInt());
    }

    // Calculate the average of the numbers
    double ave = average(a);

    // Initialize variables to track the minimum difference and the corresponding index
    double minDiff = 999999.9;
    int ansIndex = -1;
    for (int i = 0; i < n; ++i) {
        double diff = absDiff(a[i], ave);
        if (diff < minDiff) {
            minDiff = diff;
            ansIndex = i;
        }
    }

    // Print the index of the value closest to the average
    cout << ansIndex << endl;

    return 0;
}
