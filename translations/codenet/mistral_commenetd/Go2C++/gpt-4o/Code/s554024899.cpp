#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Initialize two variables to store the input integers
    int x, y;
    
    // Read the first two integers from the standard input
    cin >> x >> y;

    // Initialize two variables xt and yt to store the indices of the arrays a where x and y are present
    int xt = -1, yt = -1;

    // Define a 3x3 2D vector a
    vector<vector<int>> a = {
        {1, 3, 5, 7, 8, 10, 12},
        {4, 6, 9, 11},
        {2}
    };

    // Iterate through each inner vector of the outer vector
    for (int i = 0; i < a.size(); i++) {
        // Iterate through each element of the current inner vector
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

// <END-OF-CODE>
