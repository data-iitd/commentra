#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Defining a constant INF for a very large number
const int INF = 1e9 + 5;

int main() {
    // Creating a Scanner object to read input
    int n; // Declaring variable n to store the number of elements
    cin >> n; // Reading the integer value of n

    // Initializing two vector objects to store the elements
    vector<int> a;
    vector<int> b;

    // Initializing variables to track the minimum and maximum values
    int left = INF, right = 0;

    // Looping through n elements to read and update the lists and variables
    for (int i = 0; i < n; i++) {
        int x, y; // Declaring variables to store the elements
        cin >> x >> y; // Reading the elements into x and y
        a.push_back(x); // Pushing x into list a
        b.push_back(y); // Pushing y into list b
        left = min(left, x); // Updating left with the minimum value
        right = max(right, y); // Updating right with the maximum value
    }

    // Looping through the lists to find the target element
    for (int i = 0; i < n; i++) {
        if (left == a[i] && right == b[i]) {
            cout << i + 1 << endl; // Printing the 1-based index of the target element
            return 0; // Returning from the method after finding the target
        }
    }

    // If no such element is found, print -1
    cout << -1 << endl;
    return 0;
}

