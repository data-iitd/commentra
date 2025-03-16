
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// Function to read a line from standard input and remove trailing whitespace
string rs() {
    string s;
    getline(cin, s);
    return s.substr(0, s.find_last_not_of(" \n\r\t") + 1);
}

// Function to read an integer from standard input
int ri() {
    string s = rs();
    return stoi(s);
}

// Function to read a line from standard input and return a vector of strings
vector<string> rs_() {
    string s = rs();
    istringstream ss(s);
    vector<string> v;
    string t;
    while (ss >> t) {
        v.push_back(t);
    }
    return v;
}

// Function to read a line from standard input and return a vector of integers
vector<int> ri_() {
    vector<string> v = rs_();
    vector<int> vi;
    for (string s : v) {
        vi.push_back(stoi(s));
    }
    return vi;
}

// Read the integer N from input
int N = ri();

// Initialize the answer variable to accumulate the result
int ans = 0;

// Loop through each integer from 1 to N (inclusive)
for (int i = 1; i <= N; i++) {
    // Calculate the contribution of the current integer i to the answer
    ans += i * (N / i) * (N / i + 1) / 2;
}

// Print the final result
cout << ans << endl;

