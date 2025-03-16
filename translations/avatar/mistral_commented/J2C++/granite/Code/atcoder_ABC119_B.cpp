

#include <iostream> // Including the necessary header files for input/output operations
#include <vector> // Including the necessary header file for vector data structure
#include <string> // Including the necessary header file for string data type
#include <numeric> // Including the necessary header file for parallel processing

using namespace std; // Using the'std' namespace for standard library functions

double solve(vector<double> x, vector<string> u) {
    return accumulate(x.begin(), x.end(), 0.0, // Using the 'accumulate' function from the 'numeric' library to calculate the sum of products of double values and their respective currency conversion factors
            [](double sum, double val, string curr) {
                return sum + (curr == "JPY"? val : val * 380000); // Using a lambda function to calculate the product of double value and its conversion factor based on the currency string
            });
}

int main() {
    int N; // Declaring an integer variable 'N' to store the number of elements

    // Reading the number of elements from the user input
    cin >> N;

    vector<double> x(N); // Declaring and initializing a vector 'x' of size 'N' to store the double values
    vector<string> u(N); // Declaring and initializing a vector 'u' of size 'N' to store the currency strings

    // Reading the double values and currency strings from the user input and storing them in respective vectors
    for (int i = 0; i < N; ++i) {
        cin >> x[i] >> u[i];
    }

    // Calling the'solve' method to find the sum of products of double values and their respective currency conversion factors
    cout << solve(x, u) << endl; // Printing the result to the console

    return 0; // Returning 0 to indicate successful execution of the program
}

