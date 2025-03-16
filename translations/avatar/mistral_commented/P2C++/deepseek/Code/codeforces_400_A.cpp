#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to read a single value as a tuple
vector<int> value() {
    string line;
    getline(cin, line);
    vector<int> result;
    string num;
    for (char c : line) {
        if (c == ' ') {
            result.push_back(stoi(num));
            num.clear();
        } else {
            num += c;
        }
    }
    if (!num.empty()) {
        result.push_back(stoi(num));
    }
    return result;
}

// Function to read multiple values as a tuple
vector<int> values() {
    string line;
    getline(cin, line);
    vector<int> result;
    string num;
    for (char c : line) {
        if (c == ' ') {
            result.push_back(stoi(num));
            num.clear();
        } else {
            num += c;
        }
    }
    if (!num.empty()) {
        result.push_back(stoi(num));
    }
    return result;
}

// Function to read a single value as a list
vector<int> inlst() {
    string line;
    getline(cin, line);
    vector<int> result;
    string num;
    for (char c : line) {
        if (c == ' ') {
            result.push_back(stoi(num));
            num.clear();
        } else {
            num += c;
        }
    }
    if (!num.empty()) {
        result.push_back(stoi(num));
    }
    return result;
}

// Function to read multiple values as a list
vector<int> inlsts() {
    string line;
    getline(cin, line);
    vector<int> result;
    string num;
    for (char c : line) {
        if (c == ' ') {
            result.push_back(stoi(num));
            num.clear();
        } else {
            num += c;
        }
    }
    if (!num.empty()) {
        result.push_back(stoi(num));
    }
    return result;
}

// Function to read a single value as an integer
int inp() {
    int x;
    cin >> x;
    return x;
}

// Function to read a single value as an integer from stdin
int inps() {
    int x;
    cin >> x;
    return x;
}

// Function to read a single line as a string
string instr() {
    string line;
    getline(cin, line);
    return line;
}

// Function to read a list of strings
vector<string> stlst() {
    string line;
    getline(cin, line);
    vector<string> result;
    string word;
    for (char c : line) {
        if (c == ' ') {
            result.push_back(word);
            word.clear();
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        result.push_back(word);
    }
    return result;
}

// Helper function to check if a sub-array of given size exists in a list
bool help(const vector<int>& a, int b, int l) {
    vector<vector<int>> tot;
    for (int i = 0; i < b; ++i) {
        vector<int> sub(a.begin() + i * l, a.begin() + i * l + l);
        tot.push_back(sub);
    }
    for (int i = 0; i < tot.size(); ++i) {
        int sum = 0;
        for (int j = 0; j < tot[i].size(); ++j) {
            sum += tot[i][j];
        }
        if (sum == 12) {
            return true;
        }
    }
    return false;
}

// Main function to solve the problem
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
            if (help(s, 12 / i, i)) {
                tot.push_back({12 / i, i});
            }
        }
    }

    cout << tot.size() << " ";
    for (const auto& p : tot) {
        cout << p.first << "x" << p.second << " ";
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

