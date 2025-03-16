#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <sstream>

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
double sqfun(int a, int b, int c) {
    return (-b + sqrt(b * b - 4 * a * c)) / 2 * a;
}

// Function to read a single line as a tuple of integers
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

// Function to read a single line as a list of integers
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

// Function to read a single integer
int inp() {
    int num;
    cin >> num;
    return num;
}

// Function to read a single integer from the standard input as a string
string instr() {
    string line;
    getline(cin, line);
    return line;
}

// Function to read a list of integers
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

// Function to read a list of integers from the standard input
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

// Function to read a single integer from the standard input
int inp() {
    int num;
    cin >> num;
    return num;
}

// Function to read a single integer from the standard input
int inps() {
    int num;
    cin >> num;
    return num;
}

// Function to read a single string from the standard input
string instr() {
    string line;
    getline(cin, line);
    return line;
}

// Function to convert a string to a list
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

// Main function to solve the problem
void solve() {
    vector<string> l;
    for (int i = 0; i < 3; ++i) {
        string input;
        getline(cin, input);
        l.push_back(input);
    }
    vector<string> t;
    sort(l.begin(), l.end());
    do {
        string concatenated;
        for (const auto& str : l) {
            concatenated += str;
        }
        t.push_back(concatenated);
    } while (next_permutation(l.begin(), l.end()));
    int num_queries = inp();
    for (int i = 0; i < num_queries; ++i) {
        string query = instr();
        if (find(t.begin(), t.end(), query) != t.end()) {
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
