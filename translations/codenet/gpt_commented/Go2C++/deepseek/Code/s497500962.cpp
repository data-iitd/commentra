#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

// Function to read the next integer from input
int nextInt() {
    int i;
    cin >> i;
    return i;
}

// Function to read the next float from input
double nextFloat() {
    double f;
    cin >> f;
    return f;
}

// Function to read the next string from input
string nextString() {
    string s;
    cin >> s;
    return s;
}

// Main function
int main() {
    // Read the values for R, G, B, and N from standard input
    int R = nextInt(); // Number of red items
    int G = nextInt(); // Number of green items
    int B = nextInt(); // Number of blue items
    int N = nextInt(); // Total number of items to choose

    int ans = 0; // Variable to store the count of valid combinations

    // Iterate over possible counts of red items (x)
    for (int x = 0; x <= N; x++) {
        // Iterate over possible counts of green items (y)
        for (int y = 0; y <= N; y++) {
            // Calculate the remaining items after choosing x red and y green
            int tmp = N - R * x - G * y;
            // Check if the remaining items can be fully represented by blue items
            if (tmp >= 0 && tmp % B == 0) {
                ans++; // Increment the count of valid combinations
            }
        }
    }

    // Output the total count of valid combinations
    cout << ans << endl;

    return 0;
}

