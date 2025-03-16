#include <bits/stdc++.h>
using namespace std;

int main() {
    // Create a Scanner object to read input from the user
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // Create a list to store the result pairs
    list<string> r;
    // Variable to track the index of the element with the maximum absolute value
    int m = 0;
    // Find the index of the element with the maximum absolute value
    for (int i = 1; i < n; i++) {
        if (abs(a[m]) < abs(a[i])) {
            m = i;
        }
    }
    // Generate pairs of indices based on the sign of the maximum absolute value element
    for (int i = 0; i < n; i++) {
        if (a[m] >= 0 ^ a[i] >= 0) {
            r.push_back(to_string(m + 1) + " " + to_string(i + 1));
        }
    }
    // If the maximum absolute value element is non-negative
    if (a[m] >= 0) {
        // Add pairs of consecutive indices in ascending order
        for (int i = 1; i < n; i++) {
            r.push_back(to_string(i) + " " + to_string(i + 1));
        }
    } else {
        // If the maximum absolute value element is negative, add pairs in descending order
        for (int i = n; i > 1; i--) {
            r.push_back(to_string(i) + " " + to_string(i - 1));
        }
    }
    // Print the size of the result list
    cout << r.size() << endl;
    // Print each pair in the result list
    for (auto it = r.begin(); it!= r.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}

