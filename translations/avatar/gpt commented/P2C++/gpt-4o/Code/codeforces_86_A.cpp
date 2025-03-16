#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Read the input values for l and r, which define the range
    int l, r;
    cin >> l >> r;

    // Initialize the current value to r and a counter for the number of digits
    int curr = r;
    int s = 0;

    // Count the number of digits in the current value (r)
    while (curr) {
        s++;
        curr /= 10;
    }

    // Calculate the first power of ten greater than r
    int first = 1;
    for (int i = 0; i < s; i++) {
        first *= 10;
    }

    // Calculate the second value as half of the first power of ten
    int second = first / 2;

    // Initialize the answer variable to store the maximum product found
    long long ans = -1;

    // Iterate through the possible candidates: l, r, first, and second
    for (int i : {l, r, first, second}) {
        // Check if the candidate is within the range [l, r]
        if (i >= l && i <= r) {
            curr = i;
            string rev = "";

            // Create the reverse number by subtracting each digit from 9
            for (char k : to_string(curr)) {
                rev += to_string(9 - (k - '0'));
            }

            // Update the answer with the maximum product of the current number and its reverse
            ans = max(ans, stoll(rev) * curr);
        }
    }

    // Print the maximum product found
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
