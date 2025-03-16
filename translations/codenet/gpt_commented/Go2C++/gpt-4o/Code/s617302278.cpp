#include <iostream>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <cmath>

using namespace std;

// Function to read a line of integers from standard input
vector<int> NextIntsLine() {
    string line;
    getline(cin, line);
    vector<int> integers;
    stringstream ss(line);
    int number;
    while (ss >> number) {
        integers.push_back(number);
    }
    return integers;
}

// Function to calculate the maximum of a variable number of integers
int Max(const vector<int>& integers) {
    if (integers.empty()) {
        throw invalid_argument("Max requires at least one argument");
    }
    int m = integers[0];
    for (size_t i = 1; i < integers.size(); ++i) {
        if (m < integers[i]) {
            m = integers[i];
        }
    }
    return m;
}

// Function to calculate the minimum of a variable number of integers
int Min(const vector<int>& integers) {
    if (integers.empty()) {
        throw invalid_argument("Min requires at least one argument");
    }
    int m = integers[0];
    for (size_t i = 1; i < integers.size(); ++i) {
        if (m > integers[i]) {
            m = integers[i];
        }
    }
    return m;
}

// Function to calculate the power of an integer base raised to an integer exponent
int PowInt(int a, int e) {
    if (a < 0 || e < 0) {
        throw invalid_argument("PowInt does not accept negative integers");
    }
    return static_cast<int>(pow(static_cast<double>(a), static_cast<double>(e)));
}

// Function to calculate the absolute value of an integer
int AbsInt(int a) {
    return abs(a);
}

// Function to delete an element at a specified index from a vector of integers
vector<int> DeleteElement(const vector<int>& s, int i) {
    if (i < 0 || i >= s.size()) {
        throw out_of_range("Index out of bounds");
    }
    vector<int> n;
    n.reserve(s.size() - 1);
    for (size_t j = 0; j < s.size(); ++j) {
        if (j != i) {
            n.push_back(s[j]);
        }
    }
    return n;
}

// Function to concatenate two vectors of characters (runes)
vector<char> Concat(const vector<char>& s, const vector<char>& t) {
    vector<char> n;
    n.reserve(s.size() + t.size());
    n.insert(n.end(), s.begin(), s.end());
    n.insert(n.end(), t.begin(), t.end());
    return n;
}

// Main function where the program execution begins
int main() {
    vector<int> tmp = NextIntsLine(); // Read a line of integers
    int x = tmp[0]; // Store the first integer in variable x
    int i = 1; // Initialize counter
    int sum = 0; // Initialize sum
    while (true) {
        sum += i; // Incrementally add to sum
        if (sum >= x) { // Check if sum has reached or exceeded x
            break; // Exit the loop if condition is met
        }
        i++; // Increment counter
    }
    cout << i << endl; // Print the result
    return 0; // Return success
}

// <END-OF-CODE>
