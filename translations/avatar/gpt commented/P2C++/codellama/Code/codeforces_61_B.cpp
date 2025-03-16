
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
tuple<int, int> value() {
    string s;
    cin >> s;
    int i = 0, j = 0;
    for (int k = 0; k < s.length(); k++) {
        if (s[k] == ' ') {
            i = j;
            j = 0;
        } else {
            j = j * 10 + s[k] - '0';
        }
    }
    return make_tuple(i, j);
}

// Function to read a single line of input from stdin and return it as a tuple of integers
tuple<int, int> values() {
    string s;
    getline(cin, s);
    int i = 0, j = 0;
    for (int k = 0; k < s.length(); k++) {
        if (s[k] == ' ') {
            i = j;
            j = 0;
        } else {
            j = j * 10 + s[k] - '0';
        }
    }
    return make_tuple(i, j);
}

// Function to read a single line of input and return it as a list of integers
vector<int> inlst() {
    string s;
    cin >> s;
    vector<int> l;
    for (int k = 0; k < s.length(); k++) {
        if (s[k] == ' ') {
            l.push_back(stoi(s.substr(0, k)));
            s = s.substr(k + 1);
            k = -1;
        }
    }
    l.push_back(stoi(s));
    return l;
}

// Function to read a single line of input from stdin and return it as a list of integers
vector<int> inlsts() {
    string s;
    getline(cin, s);
    vector<int> l;
    for (int k = 0; k < s.length(); k++) {
        if (s[k] == ' ') {
            l.push_back(stoi(s.substr(0, k)));
            s = s.substr(k + 1);
            k = -1;
        }
    }
    l.push_back(stoi(s));
    return l;
}

// Function to read a single integer from input
int inp() {
    int i;
    cin >> i;
    return i;
}

// Function to read a single integer from stdin
int inps() {
    int i;
    getline(cin, i);
    return i;
}

// Function to read a single line of input and return it as a string
string instr() {
    string s;
    cin >> s;
    return s;
}

// Function to read a single line of input and return it as a list of strings
vector<string> stlst() {
    string s;
    cin >> s;
    vector<string> l;
    for (int k = 0; k < s.length(); k++) {
        if (s[k] == ' ') {
            l.push_back(s.substr(0, k));
            s = s.substr(k + 1);
            k = -1;
        }
    }
    l.push_back(s);
    return l;
}

// Function to process a string by removing specific characters and converting it to lowercase
string f(string s) {
    string r = "";
    for (int k = 0; k < s.length(); k++) {
        if (s[k] != '-' && s[k] != ';' && s[k] != '_') {
            r += tolower(s[k]);
        }
    }
    return r;
}

// Main function to solve the problem
void solve() {
    vector<string> l;
    // Read three lines of input, process them, and store the results in a list
    for (int i = 0; i < 3; i++) {
        l.push_back(f(instr()));
    }
    
    // Generate all permutations of the processed strings
    vector<string> t = permutations(l);
    l.clear();
    // Create a list of concatenated permutations
    for (int i = 0; i < t.size(); i++) {
        l.push_back(t[i]);
    }
    
    // Read the number of test cases and check if the processed input is in the list of permutations
    for (int i = 0; i < inp(); i++) {
        if (f(instr()) == l[i]) {
            cout << "ACC" << endl;  // Accepted
        } else {
            cout << "WA" << endl;   // Wrong Answer
        }
    }
}

// Function to generate all permutations of a list of strings
vector<string> permutations(vector<string> l) {
    vector<string> r;
    if (l.size() == 1) {
        r.push_back(l[0]);
        return r;
    }
    for (int i = 0; i < l.size(); i++) {
        vector<string> t = permutations(l);
        for (int j = 0; j < t.size(); j++) {
            r.push_back(l[i] + t[j]);
        }
    }
    return r;
}

// Entry point of the program
int main() {
    solve();
    return 0;
}

