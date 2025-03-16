#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>
#include <algorithm>

using namespace std;

// Define the modulus value
const int mod = 1e9 + 7;

// Function to return an integer input
int I() {
    int x;
    cin >> x;
    return x;
}

// Function to return a list of integers as input
vector<int> III(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    return arr;
}

// Function to determine the sign of a number
int my_sign(int x) {
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}

int main() {
    // Initialize variables
    int N = I();
    vector<int> a = III(N);
    int max_val = 0;
    int max_sign = 0;
    int max_index = -1;

    // Iterate through the list 'a' to find the maximum absolute value and its sign
    for (int i = 0; i < N; ++i) {
        int a0 = a[i];
        // Update the maximum value and its sign if the current value is greater
        if (abs(a0) > max_val) {
            max_val = abs(a0);
            max_sign = my_sign(a0);
            max_index = i;
        }
    }

    // Determine the output based on the sign of the maximum value
    if (max_sign == 0) {
        // If the maximum value is zero, print zero
        cout << 0 << endl;
    } else {
        // If the maximum value is non-zero, print the required output
        cout << 2 * N - 1 << endl;
        // Print the indices of the maximum value and the first element
        cout << max_index + 1 << " " << 1 << endl;
        // Print the indices of the other elements in pairs
        if (max_sign == 1) {
            for (int i = 1; i < N; ++i) {
                cout << i + 1 << " " << i + 2 << endl;
            }
        } else {
            for (int i = N - 1; i > 0; --i) {
                cout << i + 1 << " " << i << endl;
            }
        }
    }

    return 0;
}

// <END-OF-CODE>
