#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// This is the main function where the program starts execution.
int main() {
    int N, M;
    int ans = 0;
    cin >> N >> M;

    // If both N and M are 1, there is only one cell, so the answer is 1.
    if (N == 1 && M == 1) {
        ans += 1;
    } else if (N > 1 && M > 1) {
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
int max(int x, int y) {
    return (x > y) ? x : y;
}

// This function returns the minimum value among the given integers.
int min(int x, int y) {
    return (x < y) ? x : y;
}

// This function returns x raised to the power of y.
int pow(int x, int y) {
    return static_cast<int>(std::pow(x, y));
}

// This function returns the absolute value of x.
int abs(int x) {
    return std::abs(x);
}

// This function returns the floor value of x.
int floor(double x) {
    return static_cast<int>(std::floor(x));
}

// This function sorts a vector of integers by their absolute values.
struct SortBy {
    bool operator()(int a, int b) {
        return abs(a) < abs(b);
    }
};

// <END-OF-CODE>
