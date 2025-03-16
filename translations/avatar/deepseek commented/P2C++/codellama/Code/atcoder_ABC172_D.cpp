
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to read a single line from standard input and strip any trailing whitespace characters.
string rs() {
    string s;
    getline(cin, s);
    return s.substr(0, s.find_last_not_of(" \n\r\t") + 1);
}

// Function to read an integer from standard input.
int ri() {
    return stoi(rs());
}

// Function to read a list of strings from standard input.
vector<string> rs_() {
    vector<string> v;
    string s;
    while (getline(cin, s)) {
        v.push_back(s.substr(0, s.find_last_not_of(" \n\r\t") + 1));
    }
    return v;
}

// Function to read a list of integers from standard input.
vector<int> ri_() {
    vector<int> v;
    string s;
    while (getline(cin, s)) {
        v.push_back(stoi(s.substr(0, s.find_last_not_of(" \n\r\t") + 1)));
    }
    return v;
}

// Read the integer value of N from standard input.
int N = ri();

// Initialize the variable ans to 0.
int ans = 0;

// Start a loop that iterates from 1 to N + 1.
for (int i = 1; i <= N + 1; i++) {
    // Calculate the sum of multiples of i up to N using the formula for the sum of an arithmetic series.
    ans += i * (N / i) * (N / i + 1) / 2;
}

// Print the final value of ans, which represents the sum of multiples of numbers from 1 to N.
cout << ans << endl;

