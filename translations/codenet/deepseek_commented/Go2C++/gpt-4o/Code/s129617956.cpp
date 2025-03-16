#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

int main() {
    // Read an integer n from the standard input
    int n;
    cin >> n;

    // Calculate the square root of n and store it in rt
    int rt = static_cast<int>(sqrt(n));

    // Initialize minf to a large value, which will hold the minimum number of digits
    int minf = numeric_limits<int>::max();

    // Iterate from 1 to rt + 1 to find divisors of n
    for (int i = 1; i <= rt; i++) {
        if (n % i == 0) {
            // If i is a divisor of n, calculate the quotient b
            int b = n / i;

            // Count the number of digits in b
            int ndigit = 0;
            while (b > 0) {
                b /= 10;
                ndigit++;
            }

            // Update minf with the minimum number of digits found
            minf = min(minf, ndigit);
        }
    }

    // Print the minimum number of digits
    cout << minf << endl;

    return 0;
}

// <END-OF-CODE>
