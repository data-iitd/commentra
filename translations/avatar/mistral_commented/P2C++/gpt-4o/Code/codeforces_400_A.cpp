#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <tuple>

using namespace std;

// Function to read a single value as a tuple
tuple<int, int> value() {
    int a, b;
    cin >> a >> b;
    return make_tuple(a, b);
}

// Function to read multiple values as a tuple
tuple<int, int> values() {
    int a, b;
    cin >> a >> b;
    return make_tuple(a, b);
}

// Function to read a single value as a list
vector<int> inlst() {
    vector<int> lst;
    int x;
    while (cin >> x) {
        lst.push_back(x);
    }
    return lst;
}

// Function to read multiple values as a list
vector<int> inlsts() {
    vector<int> lst;
    int x;
    while (cin >> x) {
        lst.push_back(x);
    }
    return lst;
}

// Function to read a single value as an integer
int inp() {
    int x;
    cin >> x;
    return x;
}

// Function to read a single line as a string
string instr() {
    string x;
    cin >> x;
    return x;
}

// Helper function to check if a sub-array of given size exists in a list
bool help(int a, int b, const vector<int>& l) {
    vector<vector<int>> tot;
    for (int i = 0; i < b; ++i) {
        vector<int> sub(l.begin() + i * a, l.begin() + i * a + a);
        tot.push_back(sub);
    }
    for (const auto& i : tot) {
        if (accumulate(i.begin(), i.end(), 0) == b) {
            return true;
        }
    }
    return false;
}

// Main function to solve the problem
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
    for (const auto& [a, b] : tot) {
        cout << a << "x" << b << " ";
    }
    cout << endl;
}

// Main function to run the code
int main() {
    int t = inp();
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}

// <END-OF-CODE>
