#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

// ri() reads an integer from standard input.
int ri() {
    int n = 0;
    string s;
    getline(cin, s);
    for (char c : s) {
        n = n * 10 + (c - '0');
    }
    return n;
}

// ave(s []float64) calculates the average of a slice of float64 values.
double ave(const vector<double>& s) {
    double sum = 0.0;
    for (double v : s) {
        sum += v;
    }
    return sum / s.size();
}

// diff(a, b float64) calculates the absolute difference between two float64 values.
double diff(double a, double b) {
    return abs(a - b);
}

// main function is the entry point of the program.
int main() {
    int n = ri(); // Reads the number of elements.
    vector<double> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = ri(); // Reads n integers into a float64 slice.
    }
    // Uncommenting the following line will print the slice for debugging purposes.
    // for (double v : a) cout << v << " ";

    double aveVal = ave(a); // Calculates the average of the slice.

    double minDiff = 999999.9;
    int ansIndex = -1;
    for (int i = 0; i < n; i++) {
        double diffVal = diff(a[i], aveVal); // Calculates the absolute difference between each element and the average.
        if (diffVal < minDiff) {
            minDiff = diffVal;
            ansIndex = i;
        }
    }
    cout << ansIndex << endl; // Outputs the index with the smallest difference.

    return 0;
}
