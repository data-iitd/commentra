#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int l, r;
    cin >> l >> r; // Taking the range as input from the user

    int curr = r;
    int s = 0; // Initialize curr to r and s to 0

    while (curr) {
        s += 1;
        curr /= 10; // Determine the number of digits in r and store it in s
    }

    int first = 1;
    for (int i = 0; i < s; i++) {
        first *= 10; // Calculate the smallest number with s digits
    }
    int second = first / 2; // Calculate half of the smallest number with s digits

    int ans = -1; // Initialize ans to -1 to store the maximum product found

    for (int i : {l, r, first, second}) {
        if (i >= l && i <= r) {
            curr = i;
            string rev = "";
            for (char k : to_string(curr)) {
                rev += to_string(9 - (k - '0')); // Reverse the digits
            }
            ans = max(ans, stoi(rev) * curr); // Calculate the product and update ans if necessary
        }
    }

    cout << ans << endl; // Print the maximum product found
    return 0;
}
// <END-OF-CODE>
