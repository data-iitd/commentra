#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

// Define constants
const int mod = 1000000007;

// Read an integer from standard input and return it
int ii1() {
    int i;
    cin >> i;
    return i;
}

// Read a string from standard input and return it
string is1() {
    string s;
    cin >> s;
    return s;
}

// Read a list of integers from standard input and return it
vector<int> iia() {
    string s;
    cin >> s;
    vector<int> v;
    for (int i = 0; i < s.size(); i++) {
        v.push_back(s[i] - '0');
    }
    return v;
}

// Read a list of strings from standard input and return it, split by spaces
vector<string> isa() {
    string s;
    cin >> s;
    vector<string> v;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            v.push_back(s.substr(0, i));
            s = s.substr(i + 1);
            i = -1;
        }
    }
    v.push_back(s);
    return v;
}

// Set the value of k from standard input
int k = ii1();

// Initialize a variable t to 0
int t = 0;

// Loop from 1 to k
for (int i = 1; i <= k; i++) {
    // Calculate the value of t using the current value of i and k
    t = ( (t % k) * 10 + 7 ) % k;
    
    // Check if t is a multiple of k
    if (t == 0) {
        // Print the value of i and break out of the loop
        cout << i << endl;
        break;
    }
}

// If the loop completes without finding a multiple of k, print -1
if (t != 0) {
    cout << -1 << endl;
}

