
#include <iostream>

using namespace std;

// Function to read a line from standard input and remove trailing whitespace
string rs() {
    string s;
    getline(cin, s);
    return s;
}

// Function to read an integer from standard input
int ri() {
    int n;
    cin >> n;
    return n;
}

// Function to read a line from standard input and return a list of strings
vector<string> rs_() {
    string s = rs();
    vector<string> v;
    string t = "";
    for (char c : s) {
        if (c =='') {
            v.push_back(t);
            t = "";
        } else {
            t += c;
        }
    }
    v.push_back(t);
    return v;
}

// Function to read a line from standard input and return a list of integers
vector<int> ri_() {
    string s = rs();
    vector<int> v;
    string t = "";
    for (char c : s) {
        if (c =='') {
            v.push_back(stoi(t));
            t = "";
        } else {
            t += c;
        }
    }
    v.push_back(stoi(t));
    return v;
}

int main() {
    // Read the integer N from input
    int N = ri();

    // Initialize the answer variable to accumulate the result
    long long ans = 0;

    // Loop through each integer from 1 to N (inclusive)
    for (int i = 1; i <= N; i++) {
        // Calculate the contribution of the current integer i to the answer
        ans += i * (N / i) * (N / i + 1) / 2;
    }

    // Print the final result
    cout << ans << endl;

    return 0;
}

