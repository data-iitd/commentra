#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    int max_val = 0;
    int max_sign = 0;
    int max_index = -1;

    // Find the element with the maximum absolute value
    for (int i = 0; i < N; ++i) {
        if (abs(a[i]) > max_val) {
            max_val = abs(a[i]);
            max_sign = a[i] > 0 ? 1 : -1;
            max_index = i;
        }
    }

    // If the maximum value is zero, print 0
    if (max_sign == 0) {
        cout << 0 << '\n';
    }
    // If the maximum value is positive, print the sequence of operations
    else if (max_sign == 1) {
        cout << 2 * N - 1 << '\n';
        for (int i = 0; i < N; ++i) {
            cout << max_index + 1 << ' ' << i + 1 << '\n';  // Print the swap operations
        }
        for (int i = 0; i < N - 1; ++i) {
            cout << i + 1 << ' ' << i + 2 << '\n';  // Print the increment operations
        }
    }
    // If the maximum value is negative, print the sequence of operations in reverse
    else {
        cout << 2 * N - 1 << '\n';
        for (int i = 0; i < N; ++i) {
            cout << max_index + 1 << ' ' << i + 1 << '\n';  // Print the swap operations
        }
        for (int i = N - 1; i > 0; --i) {
            cout << i + 1 << ' ' << i << '\n';  // Print the decrement operations in reverse
        }
    }

    return 0;
}
