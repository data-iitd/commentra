#include <bits/stdc++.h>
using namespace std;

// Function to read a single value from input
void value() {
    int a, b;
    cin >> a >> b;
    return make_pair(a, b);
}

// Function to read multiple values from input
void values() {
    int a, b;
    cin >> a >> b;
    return make_pair(a, b);
}

// Function to read a list of integers from input
void inlst() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    return a;
}

// Function to read a list of integers from stdin
void inlsts() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    return a;
}

// Function to read a single integer from input
void inp() {
    int a;
    cin >> a;
    return a;
}

// Function to read a single integer from stdin
void inps() {
    int a;
    cin >> a;
    return a;
}

// Function to read a single string from input
void instr() {
    string a;
    cin >> a;
    return a;
}

// Function to read a list of strings from input
void stlst() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    return a;
}

// Helper function to check if a grid of given dimensions can be formed
bool help(int a, int b, vector<int> l) {
    vector<vector<int>> tot;
    for (int i = 0; i < b; i++) {
        vector<int> temp(a);
        for (int j = 0; j < a; j++) {
            temp[j] = l[i * a + j];
        }
        tot.push_back(temp);
    }
    for (int i = 0; i < a; i++) {
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

// Main solving function
void solve() {
    vector<pair<int, int>> tot;
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
    for (int i = 1; i <= 12; i++) {
        if (12 % i == 0) {
            if (help(i, 12 / i, s)) {
                tot.push_back(make_pair(12 / i, i));
            }
        }
    }
    cout << tot.size() << " ";
    sort(tot.begin(), tot.end());
    for (int i = 0; i < tot.size(); i++) {
        cout << tot[i].first << "x" << tot[i].second << " ";
    }
    cout << endl;
}

// Main execution block
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}

