#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Read the number of elements (n) and the initial value (x) from input
    int n, x;
    cin >> n >> x;

    // Read the list of integers
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Sort the list of integers
    sort(a.begin(), a.end());

    // Initialize the answer counter
    int ans = 0;

    // Check if the smallest element in the sorted list is greater than x
    if (a[0] > x) {
        // If true, print 0 and exit since no elements can be subtracted from x
        cout << 0 << endl;
        return 0;
    }

    // Iterate through the sorted list of integers
    for (int i = 0; i < n; ++i) {
        // If the current element is greater than x, set x to 0 and break the loop
        if (a[i] > x) {
            x = 0;
            break;
        }
        // Subtract the current element from x
        x -= a[i];
        // Increment the answer counter
        ans++;
    }

    // If there is any remaining value in x, decrement the answer counter
    if (x != 0) {
        ans--;
    }

    // Print the final answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
