#include <bits/stdc++.h>

using namespace std;

// Define a large constant for infinity
const int inf = 1000000000;

// Define a modulus value commonly used in competitive programming
const int mod = 1000000007;

// Define directional movements for 4 directions (up, right, down, left)
const int dd[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

// Define diagonal movements for 8 directions (including diagonals)
const int ddn[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

// Function to read a line of input and return it as a list of integers
vector<int> LI() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    vector<int> v;
    int x;
    while (ss >> x) {
        v.push_back(x);
    }
    return v;
}

// Function to read a single integer from input
int I() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    int x;
    ss >> x;
    return x;
}

// Function to read a single float from input
float F() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    float x;
    ss >> x;
    return x;
}

// Function to read a line of input and return it as a list of strings
vector<string> LS() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    vector<string> v;
    string x;
    while (ss >> x) {
        v.push_back(x);
    }
    return v;
}

// Function to read a single string from input
string S() {
    string s;
    getline(cin, s);
    return s;
}

// Main function to execute the core logic of the program
int main() {
    // Read four integers from input
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    // Calculate the maximum value from the products of the pairs and return it
    cout << max(a * c, b * d, a * d, b * c) << endl;
    return 0;
}

// 