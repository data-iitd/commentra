#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

bool help(int a, int b, const vector<int>& l) {
    vector<vector<int>> tot(b);
    for (int i = 0; i < b; ++i) {
        for (int j = 0; j < a; ++j) {
            tot[i].push_back(l[i * a + j]);
        }
    }
    for (int j = 0; j < a; ++j) {
        int sum = 0;
        for (int i = 0; i < b; ++i) {
            sum += tot[i][j];
        }
        if (sum == b) return true;
    }
    return false;
}

void solve() {
    vector<pair<int, int>> tot;
    string x;
    cin >> x;
    vector<int> s;
    for (char i : x) {
        if (i == 'O') s.push_back(0);
        else s.push_back(1);
    }
    for (int i = 1; i <= 12; ++i) {
        if (12 % i == 0) {
            if (help(i, 12 / i, s)) {
                tot.emplace_back(12 / i, i);
            }
        }
    }
    cout << tot.size() << " ";
    sort(tot.begin(), tot.end());
    for (const auto& [a, b] : tot) {
        cout << a << "x" << b << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}

// <END-OF-CODE>
