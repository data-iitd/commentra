#include <bits/stdc++.h>
using namespace std;

// Function to read a single value as a tuple
tuple<int, int> value() {
    int a, b;
    cin >> a >> b;
    return {a, b};
}

// Function to read multiple values as a tuple
tuple<int, int> values() {
    int a, b;
    cin >> a >> b;
    return {a, b};
}

// Function to read a single value as a list
vector<int> inlst() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    return v;
}

// Function to read multiple values as a list
vector<int> inlsts() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    return v;
}

// Function to read a single value as an integer
int inp() {
    int n;
    cin >> n;
    return n;
}

// Function to read a single value as an integer from stdin
int inps() {
    int n;
    cin >> n;
    return n;
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
    cin >> s;
    return vector<string>(s.begin(), s.end());
}

// Helper function to check if a sub-array of given size exists in a list
bool help(vector<int> &l, int a, int b) {
    int n = l.size();
    for (int i = 0; i < n - a + 1; i++) {
        int sum = 0;
        for (int j = 0; j < a; j++) {
            sum += l[i + j];
        }
        if (sum == b) {
            return true;
        }
    }
    return false;
}

// Main function to solve the problem
void solve() {
    string x;
    cin >> x;
    vector<int> s;
    for (char i : x) {
        if (i == 'O') {
            s.push_back(0);
        } else {
            s.push_back(1);
        }
    }

    vector<tuple<int, int>> tot;
    for (int i = 1; i <= 12; i++) {
        if (12 % i == 0) {
            if (help(s, i, 12 / i)) {
                tot.push_back({12 / i, i});
            }
        }
    }

    cout << tot.size() << " ";
    for (auto [a, b] : tot) {
        cout << a << "x" << b << " ";
    }
    cout << endl;
}

// Main function to run the code
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}

