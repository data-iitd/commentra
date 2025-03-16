#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Read the values for R, G, B, and N from standard input
    int R, G, B, N;
    cin >> R >> G >> B >> N;

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

// <END-OF-CODE>
