

#include <iostream>
#include <iomanip>
#include <cmath>
#include <bigdecimal.h>

using namespace std;

int main() {
    // Initialize variables N, d, and x
    double N, d, x;
    cin >> N >> d >> x;

    // Initialize BigDecimal to store the result with precision
    BigDecimal ans("0.0");

    // Continue the loop until N is greater than 0.5
    while (N > 0.5) {
        // Calculate a value using BigDecimal for precision
        BigDecimal adnum(d + x * (N - 0.5));
        ans = ans.add(adnum);

        // Update the values of d and x based on the current value of N
        d = (N + 1.0) * d / N + (5.0 * x) / (2.0 * N);
        x = (1.0 + (2.0 / N)) * x;

        // Decrement N by 1 in each iteration
        N--;
    }

    // Print the result formatted to a specific number of decimal places
    cout << fixed << setprecision(20) << ans << endl;

    return 0;
}

