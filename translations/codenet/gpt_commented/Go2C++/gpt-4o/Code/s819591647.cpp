// problem_b.cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

// Define a constant for modulus operation
const int constMod = 1e9 + 7;

// Function to read a single integer from input
int getInt() {
    int x;
    cin >> x;
    return x;
}

// Function to read n integers from input and return them as a vector
vector<int> getIntSlice(int n) {
    vector<int> ns(n);
    for (int i = 0; i < n; i++) {
        ns[i] = getInt();
    }
    return ns;
}

// Function to compute the greatest common divisor of a and b
int numGcd(int a, int b) {
    return b == 0 ? a : numGcd(b, a % b);
}

// Function to solve the problem
void solve() {
    // Read n and m from input
    int n = getInt();
    int m = getInt();
    // Read n integers into vector a
    vector<int> a = getIntSlice(n);

    // Calculate the sum of all elements in a
    int sum = accumulate(a.begin(), a.end(), 0);

    // Count how many elements in a meet the required rate
    int count = 0;
    double rate = static_cast<double>(sum) / (4 * m);
    for (int v : a) {
        if (static_cast<double>(v) >= rate) {
            count++;
        }
    }

    // Output "Yes" if count is greater than or equal to m, otherwise "No"
    if (count >= m) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

// Main function initializes the program and calls solve
int main() {
    // Call the solve function to execute the main logic
    solve();
    return 0;
}

// <END-OF-CODE>
