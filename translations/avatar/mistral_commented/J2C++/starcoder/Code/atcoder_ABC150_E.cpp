#include <bits/stdc++.h>
using namespace std;

int main() {
    // Reading the first line of input and splitting it into an array of strings
    string s;
    cin >> s;
    vector<string> sa = split(s,'');

    // Parsing the first element of the array as an integer representing the size of the array
    int n = stoi(sa[0]);

    // Reading the second line of input and splitting it into an array of strings
    cin >> s;
    sa = split(s,'');

    // Creating an integer array of size n
    int c[n];

    // Initializing the array c with the input values
    for (int i = 0; i < n; i++) {
        c[i] = stoi(sa[i]);
    }

    // Defining a constant value for modulus
    int mod = 1000000007;

    // Checking if the size of the array is 1
    if (n == 1) {
        // Printing the result for the case when the size of the array is 1
        cout << c[0] * 2 % mod << endl;
        return 0; // Exiting the program after printing the result
    }

    // Sorting the array c in parallel using sort() function
    sort(c.begin(), c.end());

    // Calculating the values of b and a
    long long b = power(2, n);
    long long a = power(2, n - 2);

    // Initializing the variable ans to 0
    long long ans = 0;

    // Iterating through the array from index 2 to n+1
    for (int i = 2; i <= n + 1; i++) {
        // Calculating the value of val using the current index i and the previously calculated value a
        long long val = a * i % mod;

        // Multiplying the value of val with the current element of the array c[n+1-i]
        val *= c[n + 1 - i];

        // Taking the modulus of the product to ensure the result is within the range of modulus
        val %= mod;

        // Adding the value of val to the variable ans
        ans += val;

        // Taking the modulus of the sum of ans and val to ensure the result is within the range of modulus
        ans %= mod;
    }

    // Multiplying the value of ans with the value of b
    ans *= b;

    // Taking the modulus of the product to ensure the result is within the range of modulus
    ans %= mod;

    // Printing the final result
    cout << ans << endl;

    return 0;
}

// Static method to calculate the power of a number x raised to the power n
long long power(long long x, long long n) {
    if (n == 0) { // Base case when n is 0
        return 1;
    }

    int mod = 1000000007; // Defining a constant value for modulus
    long long val = power(x, n / 2); // Recursively calculating the square of x raised to the power n/2

    // If n is odd, multiplying the result with x
    if (n % 2 == 1) {
        val = val * x % mod;
    }

    // Returning the final result
    return val;
}

// Function to split a string s into an array of strings using the delimiter d
vector<string> split(string s, char d) {
    int n = s.length(); // Getting the length of the string s
    vector<string> ans; // Creating an empty vector of strings to store the split strings

    // Iterating through the string from index 0 to n-1
    for (int i = 0; i < n; i++) {
        // If the character at the current index is equal to the delimiter
        if (s[i] == d) {
            // Creating a substring from the index 0 to the current index
            string temp = s.substr(0, i);

            // Adding the substring to the vector of strings
            ans.push_back(temp);

            // Removing the substring from the string s
            s.erase(0, i + 1);

            // Updating the length of the string s
            n = s.length();

            // Updating the current index to 0
            i = -1;
        }
    }

    // Adding the remaining substring to the vector of strings
    ans.push_back(s);

    // Returning the vector of strings
    return ans;
}

