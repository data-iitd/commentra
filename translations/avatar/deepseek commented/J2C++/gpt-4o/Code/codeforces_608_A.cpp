#include <iostream> // Including iostream for standard input and output
#include <vector> // Including vector for dynamic array
#include <algorithm> // Including algorithm for max function
#include <sstream> // Including sstream for string stream
#include <string> // Including string for string operations

using namespace std; // Using the standard namespace

int main() { // Main function is the entry point
    int n, s; // Declaring variables for number of pairs and the threshold
    cin >> n >> s; // Reading the first two integers from standard input
    int max_sum = 0; // Initializing max_sum to store the maximum sum of f and t

    while (n-- > 0) { // Looping n times
        int f, t; // Declaring variables for the pair values
        cin >> f >> t; // Reading the pair values from standard input
        max_sum = max(max_sum, f + t); // Updating max_sum with the maximum of current max_sum and the sum of f and t
    }

    cout << max(max_sum, s) << endl; // Printing the maximum of max_sum and s
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
