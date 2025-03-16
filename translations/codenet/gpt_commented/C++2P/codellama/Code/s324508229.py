#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Define macros for convenience
#define PB push_back
#define MP make_pair
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
    int n, ii, a, b; // Declare variables for input and indices
    cin >> n; // Read the upper limit of the range

    # <START-OF-CODE>
    # Initialize a 2D array to count occurrences of digit pairs
    cnt = [[0] * 10 for _ in range(10)]
    for i in range(100):
        b = i % 10
        a = i
        while a >= 10:
            a //= 10
        cnt[a][b] += 1

    ans = 0
    for i in range(1, 10):
        for j in range(1, 10):
            ans += cnt[i][j] * cnt[j][i]
    # 