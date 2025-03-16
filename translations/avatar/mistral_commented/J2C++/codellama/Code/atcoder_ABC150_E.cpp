#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// Main method to start the execution of the program
int main() {
    // Reading the first line of input and splitting it into an array of strings
    string s;
    getline(cin, s);
    istringstream iss(s);
    vector<string> sa(istream_iterator<string>{iss}, istream_iterator<string>());
    int n = stoi(sa[0]); // Parsing the first element of the array as an integer representing the size of the array

    // Reading the second line of input and splitting it into an array of strings
    getline(cin, s);
    iss.str(s);
    sa = vector<string>(istream_iterator<string>{iss}, istream_iterator<string>());
    vector<int> c(n); // Creating an integer array of size n

    // Initializing the array c with the input values
    for (int i = 0; i < n; i++) {
        c[i] = stoi(sa[i]);
    }

    // Checking if the size of the array is 1
    if (n == 1) {
        // Printing the result for the case when the size of the array is 1
        cout << c[0] * 2 % 1000000007 << endl;
        return 0; // Exiting the method after printing the result
    }

    // Sorting the array c in parallel using std::sort() method
    sort(c.begin(), c.end());

    // Calculating the values of b and a
    long b = power(2, n);
    long a = power(2, n - 2);

    // Initializing the variable ans to 0
    long ans = 0;

    // Iterating through the array from index 2 to n+1
    for (int i = 2; i <= n + 1; i++) {
        // Calculating the value of val using the current index i and the previously calculated value a
        long val = a * i % 1000000007;

        // Multiplying the value of val with the current element of the array c[n+1-i]
        val *= c[n + 1 - i];

        // Taking the modulus of the product to ensure the result is within the range of modulus
        val %= 1000000007;

        // Adding the value of val to the variable ans
        ans += val;

        // Taking the modulus of the sum of ans and val to ensure the result is within the range of modulus
        ans %= 1000000007;
    }

    // Multiplying the value of ans with the value of b
    ans *= b;

    // Taking the modulus of the product to ensure the result is within the range of modulus
    ans %= 1000000007;

    // Printing the final result
    cout << ans << endl;

    return 0;
}

// Static method to calculate the power of a number x raised to the power n
long power(long x, long n) {
    if (n == 0) { // Base case when n is 0
        return 1;
    }

    int mod = 1000000007; // Defining a constant value for modulus
    long val = power(x, n / 2); // Recursively calculating the square of x raised to the power n/2

    // If n is odd, multiplying the result with x
    if (n % 2 == 1) {
        val = val * x % mod;
    }

    // Returning the final result
    return val;
}

