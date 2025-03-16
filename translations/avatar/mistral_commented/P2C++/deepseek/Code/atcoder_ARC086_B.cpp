#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

// Function to read input from standard input
string input() {
    string line;
    getline(cin, line);
    return line;
}

// Define the modulus value
const long long mod = 1000000007;

// Function to return an integer input
int I() {
    int num;
    cin >> num;
    return num;
}

// Function to return a vector of integers as input
vector<int> III() {
    vector<int> nums;
    int num;
    while (cin >> num) {
        nums.push_back(num);
    }
    return nums;
}

// Function to create a vector of vectors based on the given number of rows and columns
vector<vector<int>> Line(int N, int num) {
    vector<vector<int>> matrix(N, vector<int>(num));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < num; ++j) {
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

// Function to determine the sign of a number
int my_sign(int a) {
    if (a > 0) return 1;
    else if (a < 0) return -1;
    else return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // Initialize variables
    int N = I();
    vector<int> a = III();
    int max_val = 0;
    int max_sign = 0;
    int max_index = -1;

    // Iterate through the vector 'a' to find the maximum absolute value and its sign
    for (int i = 0; i < N; ++i) {
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
        for (int i = 1; i < N; ++i) {
            cout << i + 1 << " " << i + 2 << endl;
        }
    } else {
        // If the maximum value is negative, print the required output
        cout << 2 * N - 1 << endl;
        // Print the indices of the maximum value and the first element
        cout << max_index + 1 << " " << 1 << endl;
        // Print the indices of the other elements in reverse order
        for (int i = N - 1; i > 0; --i) {
            cout << i + 1 << " " << i << endl;
        }
    }

    return 0;
}
