#include <bits/stdc++.h>
using namespace std;

int main() {
    // Read the first line of input and split it into an array of strings
    string s;
    cin >> s;
    vector<string> sa = split(s);
    
    // Parse the first element as an integer 'n'
    int n = stoi(sa[0]);
    
    // Read the second line of input and split it into an array of strings
    cin >> s;
    sa = split(s);
    
    // Initialize an integer array 'c' of size 'n'
    vector<int> c(n);
    
    // Populate the array 'c' with integers from the input
    for (int i = 0; i < n; i++) {
        c[i] = stoi(sa[i]);
    }
    
    // Define a modulus value for calculations
    int mod = 1000000007;
    
    // If there is only one element, calculate and print the result directly
    if (n == 1) {
        cout << c[0] * 2 % mod << endl;
        return 0;
    }
    
    // Sort the array 'c' in parallel
    sort(c.begin(), c.end());
    
    // Calculate powers of 2 for later use
    long b = power(2, n);
    long a = power(2, n - 2);
    
    // Initialize the answer variable
    long ans = 0;
    
    // Calculate the final answer using a loop
    for (int i = 2; i <= n + 1; i++) {
        // Calculate the value for the current iteration
        long val = a * i % mod;
        val *= c[n + 1 - i];
        val %= mod;
        
        // Accumulate the result
        ans += val;
        ans %= mod;
    }
    
    // Multiply the accumulated answer by 'b' and take modulus
    ans *= b;
    ans %= mod;
    
    // Print the final result
    cout << ans << endl;
    
    return 0;
}

// Method to calculate (x^n) % mod using recursion
long power(long x, long n) {
    // Base case: x^0 = 1
    if (n == 0) {
        return 1;
    }
    
    // Define a modulus value for calculations
    int mod = 1000000007;
    
    // Recursively calculate power
    long val = power(x, n / 2);
    
    // Square the result and take modulus
    val = val * val % mod;
    
    // If n is odd, multiply by x and take modulus
    if (n % 2 == 1) {
        val = val * x % mod;
    }
    
    // Return the final result
    return val;
}

// Method to split a string into an array of strings
vector<string> split(string s) {
    // Split the string into an array of strings
    vector<string> sa;
    istringstream iss(s);
    for (string str; iss >> str;) {
        sa.push_back(str);
    }
    return sa;
}

