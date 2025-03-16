#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_N 100000
#define INF 1000000000

int N, A, B, C;
int arr[MAX_N];
int dp[MAX_N][4];
int ans = INF;
int ss;

void dfs(int dp[MAX_N][4], int times, int arr[]) {
    if (times >= N) {
        ans = min(ans, calc(dp, arr));
        return;
    }

    for (int i = 0; i < 4; i++) {
        dp[times][i] = i;
        dfs(dp, times+1, arr);
    }
}

int calc(int dp[MAX_N][4], int arr[]) {
    int cost = 0;
    int AA = 0, BB = 0, CC = 0;
    int memo[4] = {0};
    for (int i = 0; i < N; i++) {
        memo[dp[i][0]]++;
        if (dp[i][0] == 1) {
            AA += arr[i];
        } else if (dp[i][0] == 2) {
            BB += arr[i];
        } else if (dp[i][0] == 3) {
            CC += arr[i];
        }
    }
    cost += abs(A-AA) + abs(B-BB) + abs(C-CC);

    for (int i = 1; i < 4; i++) {
        if (memo[i] < 1) {
            cost += 10000;
        } else {
            cost += (memo[i] - 1) * 10;
        }
    }

    return cost;
}

int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int abs(int a) {
    if (a < 0) {
        return a * -1;
    }
    return a;
}

int main() {
    scanf("%d %d %d %d", &N, &A, &B, &C);
    ss = A + B + C;
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    dfs(dp, 0, arr);
    printf("%d\n", ans);
    return 0;
}

