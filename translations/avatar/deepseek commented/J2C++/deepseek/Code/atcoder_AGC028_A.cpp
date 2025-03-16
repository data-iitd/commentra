#include <iostream>
#include <numeric> // For std::gcd
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int gcd = gcd(n, m);
    string s, t;
    cin >> s >> t;

    // Filtering the range of the GCD and checking character mismatches
    for (int k = 0; k < gcd; ++k) {
        if (s[k * n / gcd] != t[k * m / gcd]) {
            cout << -1 << endl;
            return 0;
        }
    }

    // Calculating and printing the result
    cout << static_cast<long long>(n) * m / gcd << endl;

    return 0;
}
