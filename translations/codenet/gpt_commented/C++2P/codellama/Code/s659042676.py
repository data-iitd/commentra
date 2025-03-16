#include <algorithm> // Include algorithms for potential future use
#include <cmath>     // Include cmath for mathematical functions
#include <iostream>  // Include iostream for input and output
#include <limits>    // Include limits for numeric limits
#include <numeric>   // Include numeric for numeric operations
#include <string>    // Include string for string manipulations
#include <vector>    // Include vector for using the vector container

using namespace std;

int main() {
    int a, b; // Declare two integer variables to store input values

    // Read two integer values from standard input
    cin >> a >> b;

    // Calculate and output the result of the expression (6 - a - b)
    // This assumes that a and b are part of a game or problem where their sum should not exceed 6
    cout << 6 - a - b << endl;

    return 0; // Return 0 to indicate successful completion of the program
}

