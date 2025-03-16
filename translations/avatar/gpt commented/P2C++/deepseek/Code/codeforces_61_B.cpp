#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <iterator>
#include <unordered_set>

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

// Function to read a single line of input from stdin and return it as a tuple of integers
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

// Function to read a single line of input and return it as a list of integers
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

// Function to read a single line of input from stdin and return it as a list of integers
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
    int num;
    cin >> num;
    return num;
}

// Function to read a single integer from stdin
int inps() {
    int num;
    cin >> num;
    return num;
}

// Function to read a single line of input and return it as a string
string instr() {
    string line;
    getline(cin, line);
    return line;
}

// Function to read a single line of input and return it as a list of strings
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

// Function to process a string by removing specific characters and converting it to lowercase
string f(const string& s) {
    string result;
    for (char c : s) {
        if (c != '-' && c != ';' && c != '_') {
            result += tolower(c);
        }
    }
    return result;
}

// Main function to solve the problem
void solve() {
    vector<string> l;
    // Read three lines of input, process them, and store the results in a list
    for (int i = 0; i < 3; ++i) {
        l.push_back(f(instr()));
    }

    // Generate all permutations of the processed strings
    vector<string> t;
    sort(l.begin(), l.end());
    do {
        string concatenated;
        for (const auto& str : l) {
            concatenated += str;
        }
        t.push_back(concatenated);
    } while (next_permutation(l.begin(), l.end()));

    // Read the number of test cases and check if the processed input is in the list of permutations
    int num_test_cases = inp();
    for (int i = 0; i < num_test_cases; ++i) {
        string test_case = f(instr());
        if (find(t.begin(), t.end(), test_case) != t.end()) {
            cout << "ACC" << endl; // Accepted
        } else {
            cout << "WA" << endl;  // Wrong Answer
        }
    }
}

// Entry point of the program
int main() {
    solve();
    return 0;
}
