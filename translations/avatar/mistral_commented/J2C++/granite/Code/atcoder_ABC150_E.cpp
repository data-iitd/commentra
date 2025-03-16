
#include <iostream> // Including the necessary header files for input/output operations
#include <vector> // Including the necessary header file for vector data structure
#include <algorithm> // Including the necessary header file for sorting the vector in parallel

using namespace std; // Using the standard namespace for simplifying the code

int main() {
    int mod = 1000000007; // Defining a constant value for modulus
    int n; // Declaring an integer variable n to store the size of the array
    cin >> n; // Reading the size of the array from the input

    vector<int> c(n); // Creating a vector of size n to store the input values

    // Iterating through the vector c and reading the input values
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    // Sorting the vector c in parallel using std::sort() function
    sort(c.begin(), c.end());

    long b = 1; // Initializing the variable b to 1
    long a = 1; // Initializing the variable a to 1

    // Iterating through the vector c from index 2 to n+1
    for (int i = 2; i <= n + 1; i++) {
        // Calculating the value of b using the current index i and the previously calculated value a
        b = (b * 2) % mod;

        // Calculating the value of a using the current index i and the previously calculated value a
        a = (a * 2) % mod;
    }

    long ans = 0; // Initializing the variable ans to 0

    // Iterating through the vector c from index 2 to n+1
    for (int i = 2; i <= n + 1; i++) {
        // Calculating the value of val using the current index i and the previously calculated value a
        long val = (a * i) % mod;

        // Multiplying the value of val with the current element of the vector c[n+1-i]
        val = (val * c[n + 1 - i]) % mod;

        // Adding the value of val to the variable ans
        ans = (ans + val) % mod;
    }

    // Multiplying the value of ans with the value of b
    ans = (ans * b) % mod;

    // Printing the final result
    cout << ans << endl; // Printing the final result followed by a newline character

    return 0; // Returning 0 to indicate successful execution of the program
}

