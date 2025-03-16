
#include <bits/stdc++.h>
using namespace std;

// Define constants for infinity, epsilon, and a modulus value
const int inf = 1001001001;
const long long infl = 1001001001001001001LL;
const double eps = 1e-10;
const long double pi = acos(-1);
const int mod = 1000000007;

// Define direction vectors for 4-way and 8-way movement
vector<pair<int, int>> dd = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<pair<int, int>> ddn = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

// Function to read a line of integers from input
vector<int> LI() {
    vector<int> a;
    int x;
    while (cin >> x) {
        a.push_back(x);
    }
    return a;
}

// Function to read a line of integers from input and convert them to zero-based index
vector<int> LI_() {
    vector<int> a;
    int x;
    while (cin >> x) {
        a.push_back(x - 1);
    }
    return a;
}

// Function to read a line of floats from input
vector<double> LF() {
    vector<double> a;
    double x;
    while (cin >> x) {
        a.push_back(x);
    }
    return a;
}

// Function to read a line of strings from input
vector<string> LS() {
    vector<string> a;
    string s;
    while (cin >> s) {
        a.push_back(s);
    }
    return a;
}

// Function to read a single integer from input
int I() {
    int x;
    cin >> x;
    return x;
}

// Function to read a single float from input
double F() {
    double x;
    cin >> x;
    return x;
}

// Function to read a single string from input
string S() {
    string s;
    cin >> s;
    return s;
}

// Function to print a string and flush the output buffer
void pf(string s) {
    cout << s << flush;
}

// Main function to process the input and return the result
int main() {
    // Reading a string from input
    string s;
    cin >> s;
    // Reading an integer k from input
    int k;
    cin >> k;
    int l = 0;  // Initialize a counter for leading '1's

    // Count the number of leading '1's in the string
    for (char c : s) {
        if (c!= '1') {
            break;
        }
        l++;
    }

    // If the count of leading '1's is greater than or equal to k, return 1
    if (l >= k) {
        return 1;
    }

    // Otherwise, return the character at position l in the string
    return s[l];
}

// Print the result of the main function
cout << main() << endl;

Translate the above Python code to Java and end with comment "