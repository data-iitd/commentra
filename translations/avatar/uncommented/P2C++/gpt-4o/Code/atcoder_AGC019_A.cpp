#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <limits>
#include <cmath>

using namespace std;

#define INF numeric_limits<long long>::max()
#define MOD 1000000007

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
    long long q, h, s, d;
    cin >> q >> h >> s >> d;
    long long n;
    cin >> n;

    long long best1L = min({q * 4, h * 2, s});
    long long best2L = min(d, best1L * 2);

    if (n % 2 == 0) {
        cout << best2L * (n / 2) << endl;
    } else {
        cout << best2L * (n / 2) + best1L << endl;
    }

    return 0;
}

// <END-OF-CODE>
