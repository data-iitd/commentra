#include <bits/stdc++.h>

using namespace std;

// Function to read input from standard input
auto input = [](int n) {
    int x;
    cin >> x;
    return x;
};

// Function to count occurrences of numbers
auto count(vector<int> &v) {
    unordered_map<int, int> m;
    for (int i : v) {
        m[i]++;
    }
    return m;
};

// Function to count the number of pairs
auto pairs(unordered_map<int, int> &m) {
    int c = 0;
    for (auto it = m.begin(); it!= m.end(); it++) {
        int i = it->first;
        int j = -i;
        if (j == 0) {
            c += (it->second * (it->second - 1)) / 2;
        } else if (m.find(j)!= m.end()) {
            c += it->second * m[j];
        }
    }
    return c;
};

// Main function
int main() {
    int n = input(1);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = input(1);
    }
    unordered_map<int, int> m = count(v);
    cout << pairs(m) / 2 << endl;
    return 0;
}

