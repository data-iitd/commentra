#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b; // Read first integer input
    int count = 0; // Initialize count to keep track of loop iterations

    // Loop continues until the condition is met to break
    while (true) {
        if (a > 0 && b > 0) { // Check if both a and b are positive
            count++; // Increment count
            a--; // Decrement a
            b--; // Decrement b
        } else break; // Break the loop if a or b is not positive
    }

    int ans = a / 2 + b / 2; // Calculate the value of ans
    cout << count << " " << ans << endl; // Print the results

    return 0;
}

