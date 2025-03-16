#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

using namespace std;

// Function to read a single value from input
tuple<int, int> value() {
    int a, b;
    cin >> a >> b;
    return make_tuple(a, b);
}

// Function to read multiple values from input
vector<int> values() {
    vector<int> result;
    int temp;
    while (cin >> temp) {
        result.push_back(temp);
    }
    return result;
}

// Function to read a list of integers from input
vector<int> inlst() {
    string line;
    getline(cin, line);
    vector<int> result;
    string temp;
    for (char c : line) {
        if (c == ' ') {
            result.push_back(stoi(temp));
            temp.clear();
        } else {
            temp += c;
        }
    }
    if (!temp.empty()) {
        result.push_back(stoi(temp));
    }
    return result;
}

// Function to read a single integer from input
int inp() {
    int x;
    cin >> x;
    return x;
}

// Function to read a single integer from stdin
int inps() {
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

// Function to read a list of strings from input
vector<string> stlst() {
    string line;
    getline(cin, line);
    vector<string> result;
    string temp;
    for (char c : line) {
        if (c == ' ') {
            result.push_back(temp);
            temp.clear();
        } else {
            temp += c;
        }
    }
    if (!temp.empty()) {
        result.push_back(temp);
    }
    return result;
}

// Helper function to check if a grid of given dimensions can be formed
bool help(const vector<int>& a, int b, int l) {
    vector<vector<int>> tot(b, vector<int>(l / b));
    for (int i = 0; i < b; ++i) {
        for (int j = 0; j < l / b; ++j) {
            tot[i][j] = a[i * (l / b) + j];
        }
    }
    for (int j = 0; j < l / b; ++j) {
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
    for (char c : x) {
        if (c == 'O') {
            s.push_back(0);
        } else {
            s.push_back(1);
        }
    }
    vector<pair<int, int>> tot;
    for (int i = 1; i <= 12; ++i) {
        if (12 % i == 0) {
            if (help(s, 12 / i, s.size())) {
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
