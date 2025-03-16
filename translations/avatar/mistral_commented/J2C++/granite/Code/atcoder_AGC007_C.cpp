

#include <iostream> // Including the necessary libraries for input/output operations
#include <cmath> // Including the necessary library for mathematical functions
#include <iomanip> // Including the necessary library for formatting the output

using namespace std; // Using the standard namespace for input/output operations

int main() {
    double N, d, x; // Declaring the input variables as double type

    // Reading input values from the user
    cin >> N >> d >> x;

    double ans = 0.0; // Initializing an answer variable with zero value

    // Calculating the answer using the given formula
    while (N > 0.5) {
        double adnum = (d + x * (N - 0.5)); // Calculating the next term of the sum
        ans += adnum; // Adding the next term to the answer

        // Updating the values of d and x for the next iteration
        d = (N + 1.0) * d / N + (5.0 * x) / (2.0 * N);
        x = (1.0 + (2.0 / N)) * x;

        --N; // Decreasing the value of N by 1 for the next iteration
    }

    // Formatting the output with 20 decimal places
    cout << fixed << setprecision(20) << ans << endl; // Printing the final answer with 20 decimal places

    return 0; // Returning 0 to indicate successful execution of the program
}

These comments should provide a clear understanding of the code's functionality and logic.