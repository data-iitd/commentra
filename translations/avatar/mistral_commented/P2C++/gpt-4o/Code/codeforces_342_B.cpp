#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Define a lambda function to read a line of input and convert it to a vector of integers
    auto R = []() {
        vector<int> result;
        int x;
        while (cin >> x) {
            result.push_back(x);
            if (cin.peek() == '\n') break; // Stop reading on newline
        }
        return result;
    };

    // Read the input values: n (number of test cases), m (number of tracks), s (starting position), and f (final position)
    vector<int> input = R();
    int n = input[0], m = input[1], s = input[2], f = input[3];

    // Check if the starting position is less than the final position
    int d;
    char c;
    if (s < f) {
        d = 1;
        c = 'R';
    } else {
        d = -1;
        c = 'L';
    }

    // Initialize an empty string to store the output
    string res = "";

    // Initialize variables i and j with initial values
    int i = 1;
    int j = s;

    // Read the next input: three integers t, l, and r representing the length, left end, and right end of a track
    input = R();
    int t = input[0], l = input[1], r = input[2];

    // Initialize a variable k to keep track of the number of tracks
    int k = 1;

    // While the current position j is not equal to the final position f
    while (j != f) {
        // If we have read all the tracks or the current position i is not in the current track
        if (i > t && k < m) {
            // Read the next input: three integers t, l, and r representing the length, left end, and right end of the next track
            input = R();
            t = input[0], l = input[1], r = input[2];
            // Increment the number of tracks
            k++;
        }

        // If the current position i is in the current track (either it is the same track or it overlaps with the current track)
        if (i == t && (l <= j && j <= r || l <= j + d && j + d <= r)) {
            // Append 'X' to the output string
            res += 'X';
        } else {
            // Append the corresponding direction character 'R' or 'L' to the output string
            res += c;
            // Update the current position j based on the direction
            j += d;
        }
        // Increment the current position i
        i++;
    }

    // Print the output string
    cout << res << endl;

    return 0;
}

// <END-OF-CODE>
