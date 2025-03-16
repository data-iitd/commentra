#include <iostream>  // Including the iostream library for input and output
#include <vector>    // Including the vector library for dynamic arrays
#include <cmath>     // Including cmath for mathematical functions
#include <algorithm> // Including algorithm for std::max

using namespace std;

const int MAX = 100;  // Defining a constant MAX with value 100

int check(int n, vector<int>& x, vector<int>& y, vector<int>& h, int cx, int cy) {  // Function to check the height of water at position (cx, cy)
    int ch = -1;  // Initializing the height to -1

    for (int i = 0; i < n; i++) {  // Loop to iterate through all elements in the vectors x, y, and h
        if (h[i] > 0) {  // If the height of the current element is greater than 0
            ch = abs(x[i] - cx) + abs(y[i] - cy) + h[i];  // Calculate the distance and height of the current element and update the height if it's closer
            break;  // Exit the loop once the closest element is found
        }
    }

    for (int i = 0; i < n; i++) {  // Loop to check if all elements have the same height as the closest one
        if (h[i] != max(ch - abs(x[i] - cx) - abs(y[i] - cy), 0)) {  // If the height is different, return -1 to indicate an error
            return -1;
        }
    }

    return ch;  // Return the height of the water at position (cx, cy)
}

int main() {  // Main function to start the program
    int n;
    cin >> n;  // Reading the number of elements n from the standard input
    vector<int> x(n), y(n), h(n);  // Creating vectors x, y, and h of size n

    for (int i = 0; i < n; i++) {  // Loop to read and initialize the vectors
        cin >> x[i] >> y[i] >> h[i];  // Reading values into x, y, and h
    }

    for (int i = 0; i <= MAX; i++) {  // Outer loop to iterate through all possible positions (i, j)
        for (int j = 0; j <= MAX; j++) {  // Inner loop to check all possible positions (i, j)
            int ch = check(n, x, y, h, i, j);  // Calling the check function to calculate the height of the water at position (i, j)
            if (ch > 0) {  // If the height is greater than 0, print the position and height
                cout << i << " " << j << " " << ch << endl;
            }
        }
    }

    return 0;  // Return 0 to indicate successful completion
}

// <END-OF-CODE>
