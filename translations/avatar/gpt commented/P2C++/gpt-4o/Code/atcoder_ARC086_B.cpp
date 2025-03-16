#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

// Define a modulo constant for later use
const int mod = 1e9 + 7;

// Function to read an integer from input
int I() {
    int x;
    cin >> x;
    return x;
}

// Function to read a list of integers from input
vector<int> III(int N) {
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    return a;
}

// Function to determine the sign of a number
int my_sign(int x) {
    return (x > 0) - (x < 0);
}

int main() {
    // Read the number of elements
    int N = I();

    // Read the list of integers
    vector<int> a = III(N);

    // Initialize variables to track the maximum absolute value, its sign, and index
    int max_val = 0;
    int max_sign = 0;
    int max_index = -1;

    // Loop through the list to find the maximum absolute value and its properties
    for (int i = 0; i < N; ++i) {
        int a0 = a[i];
        if (abs(a0) > max_val) {
            max_val = abs(a0);
            max_sign = my_sign(a0);
            max_index = i;
        }
    }

    // Check the sign of the maximum value and print results accordingly
    if (max_sign == 0) {
        // If the maximum sign is zero, print 0
        cout << 0 << endl;
    } else {
        // Print the number of operations
        cout << 2 * N - 1 << endl;
        for (int i = 0; i < N; ++i) {
            cout << max_index + 1 << " " << i + 1 << endl;
        }
        if (max_sign == 1) {
            for (int i = 0; i < N - 1; ++i) {
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
