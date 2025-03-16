
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
tuple<int, int, int> value() {
    int a, b, c;
    cin >> a >> b >> c;
    return make_tuple(a, b, c);
}

// Function to read a single line as a list of integers
vector<int> values() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    return v;
}

// Function to read a single integer
int inp() {
    int n;
    cin >> n;
    return n;
}

// Function to read a single integer from the standard input as a string
string instr() {
    string s;
    cin >> s;
    return s;
}

// Function to read a list of integers
vector<int> inlst() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    return v;
}

// Function to read a list of integers from the standard input
vector<int> inlsts() {
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    return v;
}

// Function to read a single integer from the standard input
int inp() {
    int n;
    cin >> n;
    return n;
}

// Function to read a single integer from the standard input
int inps() {
    int n;
    cin >> n;
    return n;
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
    stringstream ss(s);
    string word;
    while (ss >> word) {
        v.push_back(word);
    }
    return v;
}

// Main function to solve the problem
void solve() {
    vector<string> l;
    for (int i = 0; i < 3; i++) {
        l.push_back(f(instr()));
    }
    vector<string> t;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (i!= j && j!= k && i!= k) {
                    string s = l[i] + l[j] + l[k];
                    t.push_back(s);
                }
            }
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s = f(instr());
        if (find(t.begin(), t.end(), s)!= t.end()) {
            cout << "ACC" << endl;
        } else {
            cout << "WA" << endl;
        }
    }
}

// Starting the program
int main() {
    solve();
}

Translate the above Python code to Java and end with comment "