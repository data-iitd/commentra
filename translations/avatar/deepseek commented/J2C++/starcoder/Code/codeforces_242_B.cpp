#include <bits/stdc++.h>
using namespace std;

// Defining a constant INF for a very large number
#define INF (int) 1e9 + 5

int main() {
    // Creating a Scanner object to read input
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n; // Declaring variable n to store the number of elements
    cin >> n; // Reading the integer value of n

    // Initializing two vectors to store the elements
    vector<int> a, b;

    // Initializing variables to track the minimum and maximum values
    int left = INF, right = 0;

    // Looping through n elements to read and update the lists and variables
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x; // Reading element into vector a
        a.push_back(x); // Pushing element into vector a
        cin >> x; // Reading element into vector b
        b.push_back(x); // Pushing element into vector b
        left = min(left, a[i]); // Updating left with the minimum value
        right = max(right, b[i]); // Updating right with the maximum value
    }

    // Looping through the vectors to find the target element
    for (int i = 0; i < n; i++) {
        if (left == a[i] && right == b[i]) {
            cout << i + 1; // Printing the 1-based index of the target element
            return 0; // Returning from the method after finding the target
        }
    }

    // If no such element is found, print -1
    cout << -1;
    return 0;
}

