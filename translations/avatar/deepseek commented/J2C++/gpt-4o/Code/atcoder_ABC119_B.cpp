#include <iostream> // Include iostream for input and output operations
#include <vector>   // Include vector for dynamic array
#include <string>   // Include string for handling strings
#include <numeric>  // Include numeric for accumulate function

using namespace std;

int main() {
    int N; // Variable to store the number of elements
    cin >> N; // Read the number of elements N from the user
    vector<double> x(N); // Initialize a vector to store the values
    vector<string> u(N); // Initialize a vector to store the currencies

    // Read the values into the vectors x and u
    for (int i = 0; i < N; ++i) {
        cin >> x[i]; // Read the value
        cin >> u[i]; // Read the currency
    }

    // Call the solve function and print the result
    double result = 0.0;
    for (int i = 0; i < N; ++i) {
        result += (u[i] == "JPY") ? x[i] : x[i] * 380000; // Calculate total value based on currency
    }
    cout << result << endl; // Output the result

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
