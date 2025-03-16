#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Define a debug print function that only prints if running in a terminal environment
void dbg(const string& s) {
    if (getenv("TERM_PROGRAM")) {
        cout << s << endl;
    }
}

// Define a function to read a list of integers from input
vector<int> LMIIS() {
    vector<int> v;
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            v.push_back(stoi(s.substr(0, i)));
            s = s.substr(i + 1);
            i = -1;
        }
    }
    v.push_back(stoi(s));
    return v;
}

// Define a function to read a single integer from input
int II() {
    string s;
    getline(cin, s);
    return stoi(s);
}

// Constants for calculations
const int P = 1000000007;  // A large prime number for modulo operations
const int INF = 1000000010;  // A large number representing infinity

// Read two values from input: one as an integer and the other as a float in string format
string sa, sb;
cin >> sa >> sb;

// Convert the first value to an integer
int a = stoi(sa);

// Convert the second value to an integer representing cents (by multiplying by 100)
int b = stoi(sb) * 100 + 0.1;

// Calculate and print the product of a and b, divided by 100 to get the final result
cout << a * b / 100 << endl;

// End of code
