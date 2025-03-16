#include <iostream> // Including iostream for input and output
#include <iomanip>  // Including iomanip for setting output precision
#include <cmath>    // Including cmath for mathematical operations
#include <string>   // Including string for string manipulations
#include <sstream>  // Including sstream for string stream operations

using namespace std;

int main() {
    double N, d, x; // Declaring variables for user input
    cin >> N >> d >> x; // Reading input values from the user

    double ans = 0.0; // Initializing an answer variable with zero value

    // Calculating the answer using the given formula
    while (N > 0.5) {
        double adnum = d + x * (N - 0.5); // Calculating the next term of the sum
        ans += adnum; // Adding the next term to the answer

        // Updating the values of d and x for the next iteration
        d = (N + 1.0) * d / N + (5.0 * x) / (2.0 * N);
        x = (1.0 + (2.0 / N)) * x;

        --N; // Decreasing the value of N by 1 for the next iteration
    }

    // Setting the output to display 20 decimal places
    cout << fixed << setprecision(20) << ans << endl; // Printing the final answer with 20 decimal places

    return 0; // Indicating that the program ended successfully
}

// <END-OF-CODE>
