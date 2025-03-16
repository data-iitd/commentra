#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Define two helper functions to read input from the standard input stream
string S( ) { string s; cin >> s; return s; }
int I( ) { int i; cin >> i; return i; }

// Define another helper function to read a list of integers from the standard input stream
vector<int> LI( ) { vector<int> v; int i; while (cin >> i) v.push_back(i); return v; }

// Define another helper function to read a list of strings from the standard input stream
vector<string> LS( ) { vector<string> v; string s; while (cin >> s) v.push_back(s); return v; }

// Define two variables and initialize them with the values read from the standard input stream
int a, b; cin >> a >> b;

// Check if 'a' is positive
if (a > 0) {
    // If it is, print the string 'Positive'
    cout << "Positive" << endl;
}

// If 'a' is not positive, check if 'b' is non-negative
else if (a <= 0 && b >= 0) {
    // If it is, print the string 'Zero'
    cout << "Zero" << endl;
}

// If neither 'a' nor 'b' satisfy the above conditions, check if the sum of 'a' and 'b' is even
else {
    // If it is, print the string 'Negative'
    if ((a + b) % 2 == 0) {
        cout << "Negative" << endl;
    }
    // Otherwise, print the string 'Positive'
    else {
        cout << "Positive" << endl;
    }
}

