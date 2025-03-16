
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Main function
    int maxBufSize = 1e8; // Set the maximum buffer size to 100,000,000
    cin.rdbuf()->pubsetbuf(1000000007); // Set the buffer size for cin
    cin.tie(0); // Set the standard input to be synchronized with the standard output
    ios_base::sync_with_stdio(false); // Set the standard input to be synchronized with the standard output

    int n; // Initialize variable n
    cin >> n; // Read the number of elements in the array

    int as[n]; // Initialize an array as of size n
    for (int i = 0; i < n; i++) {
        cin >> as[i]; // Read the array elements
    }

    int xs[n]; // Initialize an array xs of size n
    for (int i = 0; i < n; i++) {
        xs[i] = as[i] - i + 1; // Assign the value xs[i] = a - i + 1
    }

    sort(xs, xs + n); // Sort the array xs in ascending order

    int b = xs[n / 2]; // Assign the middle element of the sorted array xs to variable b
    int ans = 0; // Initialize variable ans with 0
    for (int i = 0; i < n; i++) {
        ans += abs(xs[i] - b); // Calculate the absolute difference and add it to ans
    }

    cout << ans << endl; // Print the answer

    return 0;
}

int abs(int n) {
    // Function to calculate the absolute difference of a number
    if (n < 0) {
        // If the number is negative, return the negative number with the minus sign removed
        return -n;
    }
    // If the number is non-negative, return the number itself
    return n;
}

