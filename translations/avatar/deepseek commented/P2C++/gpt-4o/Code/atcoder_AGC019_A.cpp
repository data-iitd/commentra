#include <iostream>
#include <algorithm>
#include <numeric>
#include <limits>
#include <cmath>

using namespace std;

#define MOD 1000000007
#define INF numeric_limits<long long>::max()

long long gcd(long long a, long long b) {
    while (b) {
        swap(a, b);
        b %= a;
    }
    return a;
}

long long lcm(long long x, long long y) {
    return (x * y) / gcd(x, y);
}

long long lcm_list(const vector<long long>& nums) {
    return accumulate(nums.begin(), nums.end(), 1LL, lcm);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long q, h, s, d;
    cin >> q >> h >> s >> d;
    long long n;
    cin >> n;

    // Calculating the best price for single liters
    long long best1L = min({q * 4, h * 2, s});

    // Calculating the best price for double liters
    long long best2L = min(d, best1L * 2);

    // Checking if the quantity n is even or odd and printing the total cost accordingly
    if (n % 2 == 0) {
        cout << best2L * (n / 2) << endl;
    } else {
        cout << best2L * (n / 2) + best1L << endl;
    }

    return 0;
}

// <END-OF-CODE>
