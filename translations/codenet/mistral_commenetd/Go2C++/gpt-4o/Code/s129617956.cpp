#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Function to read an integer from standard input
int nextInt() {
    int n;
    cin >> n;
    return n;
}

// Function to find the minimum of two integers
int min(int i, int j) {
    return (i < j) ? i : j;
}

int main() {
    // Read an integer from standard input
    int n = nextInt();
    int rt = static_cast<int>(sqrt(n)); // Calculate the square root of n

    // Initialize minimum factor with a large value
    int minf = 100;

    // Check divisibility for numbers from 1 to the square root of n
    for (int i = 1; i <= rt; i++) {
        // Check if n is divisible by i
        if (n % i == 0) {
            // Calculate the number of digits in the divisor
            int b = n / i;
            int ndigit = 0;
            while (b > 0) {
                b /= 10;
                ndigit++;
            }
            // Update minimum factor if a divisor with fewer digits is found
            minf = min(minf, ndigit);
        }
    }

    // Print the result
    cout << minf << endl;

    return 0;
}

// <END-OF-CODE>
