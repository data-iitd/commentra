#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <limits.h>

using namespace std;

// Initialize scanner and read the first line
void init() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
}

// Main function
int main() {
    init();
    // Read the first two integers from the input
    int A, B;
    cin >> A >> B;

    // Check if the sum of A and B is even
    if ((A + B) % 2 == 0) {
        // If it is, print the result (the average)
        cout << (A + B) / 2 << '\n';
        return 0;
    }
    // If the sum is odd, print "IMPOSSIBLE"
    cout << "IMPOSSIBLE" << '\n';
    return 0;
}
