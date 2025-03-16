#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, m, s, f;
    cin >> n >> m >> s >> f;  // Read values of n, m, s, and f

    int d;  // Direction
    char c; // Character for direction
    if (s < f) {
        d = 1;  // Set direction to right (R)
        c = 'R';
    } else {
        d = -1; // Set direction to left (L)
        c = 'L';
    }

    string res = "";  // Initialize an empty string to store the result
    int i = 1;        // Initialize step counter
    int j = s;        // Initialize current position
    int t, l, r;     // Variables for time and range
    cin >> t >> l >> r;  // Read initial values of t, l, and r
    int k = 1;        // Initialize the current time step

    // Loop until the current position reaches the finishing point
    while (j != f) {
        if (i > t && k < m) {  // Check if it's time to update the time step and there are more steps
            cin >> t >> l >> r;  // Read new values for t, l, and r
            k++;  // Increment the time step counter
        }

        if (i == t && (l <= j && j <= r || l <= j + d && j + d <= r)) {  // Check if it's the specified time step and the position is within the allowed range
            res += 'X';  // Append 'X' to the result string
        } else {
            res += c;  // Append the direction character to the result string
            j += d;    // Update the current position
        }
        i++;  // Increment the step counter
    }

    cout << res;  // Print the result string
    return 0;
}

// <END-OF-CODE>
