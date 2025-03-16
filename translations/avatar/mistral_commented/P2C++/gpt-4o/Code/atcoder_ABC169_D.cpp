#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <limits>
#include <cmath>
#include <set>
#include <deque>
#include <string>
#include <sstream>
#include <iterator>
#include <functional>
#include <cassert>

using namespace std;

// Define constants
const long long INF = 999999999999999999LL;
const long long MOD = 1000000007;

// Function to prime factorize a number
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
    // Get the number of test cases
    int n;
    cin >> n;

    // Base case for the recursion
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    // Initialize variables
    vector<int> fac_ = prime_factorize(n);
    map<int, int> fac;
    for (int f : fac_) {
        fac[f]++;
    }
    
    long long ans = 0;

    // Calculate the answer
    for (const auto& [p, e] : fac) {
        int x = e;
        for (int i = 1; i < 1000000000; ++i) {
            if (x >= i) {
                x -= i;
                ans++;
            } else {
                break;
            }
        }
    }

    // Print the answer
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
