#include <iostream> // Include the iostream library for input and output
#include <string>   // Include the string library for string manipulations (not used in this code)
#include <algorithm>// Include the algorithm library for various algorithms (not used in this code)
#include <vector>  // Include the vector library for using vectors (not used in this code)
#include <cmath>   // Include the cmath library for mathematical functions (not used in this code)
#include <functional> // Include the functional library for function objects (not used in this code)
#define ll long long int // Define 'll' as a shorthand for 'long long int'
using namespace std; // Use the standard namespace

// Declare arrays to hold height and width values (not used in this code)
int h[6], w[6];

int main() {
    int x, ans = 0; // Declare variables x for input and ans for the result

    // Read an integer input from the user
    cin >> x;

    // Calculate the result as the sum of x, x squared, and x cubed
    ans = x + x*x + x*x*x;

    // Output the calculated result to the console
    cout << ans << endl;

    return 0; // Return 0 to indicate successful completion of the program
}


