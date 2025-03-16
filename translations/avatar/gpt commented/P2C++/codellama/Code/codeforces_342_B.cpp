#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Define a lambda function to read multiple integers from input
auto R = []() {
    vector<int> v;
    string s;
    getline(cin, s);
    stringstream ss(s);
    int x;
    while (ss >> x) {
        v.push_back(x);
    }
    return v;
};

int main() {
    // Read the values of n (total positions), m (number of obstacles), s (starting position), and f (finishing position)
    vector<int> v = R();
    int n = v[0], m = v[1], s = v[2], f = v[3];

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
    int i = 1, j = s;

    // Read the first obstacle's position and range
    vector<int> v1 = R();
    int t = v1[0], l = v1[1], r = v1[2];
    int k = 1;  // Counter for the number of obstacles processed

    // Loop until the current position reaches the finishing position
    while (j != f) {
        // Check if we need to read a new obstacle's position and range
        if (i > t && k < m) {
            v1 = R();  // Read the next obstacle's position and range
            t = v1[0], l = v1[1], r = v1[2];
            k += 1;  // Increment the obstacle counter
        }

        // Check if the current position is at an obstacle
        if (i == t && (l <= j <= r || l <= j + d <= r)) {
            res += 'X';  // Mark the position with 'X' if it's blocked by an obstacle
        } else {
            res += c;  // Append the direction character to the result
            j += d;  // Move to the next position in the determined direction
        }

        i += 1;  // Increment the step counter
    }

    // Print the resulting path taken
    cout << res << endl;

    return 0;
}

