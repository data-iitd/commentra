
#include <bits/stdc++.h>
using namespace std;

// Function to check if the given indices (i, j) are within the bounds of a grid of size n x m
bool valid(int i, int j, int n, int m) {
    if (i < n && i >= 0 && j >= 0 && j < m) {
        return true;
    }
    return false;
}

// Function to calculate the sum of integers from i to n using the formula for the sum of an arithmetic series
int sumn(int i, int n) {
    return (n - i) * (i + n) / 2;
}

// Function to solve a quadratic equation ax^2 + bx + c = 0 and return one of its roots
double sqfun(double a, double b, double c) {
    return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
}

// Function to read a single line of input and return it as a tuple of integers
tuple<int, int, int> value() {
    int a, b, c;
    cin >> a >> b >> c;
    return make_tuple(a, b, c);
}

// Function to read a single line of input from stdin and return it as a tuple of integers
tuple<int, int, int> values() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    return make_tuple(a, b, c);
}

// Function to read a single line of input and return it as a list of integers
vector<int> inlst() {
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

// Function to read a single line of input from stdin and return it as a list of integers
vector<int> inlsts() {
    vector<int> v;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        v.push_back(x);
    }
    return v;
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
    scanf("%d", &x);
    return x;
}

// Function to read a single line of input and return it as a string
string instr() {
    string s;
    cin >> s;
    return s;
}

// Function to read a single line of input and return it as a list of strings
vector<string> stlst() {
    vector<string> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    return v;
}

// Main function to solve the problem
void solve() {
    vector<string> l;
    // Read three lines of input, process them, and store the results in a list
    for (int i = 0; i < 3; i++) {
        string s;
        cin >> s;
        string t = "";
        for (char c : s) {
            if (c!= '-' && c!= ';' && c!= '_') {
                t += tolower(c);
            }
        }
        l.push_back(t);
    }
    
    // Generate all permutations of the processed strings
    vector<vector<string>> t;
    for (int i = 0; i < 3; i++) {
        sort(l.begin(), l.end());
        do {
            t.push_back(l);
        } while (next_permutation(l.begin(), l.end()));
        l.pop_back();
    }
    
    // Create a list of concatenated permutations
    vector<string> l2;
    for (vector<string> v : t) {
        string s = "";
        for (string s2 : v) {
            s += s2;
        }
        l2.push_back(s);
    }
    
    // Read the number of test cases and check if the processed input is in the list of permutations
    for (int i = 0; i < inp(); i++) {
        string s;
        cin >> s;
        string t = "";
        for (char c : s) {
            if (c!= '-' && c!= ';' && c!= '_') {
                t += tolower(c);
            }
        }
        if (find(l2.begin(), l2.end(), t)!= l2.end()) {
            cout << "ACC" << endl;  // Accepted
        } else {
            cout << "WA" << endl;   // Wrong Answer
        }
    }
}

// Entry point of the program
int main() {
    solve();
    return 0;
}

