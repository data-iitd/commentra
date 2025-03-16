
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

// This is the main function where the program starts execution.
// It reads two integers N and M from the standard input.
// Depending on the values of N and M, it calculates the number of cells in the grid.
// Finally, it prints the result to the standard output.
int main() {
    int N, M;
    int ans = 0;
    cin >> N >> M;
    // If both N and M are 1, there is only one cell, so the answer is 1.
    if (N == 1 && M == 1) {
        ans += 1;
    } else if (1 < N && 1 < M) {
        // If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
        ans += (N - 2) * (M - 2);
    } else {
        // If either N or M is 1, the number of cells is (N*M) - 2.
        ans += (N * M) - 2;
    }

    cout << ans << endl;
    return 0;
}

/*  ----------------------------------------  */

// This function returns the maximum value among the given integers.
int max(int x,...) {
    va_list args;
    int res = x;
    va_start(args, x);
    for (int i = 1; i < 10; i++) {
        res = max(res, va_arg(args, int));
    }
    va_end(args);
    return res;
}

// This function returns the minimum value among the given integers.
int min(int x,...) {
    va_list args;
    int res = x;
    va_start(args, x);
    for (int i = 1; i < 10; i++) {
        res = min(res, va_arg(args, int));
    }
    va_end(args);
    return res;
}

// This function returns x raised to the power of y.
int pow(int x, int y) { return pow(x, y); }

// This function returns the absolute value of x.
int abs(int x) { return abs(x); }

// This function returns the floor value of x.
int floor(int x) { return floor(x); }

// This type is a vector of integers that can be sorted by their absolute values.
struct SortBy {
    vector<int> v;
    bool operator()(int i, int j) { return abs(v[i]) < abs(v[j]); }
};

// Translate the above C++ code to Java and end with comment "