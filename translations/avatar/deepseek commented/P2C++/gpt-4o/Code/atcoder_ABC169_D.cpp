#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;

const long long INF = 999999999999999999LL;  // Constant for infinity
const long long MOD = 1000000007;  // Constant for a large prime number

vector<int> prime_factorize(int n) {
    vector<int> factors;
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }
    for (int f = 3; f * f <= n; f += 2) {
        while (n % f == 0) {
            factors.push_back(f);
            n /= f;
        }
    }
    if (n > 1) {
        factors.push_back(n);
    }
    return factors;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;  // Read the integer n
    if (n == 1) {
        cout << 0 << endl;  // If n is 1, print 0 and exit
        return 0;
    }

    vector<int> fac_ = prime_factorize(n);  // Get the prime factorization of n
    map<int, int> fac;  // Count the occurrences of each prime factor
    for (int f : fac_) {
        fac[f]++;
    }

    long long ans = 0;
    for (const auto& [p, e] : fac) {
        int x = e;
        for (int i = 1; i < 99999999; ++i) {
            if (x >= i) {
                x -= i;
                ans++;
            } else {
                break;
            }
        }
    }

    cout << ans << endl;  // Print the final answer
    return 0;
}

// <END-OF-CODE>
