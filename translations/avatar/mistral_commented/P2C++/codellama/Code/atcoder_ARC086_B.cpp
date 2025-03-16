
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

// Function to read input from standard input
void input() {
    cin.getline(input, 1000000);
}

// Define the modulus value
const int mod = 1000000007;

// Function to return an integer input
int I() {
    int x;
    cin >> x;
    return x;
}

// Function to return a list of integers as input
vector<int> III() {
    vector<int> a;
    int x;
    while (cin >> x) {
        a.push_back(x);
    }
    return a;
}

// Function to create a list of lists based on the given number of rows and columns
vector<vector<int>> Line(int N, int num) {
    vector<vector<int>> a;
    if (N <= 0) {
        a.push_back(vector<int>());
        return a;
    }
    if (num == 1) {
        for (int i = 0; i < N; i++) {
            vector<int> b;
            for (int j = 0; j < N; j++) {
                int x;
                cin >> x;
                b.push_back(x);
            }
            a.push_back(b);
        }
        return a;
    }
    vector<vector<int>> b;
    for (int i = 0; i < N; i++) {
        vector<int> c;
        for (int j = 0; j < N; j++) {
            int x;
            cin >> x;
            c.push_back(x);
        }
        b.push_back(c);
    }
    for (int i = 0; i < N; i++) {
        a.push_back(vector<int>());
        for (int j = 0; j < N; j++) {
            a[i].push_back(b[i][j]);
        }
    }
    return a;
}

// Initialize variables
int N = I();
vector<int> a = III();
int max_val = 0;
int max_sign = 0;
int max_index = -1;

// Iterate through the list 'a' to find the maximum absolute value and its sign
for (int i = 0; i < N; i++) {
    // Update the maximum value and its sign if the current value is greater
    if (abs(a[i]) > max_val) {
        max_val = abs(a[i]);
        max_sign = my_sign(a[i]);
        max_index = i;
    }
}

// Determine the output based on the sign of the maximum value
if (max_sign == 0) {
    // If the maximum value is zero, print zero
    cout << 0 << endl;
} else if (max_sign == 1) {
    // If the maximum value is positive, print the required output
    cout << 2 * N - 1 << endl;
    // Print the indices of the maximum value and the first element
    cout << max_index + 1 << " " << 1 << endl;
    // Print the indices of the other elements in pairs
    for (int i = 1; i < N; i++) {
        cout << i + 1 << " " << i + 2 << endl;
    }
} else {
    // If the maximum value is negative, print the required output
    cout << 2 * N - 1 << endl;
    // Print the indices of the maximum value and the first element
    cout << max_index + 1 << " " << 1 << endl;
    // Print the indices of the other elements in reverse order
    for (int i = N - 1; i > 0; i--) {
        cout << i + 1 << " " << i << endl;
    }
}

