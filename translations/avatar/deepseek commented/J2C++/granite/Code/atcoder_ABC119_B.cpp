
#include <iostream> // Include iostream for input/output operations
#include <string> // Include string for string operations
#include <numeric> // Include numeric for stream operations
#include <vector> // Include vector for array operations

using namespace std; // Use the standard namespace

int main() {
    int N; // Declare the variable N to store the number of elements
    cin >> N; // Read the number of elements N from the user

    vector<double> x(N); // Initialize the vector to store the values
    vector<string> u(N); // Initialize the vector to store the currencies

    // Read the values into the vectors x and u
    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> u[i];
    }

    // Define the solve function to calculate the total value based on the currency
    auto solve = [](const vector<double>& x, const vector<string>& u) {
        return accumulate(begin(x), end(x), 0.0, [&](double sum, double val) {
            return sum + (u[i] == "JPY"? val : val * 380000);
        });
    };

    // Call the solve function and print the result
    cout << solve(x, u) << endl; // Print the result
    return 0; // Return 0 to indicate successful execution
}

