
#include <iostream>
#include <string>

using namespace std;

int main() {
    auto R = []() {  // Define a lambda function to read integers from input
        int n, m, s, f;
        cin >> n >> m >> s >> f;
        return make_tuple(n, m, s, f);
    };

    auto [n, m, s, f] = R();  // Read values of n, m, s, and f

    // Determine the direction and character based on the starting and finishing points
    int d;
    char c;
    if (s < f) {
        d = 1;  // Set direction to right (R)
        c = 'R';
    } else {
        d = -1;  // Set direction to left (L)
        c = 'L';
    }

    string res;  // Initialize an empty string to store the result
    int i = 1;  // Initialize step counter
    int j = s;  // Initialize current position
    int t, l, r;
    int k = 1;  // Initialize the current time step

    // Loop until the current position reaches the finishing point
    while (j != f) {
        if (i > t && k < m) {  // Check if it's time to update the time step and there are more steps
            cin >> t >> l >> r;  // Read new values for t, l, and r
            k += 1;  // Increment the time step counter
        }

        if (i == t && (l <= j <= r || l <= j + d <= r)) {  // Check if it's the specified time step and the position is within the allowed range
            res += 'X';  // Append 'X' to the result string
        } else {
            res += c;  // Append the direction character to the result string
            j += d;  // Update the current position
        }
        i += 1;  // Increment the step counter
    }

    cout << res << endl;  // Print the result string

    return 0;
}

