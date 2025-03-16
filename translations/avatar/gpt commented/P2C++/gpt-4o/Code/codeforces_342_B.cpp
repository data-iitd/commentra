#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Read the values of n (total positions), m (number of obstacles), s (starting position), and f (finishing position)
    int n, m, s, f;
    cin >> n >> m >> s >> f;

    // Determine the direction of movement based on the starting and finishing positions
    int d;
    char c;
    if (s < f) {
        d = 1;  // Move right
        c = 'R';  // Character representing right movement
    } else {
        d = -1;  // Move left
        c = 'L';  // Character representing left movement
    }

    // Initialize the result string to store the path taken
    string res = "";

    // Initialize the step counter and current position
    int i = 1;
    int j = s;

    // Read the first obstacle's position and range
    int t, l, r;
    cin >> t >> l >> r;
    int k = 1;  // Counter for the number of obstacles processed

    // Loop until the current position reaches the finishing position
    while (j != f) {
        // Check if we need to read a new obstacle's position and range
        if (i > t && k < m) {
            cin >> t >> l >> r;  // Read the next obstacle's position and range
            k++;  // Increment the obstacle counter
        }

        // Check if the current position is at an obstacle
        if (i == t && (l <= j && j <= r || l <= j + d && j + d <= r)) {
            res += 'X';  // Mark the position with 'X' if it's blocked by an obstacle
        } else {
            res += c;  // Append the direction character to the result
            j += d;  // Move to the next position in the determined direction
        }

        i++;  // Increment the step counter
    }

    // Print the resulting path taken
    cout << res << endl;

    return 0;
}

// <END-OF-CODE>
