
#include <bits/stdc++.h>

using namespace std;

// Function to check if the given string is a valid binary string
bool isValid(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            st.push(s[i]);
        } else {
            if (st.empty()) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

// Function to count the number of pairs in the given string
int countPairs(string s) {
    int c = 0;
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            st.push(s[i]);
        } else {
            if (st.empty()) {
                return c;
            }
            st.pop();
        }
    }
    return c;
}

// Main function
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (isValid(s)) {
            cout << countPairs(s) * 2 << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}

