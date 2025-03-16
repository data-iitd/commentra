#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

// Function to read an integer input from the user
int next_int ( ) {
    // Read an integer input from the user and convert it to an integer
    return int(input());
}

// Function to read a list of integers from the user
vector<int> next_ints ( ) {
    // Read a list of integers from the user and convert each element to an integer
    string s;
    cin >> s;
    vector<int> v;
    for (int i = 0; i < s.size(); i++) {
        v.push_back(s[i] - '0');
    }
    return v;
}

// Main function
int main ( ) {
    // Read an integer `n` from the user
    int n = next_int();
    // Initialize a variable `t` to zero
    int t = 0;
    // Iterate through the range of integers from 0 to n-1
    for (int i = 0; i < n; i++) {
        // Check if the index i is odd
        if (i + 1 & 1) {
            // If it is odd, increment the variable t by 1
            t += 1;
        }
    }
    // Print the result t/n as the output
    cout << t / n << endl;
    return 0;
}

