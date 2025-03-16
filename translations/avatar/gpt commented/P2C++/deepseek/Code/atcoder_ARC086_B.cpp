#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>

using namespace std;

// Function to read a line of input and strip the newline character
string input() {
    string line;
    getline(cin, line);
    return line;
}

// Define a modulo constant for later use
const long long mod = 1000000007;

// Function to read an integer from input
int I() {
    int num;
    cin >> num;
    return num;
}

// Function to read a list of integers from input
vector<int> II() {
    vector<int> nums;
    int num;
    while (cin >> num) {
        nums.push_back(num);
    }
    return nums;
}

// Function to read a specific format of input based on the number of elements
vector<vector<int>> Line(int N, int num) {
    vector<vector<int>> result;
    if (N <= 0) {
        return {{}};
    }
    if (num == 1) {
        for (int i = 0; i < N; ++i) {
            result.push_back({I()});
        }
    } else {
        vector<int> temp;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < num; ++j) {
                int val;
                cin >> val;
                temp.push_back(val);
            }
            result.push_back(temp);
            temp.clear();
        }
    }
    return result;
}

// Function to determine the sign of a number
int my_sign(int x) {
    return (x > 0) - (x < 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // Read the number of elements
    int N = I();

    // Read the list of integers
    vector<int> a = II();

    // Initialize variables to track the maximum absolute value, its sign, and index
    int max_val = 0;
    int max_sign = 0;
    int max_index = -1;

    // Loop through the list to find the maximum absolute value and its properties
    for (int i = 0; i < N; ++i) {
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
        for (int i = 0; i < N; ++i) {
            cout << max_index + 1 << " " << i + 1 << endl;
        }
        for (int i = 0; i < N - 1; ++i) {
            cout << i + 1 << " " << i + 2 << endl;
        }
    } else {
        // If the maximum sign is negative, print the number of operations and the operations
        cout << 2 * N - 1 << endl;
        for (int i = 0; i < N; ++i) {
            cout << max_index + 1 << " " << i + 1 << endl;
        }
        for (int i = N - 1; i > 0; --i) {
            cout << i + 1 << " " << i << endl;
        }
    }

    return 0;
}
