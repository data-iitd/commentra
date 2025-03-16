
#include <bits/stdc++.h>
using namespace std;

// Function to return an integer input
int I() {
    return int(cin.get());
}

// Function to return a list of integers as input
vector<int> III() {
    vector<int> a;
    for (int i = 0; i < 3; i++) {
        a.push_back(I());
    }
    return a;
}

// Function to create a list of lists based on the given number of rows and columns
vector<vector<int>> Line(int N, int num) {
    vector<vector<int>> a;
    if (N <= 0) {
        a.push_back(vector<int>(num, 0));
    } else if (num == 1) {
        for (int i = 0; i < N; i++) {
            a.push_back(III());
        }
    } else {
        for (int i = 0; i < N; i++) {
            vector<int> b;
            for (int j = 0; j < num; j++) {
                b.push_back(I());
            }
            a.push_back(b);
        }
    }
    return a;
}

// Function to return the sign of the given value
int my_sign(int a) {
    if (a > 0) {
        return 1;
    } else if (a < 0) {
        return -1;
    } else {
        return 0;
    }
}

// Main function
int main() {
    int N = I();
    vector<int> a = III();
    int max_val = 0;
    int max_sign = 0;
    int max_index = -1;
    for (int i = 0; i < N; i++) {
        int a0 = a[i];
        if (abs(a0) > max_val) {
            max_val = abs(a0);
            max_sign = my_sign(a0);
            max_index = i;
        }
    }
    if (max_sign == 0) {
        cout << 0 << endl;
    } else if (max_sign == 1) {
        cout << 2 * N - 1 << endl;
        cout << max_index + 1 << " " << 1 << endl;
        for (int i = 1; i < N; i++) {
            cout << i + 1 << " " << i + 2 << endl;
        }
    } else {
        cout << 2 * N - 1 << endl;
        cout << max_index + 1 << " " << 1 << endl;
        for (int i = N - 1; i > 0; i--) {
            cout << i + 1 << " " << i << endl;
        }
    }
    return 0;
}

