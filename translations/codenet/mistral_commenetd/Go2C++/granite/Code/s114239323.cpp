
// C++ code to solve the problem
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    vector<int> dp(N, 0);
    dp[1] = abs(h[0] - h[1]);

    for (int i = 2; i < N; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    cout << dp[N - 1] << endl;

    return 0;
}

// Helper functions to calculate the maximum, minimum, sum, and absolute difference of integers
int max(vector<int> a) {
    int r = a[0];
    for (int i = 0; i < a.size(); i++) {
        if (r < a[i]) {
            r = a[i];
        }
    }
    return r;
}

int min(vector<int> a) {
    int r = a[0];
    for (int i = 0; i < a.size(); i++) {
        if (r > a[i]) {
            r = a[i];
        }
    }
    return r;
}

int sum(vector<int> a) {
    int r = 0;
    for (int i = 0; i < a.size(); i++) {
        r += a[i];
    }
    return r;
}

int abs(int a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

// Helper function to read input from standard input as a single string
string nextString() {
    string s;
    getline(cin, s);
    return s;
}

// Helper function to read a single integer from standard input
int nextInt() {
    int v;
    cin >> v;
    return v;
}

// Helper function to read an array of N integers from standard input
vector<int> nextInts(int n) {
    vector<int> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
    return r;
}

// End of C++ code
