#include <iostream>  // Including necessary libraries
#include <vector>
#include <algorithm> // For std::min and std::max

using namespace std;

const int INF = (int)1e9 + 5;  // Initializing a large constant value

int main() {
    int n;

    // Reading the number of elements in the arrays
    cin >> n;

    vector<int> a;  // Creating a vector to store the first array elements
    vector<int> b;  // Creating a vector to store the second array elements

    int left = INF, right = 0;  // Initializing left and right variables to store the minimum and maximum elements respectively

    // Reading the elements of the arrays and updating the minimum and maximum elements
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;  // Reading an element from the first and second array
        a.push_back(x);  // Adding it to the first vector
        b.push_back(y);  // Adding it to the second vector
        left = min(left, a[i]);  // Finding the minimum element in the first array
        right = max(right, b[i]);  // Finding the maximum element in the second array
    }

    // Checking if there is an element that has the same minimum and maximum value in both arrays
    for (int i = 0; i < n; i++) {
        if (left == a[i] && right == b[i]) {  // Checking if the current element in both arrays has the same minimum and maximum value
            cout << (i + 1) << endl;  // If true, printing the index of the element (1-based index)
            return 0;  // Exiting the program after finding the element
        }
    }

    // If no such element is found, printing -1
    cout << -1 << endl;

    return 0;
}

// <END-OF-CODE>
