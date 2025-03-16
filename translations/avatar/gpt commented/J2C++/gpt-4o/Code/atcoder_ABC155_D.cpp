#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a large prime number for modulo operations
const int mod = 1e9 + 7;

// Variables to store the number of elements, a threshold value, and the array of long integers
int n;
long long k;
vector<long long> a;

bool check(long long x) {
    long long tot = 0; // Total count of valid pairs

    // Iterate through each element in the array
    for (int i = 0; i < n; i++) {
        long long now = a[i]; // Current element
        int l = 0, r = n; // Initialize binary search bounds

        // If the current element is non-negative
        if (now >= 0) {
            // Perform binary search to count valid pairs
            while (l < r) {
                int c = (l + r) / 2;
                if (now * a[c] < x)
                    l = c + 1; // Move right if the product is less than x
                else
                    r = c; // Move left otherwise
            }
            tot += l; // Add the count of valid pairs
        } else {
            // If the current element is negative
            while (l < r) {
                int c = (l + r) / 2;
                if (now * a[c] >= x)
                    l = c + 1; // Move right if the product is greater than or equal to x
                else
                    r = c; // Move left otherwise
            }
            tot += (n - l); // Count valid pairs with negative current element
        }

        // Adjust total count if the product of the element with itself is less than x
        if (now * now < x)
            tot--;
    }

    // Return true if the total count of pairs is less than k
    return tot / 2 < k;
}

int main() {
    // Initialize input
    cin >> n >> k;

    // Initialize the array to hold the long integers
    a.resize(n);

    // Read the elements into the array
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Sort the array to facilitate binary search
    sort(a.begin(), a.end());

    // Define a large value for infinity
    long long INF = 1e18 + 1;

    // Set the initial bounds for binary search
    long long l = -INF;
    long long r = INF;

    // Perform binary search to find the maximum value satisfying the condition
    while (l + 1 < r) {
        long long c = (l + r) / 2;
        if (check(c))
            l = c; // If check returns true, move the lower bound up
        else
            r = c; // Otherwise, move the upper bound down
    }

    // Output the result
    cout << l << endl;

    return 0;
}

// <END-OF-CODE>
