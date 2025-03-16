#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    // Take two integers as input and store them in 'l' and 'r' respectively
    int l, r;
    cin >> l >> r;

    // Initialize current number to 'r'
    int curr = r;

    // Initialize sum variable 's' to 0
    int s = 0;

    // Initialize the answer variable 'ans' with a negative value
    int ans = -1;

    // While 'curr' is not zero, perform the following operations
    while (curr) {
        // Increment the sum 's' by 1
        s++;

        // Calculate the power of 10 raised to the value of 's' and store it in 'first'
        int first = pow(10, s);

        // Calculate half of 'first' and store it in 'second'
        int second = first / 2;

        // Iterate through the list containing 'l', 'r', 'first', and 'second'
        for (int i : {l, r, first, second}) {
            // If 'i' lies within the range of 'l' and 'r', update 'curr'
            if (i >= l && i <= r) {
                curr = i;
                string rev = "";

                // Reverse the digits of 'curr' and store it in 'rev'
                for (char k : to_string(curr)) {
                    rev += to_string(9 - (k - '0'));
                }

                // Update 'ans' with the maximum value of the current 'ans' and the product of 'curr' and the reversed number
                ans = max(ans, stoi(rev) * curr);
            }
        }
    }

    // Print the final answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
