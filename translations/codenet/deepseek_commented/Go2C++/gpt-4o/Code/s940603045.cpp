#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>

using namespace std;

// Function to calculate the sum of digits in a string
int digitSum(const string& s) {
    int sum = 0;
    for (char c : s) {
        sum += c - '0';
    }
    return sum;
}

// Main function
int main() {
    string N;
    cin >> N; // Read input string

    int sum = digitSum(N); // Calculate sum of digits
    int m = stoi(N); // Convert input string to integer

    // Check if the number is divisible by the sum of its digits
    if (m % sum == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

// Utility functions (not used in this specific example)
bool in(int c, int a, int z) {
    return c >= a && c < z;
}

bool out(int c, int a, int z) {
    return !in(c, a, z);
}

int btoi(bool b) {
    return b ? 1 : 0;
}

bool itob(int a) {
    return a != 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int sum(const vector<int>& a) {
    return accumulate(a.begin(), a.end(), 0);
}

int pro(const vector<int>& a) {
    return accumulate(a.begin(), a.end(), 1, std::multiplies<int>());
}

vector<int> fill(int n, int size) {
    return vector<int>(size, n);
}

pair<int, int> minmax(int a, int b) {
    return make_pair(min(a, b), max(a, b));
}

int abs(int a) {
    return (a < 0) ? -a : a;
}

int ceil(int a, int b) {
    return (a % b != 0) ? (a / b) + 1 : (a / b);
}

void printStrings(const vector<string>& out) {
    for (size_t i = 0; i < out.size(); ++i) {
        cout << out[i];
        if (i != out.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

void printInts(const vector<int>& out) {
    for (size_t i = 0; i < out.size(); ++i) {
        cout << out[i];
        if (i != out.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

// <END-OF-CODE>
