#include <bits/stdc++.h>
using namespace std;

// Function to read a line from standard input and remove trailing whitespace
string S() {
    string s;
    getline(cin, s);
    return s;
}

// Function to read an integer from standard input
int I() {
    return atoi(S().c_str());
}

// Function to read a list of integers from standard input
vector<int> LI() {
    vector<int> v;
    for (int i = 0; i < I(); i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    return v;
}

// Function to read a list of strings from standard input
vector<string> LS() {
    vector<string> v;
    for (int i = 0; i < I(); i++) {
        string s; cin >> s;
        v.push_back(s);
    }
    return v;
}

int main() {
    int a, b; cin >> a >> b;
    if (a > 0) {
        cout << "Positive" << endl;
    } else if (a <= 0 && b >= 0) {
        cout << "Zero" << endl;
    } else {
        if ((a + b) % 2 == 0) {
            cout << "Negative" << endl;
        } else {
            cout << "Positive" << endl;
        }
    }
    return 0;
}

