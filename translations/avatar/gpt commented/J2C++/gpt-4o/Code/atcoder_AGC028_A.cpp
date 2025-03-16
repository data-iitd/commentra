#include <iostream>
#include <string>
#include <numeric> // for std::gcd
#include <vector>

using namespace std;

int main() {
    // Read two integers n and m from input
    int n, m;
    cin >> n >> m;

    // Calculate the greatest common divisor (gcd) of n and m
    int gcd = std::gcd(n, m);

    // Read two strings s and t from input
    string s, t;
    cin >> s >> t;

    // Check for mismatches in the characters of the two strings based on the gcd
    // If a mismatch is found, return -1; otherwise, return the least common multiple (lcm) of n and m
    for (int k = 0; k < gcd; ++k) {
        if (s[k * n / gcd] != t[k * m / gcd]) {
            cout << -1 << endl; // Mismatch found
            return 0;
        }
    }

    // Calculate lcm
    long long lcm = (long long)n * (m / gcd);
    cout << lcm << endl;

    return 0;
}

// <END-OF-CODE>
