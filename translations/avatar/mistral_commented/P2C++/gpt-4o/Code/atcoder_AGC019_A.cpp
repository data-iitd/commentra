#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <limits>

using namespace std;

// Define constants
const long long INF = numeric_limits<long long>::max();
const long long MOD = 1e9 + 7;

// Helper functions
long long ceil_div(long long a, long long b = 1) {
    return (a + b - 1) / b;
}

long long lcm(long long x, long long y) {
    return (x * y) / __gcd(x, y);
}

long long lcm_list(const vector<long long>& nums) {
    return accumulate(nums.begin(), nums.end(), 1LL, lcm);
}

int main() {
    // Read input
    long long q, h, s, d;
    cin >> q >> h >> s >> d;
    long long n;
    cin >> n;

    // Calculate the length of the longest segment that can be formed
    long long best1L = min({q * 4, h * 2, s});
    long long best2L = min(d, best1L * 2);

    // Check if n is even
    if (n % 2 == 0) {
        // If it is, print the length of the longest segment that can be formed
        cout << best2L * (n / 2) << endl;
    } else {
        // If n is odd, print the length of the longest segment that can be formed
        cout << best2L * (n / 2) + best1L << endl;
    }

    return 0;
}

// <END-OF-CODE>
