#include <bits/stdc++.h>
using namespace std;

// Function to read a single value as a tuple
tuple<int, int> value() {
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            a = b;
            b = 0;
        } else {
            b = b * 10 + s[i] - '0';
        }
    }
    return make_tuple(a, b);
}

// Function to read multiple values as a tuple
tuple<int, int, int> values() {
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            a = b;
            b = c;
            c = 0;
        } else {
            c = c * 10 + s[i] - '0';
        }
    }
    return make_tuple(a, b, c);
}

// Function to read a single value as a list
vector<int> inlst() {
    string s;
    cin >> s;
    vector<int> v;
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

// Function to read multiple values as a list
vector<int> inlsts() {
    string s;
    cin >> s;
    vector<int> v;
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

// Function to read a single value as an integer
int inp() {
    string s;
    cin >> s;
    return stoi(s);
}

// Function to read a single value as an integer from stdin
int inps() {
    string s;
    getline(cin, s);
    return stoi(s);
}

// Function to read a single line as a string
string instr() {
    string s;
    getline(cin, s);
    return s;
}

// Function to read a list of strings
vector<string> stlst() {
    string s;
    getline(cin, s);
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

// Helper function to check if a sub-array of given size exists in a list
bool help(int a, int b, vector<int> l) {
    /**
     * This function checks if there exists a sub-array of size 'a' in the list 'l' whose sum is equal to 'b'.
     */
    vector<vector<int>> tot;
    for (int i = 0; i < b; i++) {
        vector<int> t;
        for (int j = 0; j < a; j++) {
            t.push_back(l[i * a + j]);
        }
        tot.push_back(t);
    }
    for (int i = 0; i < tot.size(); i++) {
        if (accumulate(tot[i].begin(), tot[i].end(), 0) == b) {
            return true;
        }
    }
    return false;
}

// Main function to solve the problem
void solve() {
    /**
     * This function reads a string 'x' and checks if there exists any sub-array of size 1, 2, 3, ..., 12 whose sum is equal to 12.
     * If such a sub-array is found, it is added to the list 'tot'. Finally, the number of such sub-arrays and their sizes are printed.
     */
    string x;
    getline(cin, x);
    vector<int> s;
    for (int i = 0; i < x.size(); i++) {
        if (x[i] == 'O') {
            s.push_back(0);
        } else {
            s.push_back(1);
        }
    }
    vector<pair<int, int>> tot;
    for (int i = 1; i <= 12; i++) {
        if (12 % i == 0) {
            if (help(i, 12 / i, s)) {
                tot.push_back(make_pair(12 / i, i));
            }
        }
    }
    cout << tot.size() << " ";
    for (int i = 0; i < tot.size(); i++) {
        cout << tot[i].first << "x" << tot[i].second << " ";
    }
    cout << endl;
}

// Main function to run the code
int main() {
    int t = inp();
    while (t--) {
        solve();
    }
    return 0;
}

