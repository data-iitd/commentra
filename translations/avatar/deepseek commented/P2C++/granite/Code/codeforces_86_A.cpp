

#include <bits/stdc++.h>
using namespace std;

int main() {
    int l, r;
    cin >> l >> r;
    // Taking the range as input from the user

    int curr = r;
    int s = 0;
    // Initialize curr to r and s to 0

    while (curr) {
        s++;
        curr /= 10;
    }
    // Determine the number of digits in r and store it in s

    int first = pow(10, s);
    int second = first / 2;
    // Calculate the smallest number with s digits and its half

    int ans = -1;
    // Initialize ans to -1 to store the maximum product found

    for (int i : {l, r, first, second}) {
        if (i >= l && i <= r) {
            curr = i;
            string rev = "";
            for (char k : to_string(curr)) {
                rev += to_string(9 - (k - '0'));
            }
            ans = max(ans, stoi(rev) * curr);
        }
    }
    // Iterate over the specified numbers, check if they are within the range,
    // reverse the digits, calculate the product, and update ans if necessary

    cout << ans << endl;
    // Print the maximum product found

    return 0;
}
