#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    // Set the logging flags to display the short file name and line number
    // (Not applicable in C++, but we can use cout for debugging)
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Initialize a new scanner object
    // (Not applicable in C++, we will use cin for input)

    // Read the first two integers from the standard input using cin
    int x, y;
    cin >> x >> y;

    // Initialize two variables xt and yt to store the indices of the arrays a where x and y are present
    int xt = -1, yt = -1;

    // Define a 3x3 2D vector a
    vector<vector<int>> a = {{1, 3, 5, 7, 8, 10, 12}, {4, 6, 9, 11}, {2}};

    // Iterate through each inner loop of the outer loop
    for (int i = 0; i < a.size(); ++i) {
        // Iterate through each element of the current inner loop
        for (int n : a[i]) {
            // Check if the current element is equal to x, if yes, store its index in xt
            if (x == n) {
                xt = i;
            }
            // Check if the current element is equal to y, if yes, store its index in yt
            if (y == n) {
                yt = i;
            }
        }
    }

    // Check if the indices xt and yt are equal, if yes, print "Yes"
    if (xt == yt) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

