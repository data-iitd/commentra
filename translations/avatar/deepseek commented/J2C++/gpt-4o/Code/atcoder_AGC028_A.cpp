#include <iostream> // For input and output
#include <string>   // For string manipulation
#include <numeric>  // For std::gcd
#include <vector>   // For std::vector
#include <algorithm> // For std::find_if

using namespace std;

int main() {
    int n, m;
    cin >> n >> m; // Reading the first two integers
    int gcd = std::gcd(n, m); // Calculating the GCD of n and m
    string s, t;
    cin >> s >> t; // Reading the two strings

    // Filtering the range of the GCD and checking character mismatches
    for (int k = 0; k < gcd; ++k) {
        if (s[k * n / gcd] != t[k * m / gcd]) {
            cout << -1 << endl; // If there's a mismatch, print -1
            return 0; // Exit the program
        }
    }

    // Calculating and printing the result
    cout << (static_cast<long long>(n) * m / gcd) << endl;
    return 0;
}

// <END-OF-CODE>
