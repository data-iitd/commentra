
#include <bits/stdc++.h>
using namespace std;

// Function to read a single value as a tuple
tuple<int, int, int> value() {
    int a, b, c;
    cin >> a >> b >> c;
    return make_tuple(a, b, c);
}

// Function to read multiple values as a tuple
tuple<int, int, int, int, int, int> values() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    return make_tuple(a, b, c, d, e, f);
}

// Function to read a single value as a list
vector<int> inlst() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    return a;
}

// Function to read multiple values as a list
vector<int> inlsts() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    return a;
}

// Function to read a single value as an integer
int inp() {
    int a;
    cin >> a;
    return a;
}

// Function to read a single value as an integer from stdin
int inps() {
    int a;
    cin >> a;
    return a;
}

// Function to read a single line as a string
string instr() {
    string a;
    cin >> a;
    return a;
}

// Function to read a list of strings
vector<string> stlst() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    return a;
}

// Helper function to check if a sub-array of given size exists in a list
bool help(vector<int> &a, int b, int l) {
    vector<vector<int>> tot;
    for (int i = 0; i < b; i++) {
        tot.push_back(vector<int>(a.begin() + i * l, a.begin() + i * l + l));
    }
    for (int i = 0; i < l; i++) {
        int sum = 0;
        for (int j = 0; j < b; j++) {
            sum += tot[j][i];
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
    for (int i = 0; i < x.length(); i++) {
        if (x[i] == 'O') {
            s.push_back(0);
        } else {
            s.push_back(1);
        }
    }

    vector<pair<int, int>> tot;
    for (int i = 1; i < 13; i++) {
        if (12 % i == 0) {
            if (help(s, 12 / i, i)) {
                tot.push_back(make_pair(12 / i, i));
            }
        }
    }

    cout << tot.size() << " ";
    for (auto &p : tot) {
        cout << p.first << "x" << p.second << " ";
    }
    cout << endl;
}

// Main function to run the code
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

