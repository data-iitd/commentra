#include <bits/stdc++.h> // Import necessary libraries for input and mathematical operations.
#include <math.h> // Import for BigInteger class if needed.

using namespace std; // Use the standard namespace.

const int mod = (int) 1e9 + 7; // Define constant for modulo operation.
const int DX[] = { -1, 0, 1, 0 }, DY[] = { 0, -1, 0, 1 }; // Define directions for movement.

int n; // Declare variable for the size of the array.
long k; // Declare variable for the target value.
long a[100000]; // Declare array to store the values.

bool check(long x) {
    long tot = 0; // Initialize the total count.
    
    for (int i = 0; i < n; i++) {
        long now = a[i]; // Get the current element.
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
        
        if ((long) a[i] * a[i] < x) {
            tot--; // Adjust the total if necessary.
        }
    }
    
    if (tot / 2 < k) {
        return true; // Return true if the count is less than k.
    } else {
        return false; // Return false otherwise.
    }
}

int main() {
    ios_base::sync_with_stdio(false); // Disable synchronization between C and C++ standard streams.
    cin.tie(NULL); // Disable flush on new line in C++ standard streams.
    
    cin >> n >> k; // Read the size of the array and the target value.
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; // Read the elements of the array.
    }
    
    sort(a, a + n); // Sort the array.
    
    long INF = (long) (1e18) + 1; // Define a large number as infinity.
    long l = -INF; // Initialize the left boundary of the search.
    long r = INF; // Initialize the right boundary of the search.
    
    while (l + 1 < r) { // Perform binary search.
        long c = (l + r) / 2; // Calculate the middle point.
        if (check(c)) {
            l = c; // Adjust the left boundary.
        } else {
            r = c; // Adjust the right boundary.
        }
    }
    
    cout << l << endl; // Print the result.
    
    return 0;
}

