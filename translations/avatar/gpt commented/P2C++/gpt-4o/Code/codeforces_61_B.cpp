#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <sstream>
#include <iterator>

using namespace std;

// Function to check if the given indices (i, j) are within the bounds of a grid of size n x m
bool valid(int i, int j, int n, int m) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

// Function to calculate the sum of integers from i to n using the formula for the sum of an arithmetic series
double sumn(int i, int n) {
    return (n - i) * (i + n) / 2.0;
}

// Function to solve a quadratic equation ax^2 + bx + c = 0 and return one of its roots
double sqfun(double a, double b, double c) {
    return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
}

// Function to read a single line of input and return it as a vector of integers
vector<int> inlst() {
    string line;
    getline(cin, line);
    istringstream iss(line);
    return vector<int>(istream_iterator<int>(iss), istream_iterator<int>());
}

// Function to read a single integer from input
int inp() {
    int x;
    cin >> x;
    cin.ignore(); // To ignore the newline character after the integer input
    return x;
}

// Function to process a string by removing specific characters and converting it to lowercase
string f(const string& s) {
    string r;
    for (char i : s) {
        if (i != '-' && i != ';' && i != '_') {
            r += tolower(i);
        }
    }
    return r;
}

// Main function to solve the problem
void solve() {
    vector<string> l;
    // Read three lines of input, process them, and store the results in a vector
    for (int i = 0; i < 3; i++) {
        string input;
        getline(cin, input);
        l.push_back(f(input));
    }

    // Generate all permutations of the processed strings
    set<string> permutations;
    sort(l.begin(), l.end());
    do {
        string concatenated;
        for (const string& str : l) {
            concatenated += str;
        }
        permutations.insert(concatenated);
    } while (next_permutation(l.begin(), l.end()));

    // Read the number of test cases and check if the processed input is in the set of permutations
    for (int i = 0; i < inp(); i++) {
        string test_input;
        getline(cin, test_input);
        if (permutations.count(f(test_input))) {
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

// <END-OF-CODE>
