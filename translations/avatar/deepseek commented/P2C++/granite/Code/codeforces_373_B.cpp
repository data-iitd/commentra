

#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

ll sum(ll k) {
    // Initialize the return value and other variables
    ll ret = 0, pw = 10, len = 1;
    // Loop to calculate the sum of digits from 1 to k
    while (true) {
        // Calculate the current range of numbers
        ll cur = min(pw - 1, k);
        ll prev = pw / 10;
        // Add the count of numbers in the current range to the result
        ret += (cur - prev + 1) * len;
        // Break the loop if the current range exceeds k
        if (pw - 1 >= k) break;
        // Update the length and power of ten for the next range
        len += 1;
        pw *= 10;
    }
    return ret;
}

int main() {
    // Read input values for w, m, and k
    ll w, m, k;
    cin >> w >> m >> k;

    // Initialize the binary search range
    ll lo = 0, hi = 1e18;

    // Perform binary search to find the maximum md
    while (hi - lo > 1) {
        ll md = (lo + hi) / 2;
        // Calculate the count of numbers in the range [m, m+md-1]
        ll c = sum(m + md - 1) - sum(m - 1);
        // Adjust the search range based on the condition
        if (c * k <= w) lo = md;
        else hi = md;
    }

    // Print the result of the binary search
    cout << lo << endl;

    return 0;
}

