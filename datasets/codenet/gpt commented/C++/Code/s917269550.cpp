#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Declare two long long integer variables to store input values
    long long x, y;

    // Read two integer values from standard input
    cin >> x >> y;

    // Check if the absolute difference between x and y is less than or equal to 1
    if (abs(x - y) <= 1) {
        // If the condition is true, output "Brown"
        cout << "Brown" << endl;
    } else {
        // If the condition is false, output "Alice"
        cout << "Alice" << endl;
    }

    return 0; // Return 0 to indicate successful execution
}
