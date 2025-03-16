
#include <bits/stdc++.h>
using namespace std;

// Define a modulo constant for later use
const int mod = 1e9 + 7;

// Function to read a line of input and strip the newline character
string input() {
    string s;
    getline(cin, s);
    return s;
}

// Function to read an integer from input
int I() {
    int x;
    cin >> x;
    return x;
}

// Function to read a list of integers from input
vector<int> II() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    return a;
}

// Function to read a specific format of input based on the number of elements
vector<vector<int>> Line(int N, int num) {
    // If N is less than or equal to 0, return an empty list
    if (N <= 0) {
        return vector<vector<int>>(num);
    }
    // If num is 1, read N integers and return them as a list
    else if (num == 1) {
        return vector<vector<int>>(1, II());
    }
    // Otherwise, read N tuples of integers and return them as a transposed list
    else {
        vector<vector<int>> read_all(N);
        for (int i = 0; i < N; i++) {
            read_all[i] = II();
        }
        vector<vector<int>> ans(num);
        for (int i = 0; i < num; i++) {
            ans[i] = vector<int>(N);
            for (int j = 0; j < N; j++) {
                ans[i][j] = read_all[j][i];
            }
        }
        return ans;
    }
}

// Function to determine the sign of a number
int my_sign(int x) {
    return (x > 0) - (x < 0);
}

int main() {
    // Read the number of elements
    int N = I();

    // Read the list of integers
    vector<int> a = II();

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
    }
    else if (max_sign == 1) {
        // If the maximum sign is positive, print the number of operations and the operations
        cout << 2 * N - 1 << endl;
        for (int i = 0; i < N; i++) {
            cout << max_index + 1 << " " << i + 1 << endl;
        }
        for (int i = 0; i < N - 1; i++) {
            cout << i + 1 << " " << i + 2 << endl;
        }
    }
    else {
        // If the maximum sign is negative, print the number of operations and the operations
        cout << 2 * N - 1 << endl;
        for (int i = 0; i < N; i++) {
            cout << max_index + 1 << " " << i + 1 << endl;
        }
        for (int i = N - 1; i > 0; i--) {
            cout << i + 1 << " " << i << endl;
        }
    }

    return 0;
}

Translate the above C++ code to Java and end with comment "