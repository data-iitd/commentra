// Import necessary libraries
#include <iostream>     // For input and output
#include <string>      // For string manipulation
#include <numeric>     // For std::gcd
#include <vector>      // For std::vector

using namespace std;

int main() {
    // Read input values for n and m
    int n, m;
    cin >> n >> m;

    // Calculate the greatest common divisor (GCD) of n and m
    int gcd = std::gcd(n, m);

    // Read input strings s and t
    string s, t;
    cin >> s >> t;

    // Perform the required calculation and print the result
    long long result = -1;
    for (int k = 0; k < gcd; ++k) {
        if (s[k * n / gcd] != t[k * m / gcd]) {
            result = -1;
            break;
        }
    }

    if (result == -1) {
        result = (static_cast<long long>(n) * m) / gcd;
    }

    // Print the result
    cout << result << endl;

    return 0;
}

// <END-OF-CODE>
