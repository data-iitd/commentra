
#include <bits/stdc++.h>
using namespace std;

// Define a large constant for infinity
const int inf = 1000000000;

// Define a modulus value commonly used in competitive programming
const int mod = 1000000007;

// Define directional movements for 4 directions (up, right, down, left)
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// Define diagonal movements for 8 directions (including diagonals)
const int ddx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int ddy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

// Function to read a line of input and return it as a list of integers
vector<int> LI() {
    vector<int> res;
    int x;
    while (cin >> x) {
        res.push_back(x);
    }
    return res;
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

// Function to read a line of input and return it as a list of strings
vector<string> LS() {
    vector<string> res;
    string s;
    while (cin >> s) {
        res.push_back(s);
    }
    return res;
}

// Function to read a single string from input
string S() {
    string s;
    cin >> s;
    return s;
}

// Main function to execute the core logic of the program
int main() {
    // Read four integers from input
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    // Calculate the maximum value from the products of the pairs and return it
    return max({a * c, b * d, a * d, b * c});
}

// Print the result of the main function
cout << main() << endl;
