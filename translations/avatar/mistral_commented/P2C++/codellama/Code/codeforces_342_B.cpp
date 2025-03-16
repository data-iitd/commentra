#######
# Code
#######

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <queue>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Define a lambda function to read a line of input and convert it to a list of integers
auto R = []() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    vector<int> v;
    int n;
    while (ss >> n) {
        v.push_back(n);
    }
    return v;
};

// Read the input values: n (number of test cases), m (number of tracks), s (starting position), and f (final position)
auto n = R()[0];
auto m = R()[0];
auto s = R()[0];
auto f = R()[0];

// Check if the starting position is less than the final position
if (s < f) {
    // Initialize direction and corresponding character
    auto d = 1;
    auto c = 'R';
} else {
    // Initialize direction with negative sign and corresponding character 'L'
    auto d = -1;
    auto c = 'L';
}

// Initialize an empty string to store the output
string res = "";

// Initialize variables i and j with initial values
auto i = 1;
auto j = s;

// Read the next input: three integers t, l, and r representing the length, left end, and right end of a track
auto t = R()[0];
auto l = R()[0];
auto r = R()[0];

// Initialize a variable k to keep track of the number of tracks
auto k = 1;

// While the current position j is not equal to the final position f
while (j != f) {
    // If we have read all the tracks or the current position i is not in the current track
    if (i > t && k < m) {
        // Read the next input: three integers t, l, and r representing the length, left end, and right end of the next track
        t = R()[0];
        l = R()[0];
        r = R()[0];
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

// End of code
