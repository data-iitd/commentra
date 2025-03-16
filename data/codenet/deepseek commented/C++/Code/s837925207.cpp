#include <iostream> // Include the iostream library for input and output operations.
#include <string>   // Include the string library for string operations.
#include <algorithm> // Include the algorithm library for various algorithms.
#include <vector>  // Include the vector library for using vectors.
#include <cmath>   // Include the cmath library for mathematical operations.
#include <functional> // Include the functional library for functional programming.
#define ll long long int // Define a macro for long long int.
using namespace std; // Use the standard namespace.

int h[6], w[6]; // Declare two global arrays of size 6.

int main() { // The main function is the entry point of the program.
    int x, ans = 0; // Declare an integer variable x and initialize ans to 0.

    cin >> x; // Read an integer from the standard input and store it in x.

    ans = x + x*x + x*x*x; // Calculate the result by adding x, x*x, and x*x*x.

    cout << ans << endl; // Print the result to the standard output.

    return 0; // Return 0 to indicate successful execution.
}
