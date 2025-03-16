#include <iostream>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Calculate gcd
    int gcd = std::gcd(n, m);

    string s, t;
    cin >> s >> t;

    long long result = n * 1LL * m / gcd; // Default result if no mismatch is found

    for (int k = 0; k < gcd; ++k) {
        if (s[k * n / gcd] != t[k * m / gcd]) {
            result = -1; // Found a mismatch
            break;
        }
    }

    cout << result << endl;

    return 0;
}

// <END-OF-CODE>
