#include <iostream> // Including iostream for input and output
#include <vector>   // Including vector for dynamic array
#include <string>   // Including string for handling strings
#include <numeric>  // Including numeric for accumulate function

using namespace std;

int main() {
    int N; // Declaring an integer variable 'N' to store the number of elements

    // Reading the number of elements from the user input
    cin >> N;

    vector<double> x(N); // Declaring and initializing a vector 'x' of size 'N' to store the double values
    vector<string> u(N); // Declaring and initializing a vector 'u' of size 'N' to store the currency strings

    // Reading the double values and currency strings from the user input and storing them in respective vectors
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
        cin >> u[i];
    }

    // Calling the 'solve' function to find the sum of products of double values and their respective currency conversion factors
    cout << solve(x, u) << endl;

    return 0; // Returning 0 to indicate successful execution
}

double solve(const vector<double>& x, const vector<string>& u) {
    double total = 0.0; // Variable to store the total sum

    // Looping through the elements to calculate the total sum based on currency conversion
    for (size_t i = 0; i < x.size(); ++i) {
        total += x[i] * (u[i] == "JPY" ? 1 : 380000); // Multiplying the double value with the conversion factor based on the currency string
    }

    return total; // Returning the total sum
}

// <END-OF-CODE>
