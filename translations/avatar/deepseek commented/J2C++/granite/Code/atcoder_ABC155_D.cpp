
#include <iostream> // Include necessary libraries for input and output.
#include <vector> // Include necessary library for vector.
#include <algorithm> // Include necessary library for sorting.

using namespace std;

typedef long long ll; // Define a 64-bit integer type.

const ll MOD = 1e9 + 7; // Define constant for modulo operation.
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 }; // Define directions for movement.

int n; // Declare variable for the size of the array.
ll k; // Declare variable for the target value.
vector<ll> a; // Declare vector to store the values.

bool check(ll x) {
    ll tot = 0; // Initialize the total count.

    for (int i = 0; i < n; i++) {
        ll now = a[i]; // Get the current element.
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

        if ((ll) a[i] * a[i] < x) {
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
    cin >> n >> k; // Read the size of the array and the target value.
    a.resize(n); // Initialize the vector.

    for (int i = 0; i < n; i++) {
        cin >> a[i]; // Read the elements of the array.
    }

    sort(a.begin(), a.end()); // Sort the array.

    ll l = -1e18, r = 1e18; // Initialize the left and right boundaries of the search.

    while (l + 1 < r) { // Perform binary search.
        ll c = (l + r) / 2; // Calculate the middle point.
        if (check(c)) {
            l = c; // Adjust the left boundary.
        } else {
            r = c; // Adjust the right boundary.
        }
    }

    cout << l << endl; // Print the result.

    return 0; // End of the program.
}

