#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int mod = 1e9 + 7; // Define constant for modulo operation.
const int DX[] = { -1, 0, 1, 0 }, DY[] = { 0, -1, 0, 1 }; // Define directions for movement.

int n; // Declare variable for the size of the array.
long long k; // Declare variable for the target value.
vector<long long> a; // Declare vector to store the values.

bool check(long long x) {
    long long tot = 0; // Initialize the total count.

    for (int i = 0; i < n; i++) {
        long long now = a[i]; // Get the current element.
        int l = 0, r = n; // Initialize the boundaries for binary search.

        if (now >= 0) { // If the current element is non-negative.
            while (l < r) { // Perform binary search.
                int c = (l + r) / 2;
                if (now * a[c] < x) {
                    l = c + 1; // Adjust the left boundary.
                } else {
                    r = c; // Adjust the right boundary.
                }
            }
            tot += l; // Add the result to the total.
        } else { // If the current element is negative.
            while (l < r) { // Perform binary search.
                int c = (l + r) / 2;
                if (now * a[c] >= x) {
                    l = c + 1; // Adjust the left boundary.
                } else {
                    r = c; // Adjust the right boundary.
                }
            }
            tot += (n - l); // Add the result to the total.
        }

        if (now * now < x) {
            tot--; // Adjust the total if necessary.
        }
    }

    return tot / 2 < k; // Return true if the count is less than k.
}

int main() {
    cin >> n; // Read the size of the array.
    cin >> k; // Read the target value.
    a.resize(n); // Initialize the vector.

    for (int i = 0; i < n; ++i) {
        cin >> a[i]; // Read the elements of the array.
    }

    sort(a.begin(), a.end()); // Sort the array.

    long long INF = 1e18 + 1; // Define a large number as infinity.
    long long l = -INF; // Initialize the left boundary of the search.
    long long r = INF; // Initialize the right boundary of the search.

    while (l + 1 < r) { // Perform binary search.
        long long c = (l + r) / 2; // Calculate the middle point.
        if (check(c)) {
            l = c; // Adjust the left boundary.
        } else {
            r = c; // Adjust the right boundary.
        }
    }

    cout << l << endl; // Print the result.
    return 0;
}

// <END-OF-CODE>
