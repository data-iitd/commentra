#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    // Defining a constant INF for a very large number
    const int INF = 1e9 + 5;

    // Creating a Scanner object to read input
    int n;
    cin >> n;

    // Initializing two vector objects to store the elements
    vector<int> a;
    vector<int> b;

    // Initializing variables to track the minimum and maximum values
    int left = INF, right = 0;

    // Looping through n elements to read and update the vectors and variables
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a.push_back(temp); // Reading element into vector a
        cin >> temp;
        b.push_back(temp); // Reading element into vector b
        left = min(left, a[i]); // Updating left with the minimum value
        right = max(right, b[i]); // Updating right with the maximum value
    }

    // Looping through the vectors to find the target element
    for (int i = 0; i < n; i++) {
        if (left == a[i] && right == b[i]) {
            cout << i + 1 << endl; // Printing the 1-based index of the target element
            return 0; // Returning from the method after finding the target
        }
    }

    // If no such element is found, print -1
    cout << -1 << endl;

