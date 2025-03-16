#include <bits/stdc++.h>
using namespace std;

// Function to check if given indices are valid
bool valid(int i, int j, int n, int m) {
    if (i < n && i >= 0 && j >= 0 && j < m) {
        return true;
    }
    return false;
}

// Function to calculate sum of first n natural numbers
int sumn(int i, int n) {
    return (n - i) * (i + n) / 2;
}

// Function to calculate square root of a number using quadratic formula
int sqfun(int a, int b, int c) {
    return (-b + sqrt(b * b - 4 * a * c)) / 2 * a;
}

// Function to read a single line as a tuple of integers
tuple<int, int> value() {
    string s;
    cin >> s;
    int i = 0, j = 0;
    while (s[i] != ' ') {
        i++;
    }
    while (s[j] != ' ') {
        j++;
    }
    return make_tuple(stoi(s.substr(0, i)), stoi(s.substr(i + 1, j)));
}

// Function to read a single line as a list of integers
vector<int> values() {
    string s;
    cin >> s;
    vector<int> v;
    int i = 0;
    while (s[i] != '\0') {
        while (s[i] != ' ') {
            i++;
        }
        v.push_back(stoi(s.substr(0, i)));
        i++;
    }
    return v;
}

// Function to read a single integer
int inp() {
    int x;
    cin >> x;
    return x;
}

// Function to read a single integer from the standard input as a string
string instr() {
    string s;
    cin >> s;
    return s;
}

// Function to read a list of integers
vector<int> inlst() {
    string s;
    cin >> s;
    vector<int> v;
    int i = 0;
    while (s[i] != '\0') {
        while (s[i] != ' ') {
            i++;
        }
        v.push_back(stoi(s.substr(0, i)));
        i++;
    }
    return v;
}

// Function to read a list of integers from the standard input
vector<int> inlsts() {
    string s;
    cin >> s;
    vector<int> v;
    int i = 0;
    while (s[i] != '\0') {
        while (s[i] != ' ') {
            i++;
        }
        v.push_back(stoi(s.substr(0, i)));
        i++;
    }
    return v;
}

// Function to read a single integer from the standard input
int inp() {
    int x;
    cin >> x;
    return x;
}

// Function to read a single integer from the standard input
int inps() {
    int x;
    cin >> x;
    return x;
}

// Function to read a single string from the standard input
string instr() {
    string s;
    cin >> s;
    return s;
}

// Function to convert a string to a list
vector<string> stlst() {
    string s;
    cin >> s;
    vector<string> v;
    int i = 0;
    while (s[i] != '\0') {
        while (s[i] != ' ') {
            i++;
        }
        v.push_back(s.substr(0, i));
        i++;
    }
    return v;
}

// Main function to solve the problem
void solve() {
    vector<string> l;
    for (int i = 0; i < 3; i++) {
        l.push_back(f(instr()));
    }
    vector<string> t = permutations(l, l.size());
    l.clear();
    for (int i = 0; i < t.size(); i++) {
        l.push_back("".join(t[i]));
    }
    for (int i = 0; i < inp(); i++) {
        if (f(instr()) == l[i]) {
            cout << "ACC" << endl;
        } else {
            cout << "WA" << endl;
        }
    }
}

// Starting the program
int main() {
    solve();
    return 0;
}

