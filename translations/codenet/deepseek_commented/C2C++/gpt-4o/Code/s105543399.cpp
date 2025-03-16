#include <iostream>
using namespace std;

int main() {
    long long n, a, m, M, c, i; // Declare variables to store input, current number, min, max, and loop index
    c = 0; // Initialize sum to 0
    m = 100000000; // Initialize minimum to a large positive value
    M = -100000000; // Initialize maximum to a large negative value
    cin >> n; // Read the number of elements

    // Loop through each element
    for (i = 1; i <= n; i++) {
        cin >> a; // Read the current number
        if (a > M) {
            M = a; // Update maximum if current number is greater
        }
        if (a < m) {
            m = a; // Update minimum if current number is smaller
        }
        c += a; // Add current number to sum
    }

    cout << m << " " << M << " " << c << endl; // Print the minimum, maximum, and sum of the numbers

    return 0;
}

// <END-OF-CODE>
