#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>

using namespace std;

#define MOD 1000000007

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;  // Read the number of elements
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];  // Read the list of elements
    }

    int max_val = 0;  // Initialize the maximum value to 0
    int max_sign = 0;  // Initialize the sign of the maximum value to 0
    int max_index = -1;  // Initialize the index of the maximum value to -1

    // Find the element with the maximum absolute value
    for (int i = 0; i < N; ++i) {
        if (abs(a[i]) > max_val) {
            max_val = abs(a[i]);
            max_sign = (a[i] > 0) - (a[i] < 0);  // Determine the sign
            max_index = i;
        }
    }

    // If the maximum value is zero, print 0
    if (max_sign == 0) {
        cout << 0 << endl;
    }
    // If the maximum value is positive, print the sequence of operations
    else if (max_sign == 1) {
        cout << 2 * N - 1 << endl;
        for (int i = 0; i < N; ++i) {
            cout << max_index + 1 << " " << i + 1 << endl;  // Print the swap operations
        }
        for (int i = 0; i < N - 1; ++i) {
            cout << i + 1 << " " << i + 2 << endl;  // Print the increment operations
        }
    }
    // If the maximum value is negative, print the sequence of operations in reverse
    else {
        cout << 2 * N - 1 << endl;
        for (int i = 0; i < N; ++i) {
            cout << max_index + 1 << " " << i + 1 << endl;  // Print the swap operations
        }
        for (int i = N - 2; i >= 0; --i) {
            cout << i + 2 << " " << i + 1 << endl;  // Print the decrement operations in reverse
        }
    }

    return 0;
}

// <END-OF-CODE>
