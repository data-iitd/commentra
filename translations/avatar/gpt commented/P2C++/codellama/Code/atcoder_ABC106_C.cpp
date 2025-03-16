
#include <bits/stdc++.h>

using namespace std;

// Defining constants for infinity, epsilon, and a modulus value
const int inf = 1000000000;
const double eps = 1.0 / 1000000000;
const int mod = 1000000007;

// Defining direction vectors for 4-way and 8-way movement
const int dd[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

const int ddn[8][2] = {
    {-1, 0},
    {-1, 1},
    {0, 1},
    {1, 1},
    {1, 0},
    {1, -1},
    {0, -1},
    {-1, -1}
};

// Function to read a line of integers from input
vector<int> LI() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    vector<int> v;
    int i;
    while (ss >> i) {
        v.push_back(i);
    }
    return v;
}

// Function to read a line of integers from input and convert them to zero-based index
vector<int> LI_() {
    vector<int> v = LI();
    for (int i = 0; i < v.size(); i++) {
        v[i]--;
    }
    return v;
}

// Function to read a line of floats from input
vector<float> LF() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    vector<float> v;
    float i;
    while (ss >> i) {
        v.push_back(i);
    }
    return v;
}

// Function to read a line of strings from input
vector<string> LS() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    vector<string> v;
    string i;
    while (ss >> i) {
        v.push_back(i);
    }
    return v;
}

// Function to read a single integer from input
int I() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    int i;
    ss >> i;
    return i;
}

// Function to read a single float from input
float F() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    float i;
    ss >> i;
    return i;
}

// Function to read a single string from input
string S() {
    string s;
    getline(cin, s);
    return s;
}

// Function to print a string and flush the output buffer
void pf(string s) {
    cout << s << flush;
}

// Main function to process the input and return the result
int main() {
    // Reading a string from input
    string s = S();
    // Reading an integer k from input
    int k = I();
    int l = 0;  // Initialize a counter for leading '1's

    // Count the number of leading '1's in the string
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '1') {
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

// 