
#####
# Code
#####

# Include the necessary header file
#include <iostream>
#include <vector>
#include <string>

// Define a lambda function to read a line of input and convert it to a vector of integers
auto R = [](){
    std::vector<int> res;
    int x;
    while (std::cin >> x) {
        res.push_back(x);
    }
    return res;
}();

// Read the input values: n (number of test cases), m (number of tracks), s (starting position), and f (final position)
int n, m, s, f;
std::cin >> n >> m >> s >> f;

// Check if the starting position is less than the final position
char d = s < f? 'R' : 'L';

// Initialize an empty string to store the output
std::string res;

// Initialize variables i and j with initial values
int i = 1, j = s;

// Read the next input: three integers t, l, and r representing the length, left end, and right end of a track
int t, l, r;
std::cin >> t >> l >> r;

// Initialize a variable k to keep track of the number of tracks
int k = 1;

// While the current position j is not equal to the final position f
while (j!= f) {
    // If we have read all the tracks or the current position i is not in the current track
    if (i > t && k < m) {
        // Read the next input: three integers t, l, and r representing the length, left end, and right end of the next track
        std::cin >> t >> l >> r;
        // Increment the number of tracks
        k += 1;
    }

    // If the current position i is in the current track (either it is the same track or it overlaps with the current track)
    if (i == t && (l <= j <= r || l <= j + (d == 'R'? 1 : -1) <= r)) {
        // Append 'X' to the output string
        res += 'X';
    } else {
        // Append the corresponding direction character 'R' or 'L' to the output string
        res += d;
        // Update the current position j based on the direction
        j += d == 'R'? 1 : -1;
    }
    // Increment the current position i
    i += 1;
}

// Print the output string
std::cout << res << std::endl;

