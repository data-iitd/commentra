#include <iostream>
using namespace std;

int main(void) {
    // Declare two long long integer variables to hold the input values
    long long int a, b;

    // Read two integers from the standard input
    cin >> a >> b;

    // Check if the sum of a and b is even
    if ((a + b) % 2 == 0) {
        // If the sum is even, calculate and output the average
        cout << (a + b) / 2 << "\n";
    } else {
        // If the sum is odd, output "IMPOSSIBLE"
        cout << "IMPOSSIBLE\n";
    }
}
