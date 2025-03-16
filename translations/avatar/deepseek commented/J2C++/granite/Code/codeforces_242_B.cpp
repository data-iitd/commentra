
#include <iostream> // Includingiostream for input/output
#include <vector> // Including vector for dynamic arrays
#include <algorithm> // Including algorithm for min and max functions

using namespace std;

int main() {
    // Creating a vector object to store the elements
    vector<int> a, b;
    int n; // Declaring variable n to store the number of elements
    cin >> n; // Reading the integer value of n

    // Initializing variables to track the minimum and maximum values
    int left = INT_MAX, right = INT_MIN;

    // Looping through n elements to read and update the vectors and variables
    for (int i = 0; i < n; i++) {
        int x, y; // Declaring variables x and y to store the elements
        cin >> x >> y; // Reading elements into variables x and y
        a.push_back(x); // Adding element x to vector a
        b.push_back(y); // Adding element y to vector b
        left = min(left, x); // Updating left with the minimum value
        right = max(right, y); // Updating right with the maximum value
    }

    // Looping through the vectors to find the target element
    for (int i = 0; i < n; i++) {
        if (left == a[i] && right == b[i]) {
            cout << i + 1 << endl; // Printing the 1-based index of the target element
            return 0; // Returning from the function after finding the target
        }
    }

    // If no such element is found, print -1
    cout << -1 << endl;

    return 0; // Returning from the main function
}
