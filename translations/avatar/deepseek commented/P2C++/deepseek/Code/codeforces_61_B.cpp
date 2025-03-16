#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <iomanip>

using namespace std;

// Function to check if a given pair of indices (i, j) is within the bounds of a grid with dimensions n by m
bool valid(int i, int j, int n, int m) {
    if (i < n && i >= 0 && j >= 0 && j < m) return true;
    return false;
}

// Function to calculate the sum of an arithmetic series from i to n
double sumn(int i, int n) {
    return (n - i) * (i + n) / 2.0;
}

// Function to solve a quadratic equation of the form ax^2 + bx + c = 0
double sqfun(double a, double b, double c) {
    return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
}

// Function to read a single or multiple integer values from input
vector<int> value() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> result;
    int num;
    while (ss >> num) {
        result.push_back(num);
    }
    return result;
}

// Function to read a single or multiple integer values from standard input
vector<int> values() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> result;
    int num;
    while (ss >> num) {
        result.push_back(num);
    }
    return result;
}

// Function to read a list of integers from input
vector<int> inlst() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> result;
    int num;
    while (ss >> num) {
        result.push_back(num);
    }
    return result;
}

// Function to read a list of integers from standard input
vector<int> inlsts() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> result;
    int num;
    while (ss >> num) {
        result.push_back(num);
    }
    return result;
}

// Function to read a single integer from input
int inp() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    int num;
    ss >> num;
    return num;
}

// Function to read a single integer from standard input
int inps() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    int num;
    ss >> num;
    return num;
}

// Function to read a string from input
string instr() {
    string line;
    getline(cin, line);
    return line;
}

// Function to split a string into a list of words
vector<string> stlst() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<string> result;
    string word;
    while (ss >> word) {
        result.push_back(word);
    }
    return result;
}

// Function to sanitize a string by converting it to lowercase and removing certain characters
string f(const string& s) {
    string result;
    for (char c : s) {
        if (c != '-' && c != ';' && c != '_') {
            result += tolower(c);
        }
    }
    return result;
}

// Main logic of the program
void solve() {
    vector<string> l;
    for (int i = 0; i < 3; ++i) {
        string input;
        getline(cin, input);
        l.push_back(f(input));
    }
    vector<string> l_copy = l;
    sort(l_copy.begin(), l_copy.end());
    l_copy.erase(unique(l_copy.begin(), l_copy.end()), l_copy.end());
    for (int i = 0; i < inp(); ++i) {
        string test = f(instr());
        if (binary_search(l_copy.begin(), l_copy.end(), test)) {
            cout << "ACC" << endl;
        } else {
            cout << "WA" << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}
