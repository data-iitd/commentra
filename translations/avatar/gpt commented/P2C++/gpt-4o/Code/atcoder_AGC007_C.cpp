#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Read the input values for N, d, and x
    int N;
    double d, x;
    cin >> N >> d >> x;

    // Initialize the result variable to accumulate the final value
    double ret = 0;

    // Loop until N becomes zero
    while (N) {
        // Update the result by adding the current d and a calculated value based on N and x
        ret += d + (N - 0.5) * x;

        // Update d based on its current value, N, and x
        d = d + (d / N) + (5 * x) / (2 * N);

        // Update x based on its current value and N
        x += 2 * x / N;

        // Decrement N to move to the next iteration
        N--;
    }

    // Print the accumulated result
    cout << fixed << setprecision(10) << ret << endl;

    return 0;
}

// <END-OF-CODE>
