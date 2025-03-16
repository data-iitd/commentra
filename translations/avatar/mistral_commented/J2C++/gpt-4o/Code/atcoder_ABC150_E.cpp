#include <iostream>     // For input and output
#include <vector>      // For using vectors
#include <algorithm>   // For sorting
#include <sstream>     // For string stream
using namespace std;

// Function to calculate the power of a number x raised to the power n
long long power(long long x, long long n, int mod) {
    if (n == 0) { // Base case when n is 0
        return 1;
    }
    long long val = power(x, n / 2, mod); // Recursively calculating the square of x raised to the power n/2
    val = (val * val) % mod; // Squaring the result
    if (n % 2 == 1) { // If n is odd, multiplying the result with x
        val = (val * x) % mod;
    }
    return val; // Returning the final result
}

int main() {
    ios::sync_with_stdio(false); // For faster input/output
    cin.tie(nullptr); // Untie cin and cout

    string line;
    getline(cin, line); // Reading the first line of input
    istringstream iss(line);
    int n;
    iss >> n; // Parsing the first element as an integer representing the size of the array

    getline(cin, line); // Reading the second line of input
    istringstream iss2(line);
    vector<int> c(n); // Creating a vector of size n

    // Initializing the vector c with the input values
    for (int i = 0; i < n; i++) {
        iss2 >> c[i];
    }

    int mod = 1000000007; // Defining a constant value for modulus

    // Checking if the size of the array is 1
    if (n == 1) {
        // Printing the result for the case when the size of the array is 1
        cout << (c[0] * 2LL) % mod << endl; // Using 2LL to ensure long long multiplication
        return 0; // Exiting the method after printing the result
    }

    // Sorting the vector c
    sort(c.begin(), c.end());

    // Calculating the values of b and a
    long long b = power(2, n, mod);
    long long a = power(2, n - 2, mod);

    // Initializing the variable ans to 0
    long long ans = 0;

    // Iterating through the vector from index 2 to n+1
    for (int i = 2; i <= n + 1; i++) {
        // Calculating the value of val using the current index i and the previously calculated value a
        long long val = (a * i) % mod;

        // Multiplying the value of val with the current element of the vector c[n+1-i]
        val = (val * c[n + 1 - i]) % mod;

        // Adding the value of val to the variable ans
        ans = (ans + val) % mod;
    }

    // Multiplying the value of ans with the value of b
    ans = (ans * b) % mod;

    // Printing the final result
    cout << ans << endl;

    return 0; // Indicating successful completion
}

// <END-OF-CODE>
