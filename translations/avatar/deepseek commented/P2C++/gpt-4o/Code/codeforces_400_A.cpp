#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

// Function to read a single value from input
pair<int, int> value() {
    int a, b;
    cin >> a >> b;
    return make_pair(a, b);
}

// Function to read multiple values from input
vector<int> values() {
    int n;
    cin >> n;
    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
        cin >> result[i];
    }
    return result;
}

// Function to read a list of integers from input
vector<int> inlst() {
    vector<int> result;
    int x;
    while (cin >> x) {
        result.push_back(x);
    }
    return result;
}

// Function to read a single integer from input
int inp() {
    int x;
    cin >> x;
    return x;
}

// Function to read a single string from input
string instr() {
    string x;
    cin >> x;
    return x;
}

// Helper function to check if a grid of given dimensions can be formed
bool help(int a, int b, const vector<int>& l) {
    vector<vector<int>> tot(b, vector<int>(a));
    for (int i = 0; i < b; ++i) {
        for (int j = 0; j < a; ++j) {
            tot[i][j] = l[i * a + j];
        }
    }
    for (int j = 0; j < a; ++j) {
        int sum = 0;
        for (int i = 0; i < b; ++i) {
            sum += tot[i][j];
        }
        if (sum == b) {
            return true;
        }
    }
    return false;
}

// Main solving function
void solve() {
    string x = instr();
    vector<int> s;
    for (char i : x) {
        if (i == 'O') {
            s.push_back(0);
        } else {
            s.push_back(1);
        }
    }
    vector<pair<int, int>> tot;
    for (int i = 1; i <= 12; ++i) {
        if (12 % i == 0) {
            if (help(i, 12 / i, s)) {
                tot.emplace_back(12 / i, i);
            }
        }
    }
    cout << tot.size() << " ";
    sort(tot.begin(), tot.end());
    for (const auto& p : tot) {
        cout << p.first << "x" << p.second << " ";
    }
    cout << endl;
}

// Main execution block
int main() {
    int t = inp();
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}

// <END-OF-CODE>
