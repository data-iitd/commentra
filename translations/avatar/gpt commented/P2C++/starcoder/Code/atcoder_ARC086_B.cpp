#include <bits/stdc++.h>
using namespace std;

// Set the recursion limit to a higher value to handle deep recursions
const int MAX_N = 100000;
const int MAX_K = 100000;
const int MOD = 1000000007;

// Function to read a line of input and strip the newline character
string input() {
    string s;
    getline(cin, s);
    return s;
}

// Function to read an integer from input
int I() {
    return atoi(input().c_str());
}

// Function to read a list of integers from input
vector<int> II() {
    vector<int> v;
    string s = input();
    stringstream ss(s);
    int x;
    while (ss >> x) {
        v.push_back(x);
        if (ss.peek() == ',')
            ss.ignore();
    }
    return v;
}

// Function to read a list of integers and return it as a list
vector<int> III() {
    int N = I();
    return vector<int>(II().begin(), II().begin() + N);
}

// Function to read a specific format of input based on the number of elements
vector<vector<int>> Line(int N, int num) {
    // If N is less than or equal to 0, return an empty list
    if (N <= 0) {
        return vector<vector<int>>(num);
    }
    // If num is 1, read N integers and return them as a list
    else if (num == 1) {
        return vector<vector<int>>(N, II());
    }
    // Otherwise, read N tuples of integers and return them as a transposed list
    else {
        vector<vector<int>> v(num);
        for (int i = 0; i < N; i++) {
            vector<int> t = II();
            for (int j = 0; j < num; j++) {
                v[j].push_back(t[j]);
            }
        }
        return v;
    }
}

// Function to determine the sign of a number
int my_sign(int x) {
    return (x > 0) - (x < 0);
}

// Function to determine the maximum absolute value and its properties
void solve() {
    int N = I();
    vector<int> a = III();

    int max_val = 0;
    int max_sign = 0;
    int max_index = -1;

    for (int i = 0; i < N; i++) {
        if (abs(a[i]) > max_val) {
            max_val = abs(a[i]);
            max_sign = my_sign(a[i]);
            max_index = i;
        }
    }

    if (max_sign == 0) {
        cout << 0 << endl;
    }
    else if (max_sign == 1) {
        cout << 2 * N - 1 << endl;
        for (int i = 0; i < N; i++) {
            cout << max_index + 1 << " " << i + 1 << endl;
        }
        for (int i = 0; i < N - 1; i++) {
            cout << i + 1 << " " << i + 2 << endl;
        }
    }
    else {
        cout << 2 * N - 1 << endl;
        for (int i = 0; i < N; i++) {
            cout << max_index + 1 << " " << i + 1 << endl;
        }
        for (int i = 1; i < N; i++) {
            cout << i + 1 << " " << i << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

