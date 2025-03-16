#include <iostream>
using namespace std;

int main() {
    // Take three integers as input from the user and store them in variables t, s, and q respectively
    int t, s, q;
    cin >> t >> s >> q;

    // Initialize an answer counter variable ans to 0
    int ans = 0;

    // Loop while the value of s is less than t
    while (s < t) {
        // Multiply the value of s by q and update the value of s
        s *= q;

        // Increment the answer counter variable ans by 1
        ans++;
    }

    // Print the final answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
