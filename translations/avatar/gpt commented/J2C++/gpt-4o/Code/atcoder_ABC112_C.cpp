#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Define a constant for the maximum coordinate value
const int MAX = 100;

int check(int n, const vector<int>& x, const vector<int>& y, const vector<int>& h, int cx, int cy) {
    int ch = -1;

    // Calculate the initial height based on the first point with a positive height
    for (int i = 0; i < n; i++) {
        if (h[i] > 0) {
            ch = abs(x[i] - cx) + abs(y[i] - cy) + h[i];
            break;
        }
    }

    // Validate the height against all points
    for (int i = 0; i < n; i++) {
        // If the calculated height does not match the expected height, return -1
        if (h[i] != max(ch - abs(x[i] - cx) - abs(y[i] - cy), 0)) {
            return -1;
        }
    }

    // Return the calculated height if all checks pass
    return ch;
}

int main() {
    // Create a vector to read input from the user
    int n;
    cin >> n;

    // Initialize vectors to store x, y coordinates and heights
    vector<int> x(n), y(n), h(n);

    // Read the x, y coordinates and heights for each point
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> h[i];
    }

    // Iterate through all possible coordinates (i, j) within the defined range
    for (int i = 0; i <= MAX; i++) {
        for (int j = 0; j <= MAX; j++) {
            // Check the height at the current coordinate (i, j)
            int ch = check(n, x, y, h, i, j);
            // If the height is valid (greater than 0), print the coordinates and height
            if (ch > 0) {
                cout << i << " " << j << " " << ch << endl;
            }
        }
    }

    return 0;
}

// <END-OF-CODE>
