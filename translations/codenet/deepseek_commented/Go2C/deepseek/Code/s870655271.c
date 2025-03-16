#include <stdio.h>
#include <math.h>

// This function returns the maximum value among the given integers.
int max(int x, int y) {
    return x > y ? x : y;
}

// This function returns the minimum value among the given integers.
int min(int x, int y) {
    return x < y ? x : y;
}

// This function returns x raised to the power of y.
int pow(int x, int y) {
    int result = 1;
    for (int i = 0; i < y; ++i) {
        result *= x;
    }
    return result;
}

// This function returns the absolute value of x.
int abs(int x) {
    return x < 0 ? -x : x;
}

// This function returns the floor value of x.
int floor(int x) {
    return (int)floor(x);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int ans = 0;

    // If both N and M are 1, there is only one cell, so the answer is 1.
    if (N == 1 && M == 1) {
        ans = 1;
    } else if (N > 1 && M > 1) {
        // If both N and M are greater than 1, the number of cells is (N-2)*(M-2).
        ans = (N - 2) * (M - 2);
    } else {
        // If either N or M is 1, the number of cells is (N*M) - 2.
        ans = (N * M) - 2;
    }

    printf("%d\n", ans);
    return 0;
}
