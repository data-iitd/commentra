

#include <iostream>

using namespace std;

// Function to read a single line from standard input and strip any trailing whitespace characters.
string rs() {
    string s;
    getline(cin, s);
    return s;
}

// Function to read an integer from standard input.
int ri() {
    int n;
    cin >> n;
    return n;
}

// Function to read a list of strings from standard input.
vector<string> rs_() {
    string s = rs();
    vector<string> v;
    string word = "";
    for (char c : s) {
        if (c =='') {
            v.push_back(word);
            word = "";
        } else {
            word += c;
        }
    }
    v.push_back(word);
    return v;
}

// Function to read a list of integers from standard input.
vector<int> ri_() {
    string s = rs();
    vector<int> v;
    string word = "";
    for (char c : s) {
        if (c =='') {
            v.push_back(stoi(word));
            word = "";
        } else {
            word += c;
        }
    }
    v.push_back(stoi(word));
    return v;
}

int main() {
    // Read the integer value of N from standard input.
    int N = ri();

    // Initialize the variable ans to 0.
    int ans = 0;

    // Start a loop that iterates from 1 to N + 1.
    for (int i = 1; i <= N; i++) {
        // Calculate the sum of multiples of i up to N using the formula for the sum of an arithmetic series.
        ans += i * (N / i) * (N / i + 1) / 2;
    }

    // Print the final value of ans, which represents the sum of multiples of numbers from 1 to N.
    cout << ans << endl;

    return 0;
}

