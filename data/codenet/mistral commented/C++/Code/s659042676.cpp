
#include <algorithm> // Header for standard library algorithms
#include <cmath>     // Header for mathematical functions
#include <iostream>  // Header for input/output operations
#include <limits>     // Header for numerical limits
#include <numeric>    // Header for numerical operations
#include <string>     // Header for string manipulation
#include <vector>     // Header for dynamic arrays

using namespace std; // Use the standard namespace for easier access to functions and variables

int main() {
    int a, b; // Declare two integer variables `a` and `b`

    // Read two integer values from the standard input using `cin`
    cin >> a >> b;

    // Calculate the difference between `6` and the sum of `a` and `b`
    int result = 6 - a - b;

    // Print the result to the standard output using `cout`
    cout << result << endl;
}