
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

// Function to read a line of input and strip the newline character
string input() {
    string s;
    getline(cin, s);
    return s;
}

// Function to read an integer from input
int I() {
    return stoi(input());
}

// Function to read a list of integers from input
vector<int> II() {
    string s = input();
    vector<int> v;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            v.push_back(stoi(s.substr(0, i)));
            s = s.substr(i + 1);
            i = -1;
        }
    }
    v.push_back(stoi(s));
    return v;
}

// Function to read a list of integers and return it as a list
vector<int> III() {
    string s = input();
    vector<int> v;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            v.push_back(stoi(s.substr(0, i)));
            s = s.substr(i + 1);
            i = -1;
        }
    }
    v.push_back(stoi(s));
    return v;
}

// Function to read a specific format of input based on the number of elements
vector<vector<int>> Line(int N, int num) {
    // If N is less than or equal to 0, return an empty list
    if (N <= 0) {
        return vector<vector<int>>(num, vector<int>());
    }
    // If num is 1, read N integers and return them as a list
    if (num == 1) {
        vector<int> v;
        for (int i = 0; i < N; i++) {
            v.push_back(I());
        }
        return vector<vector<int>>(1, v);
    }
    // Otherwise, read N tuples of integers and return them as a transposed list
    vector<vector<int>> v;
    for (int i = 0; i < N; i++) {
        v.push_back(II());
    }
    return v;
}

// Function to determine the sign of a number
int my_sign(int x) {
    return (x > 0) - (x < 0);
}

int main() {
    // Read the number of elements
    int N = I();

    // Read the list of integers
    vector<int> a = III();

    // Initialize variables to track the maximum absolute value, its sign, and index
    int max_val = 0;
    int max_sign = 0;
    int max_index = -1;

    // Loop through the list to find the maximum absolute value and its properties
    for (int i = 0; i < N; i++) {
        if (abs(a[i]) > max_val) {
            max_val = abs(a[i]);
            max_sign = my_sign(a[i]);
            max_index = i;
        }
    }

    // Check the sign of the maximum value and print results accordingly
    if (max_sign == 0) {
        // If the maximum sign is zero, print 0
        cout << 0 << endl;
    } else if (max_sign == 1) {
        // If the maximum sign is positive, print the number of operations and the operations
        cout << 2 * N - 1 << endl;
        for (int i = 0; i < N; i++) {
            cout << max_index + 1 << " " << i + 1 << endl;
        }
        for (int i = 0; i < N - 1; i++) {
            cout << i + 1 << " " << i + 2 << endl;
        }
    } else {
        // If the maximum sign is negative, print the number of operations and the operations
        cout << 2 * N - 1 << endl;
        for (int i = 0; i < N; i++) {
            cout << max_index + 1 << " " << i + 1 << endl;
        }
        for (int i = 1; i < N; i++) {
            cout << i + 1 << " " << i << endl;
        }
    }

    return 0;
}

