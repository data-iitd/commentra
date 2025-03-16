#######
# Code
#######

#include <iostream>
#include <string>

using namespace std;

int main() {
    // Read the input values: n (number of test cases), m (number of tracks), s (starting position), and f (final position)
    int n, m, s, f;
    cin >> n >> m >> s >> f;

    // Check if the starting position is less than the final position
    if (s < f) {
        // Initialize direction and corresponding character
        int d = 1;
        char c = 'R';
    } else {
        // Initialize direction with negative sign and corresponding character 'L'
        int d = -1;
        char c = 'L';
    }

    // Initialize an empty string to store the output
    string res = "";

    // Initialize variables i and j with initial values
    int i = 1;
    int j = s;

    // Read the next input: three integers t, l, and r representing the length, left end, and right end of a track
    int t, l, r;
    cin >> t >> l >> r;

    // Initialize a variable k to keep track of the number of tracks
    int k = 1;

    // While the current position j is not equal to the final position f
    while (j!= f) {
        // If we have read all the tracks or the current position i is not in the current track
        if (i > t && k < m) {
            // Read the next input: three integers t, l, and r representing the length, left end, and right end of the next track
            cin >> t >> l >> r;
            // Increment the number of tracks
            k += 1;
        }

        // If the current position i is in the current track (either it is the same track or it overlaps with the current track)
        if (i == t && (l <= j <= r || l <= j + d <= r)) {
            // Append 'X' to the output string
            res += 'X';
        } else {
            // Append the corresponding direction character 'R' or 'L' to the output string
            res += c;
            // Update the current position j based on the direction
            j += d;
        }
        // Increment the current position i
        i += 1;
    }

    // Print the output string
    cout << res << endl;

    return 0;
}

