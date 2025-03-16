#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100
#define INF 10000

int N, A, B, C;
int arr[MAX_N];
int ans = INF;

void dfs(int *dp, int times, int *arr);
int calc(int *dp, int *arr);
int min(int a, int b);
int abs(int a);

int main() {
    char input[100];
    fgets(input, sizeof(input), stdin);
    char *token = strtok(input, " ");
    int i = 0;
    int values[4];
    while (token != NULL) {
        values[i] = atoi(token);
        token = strtok(NULL, " ");
        i++;
    }
    N = values[0];
    A = values[1];
    B = values[2];
    C = values[3];

    for (int i = 0; i < N; i++) {
        fgets(input, sizeof(input), stdin);
        arr[i] = atoi(input);
    }

    int dp[N];
    dfs(dp, 0, arr);

    printf("%d\n", ans);
    return 0;
}

void dfs(int *dp, int times, int *arr) {
    if (times >= N) {
        ans = min(ans, calc(dp, arr));
        return;
    }

    for (int i = 0; i < 4; i++) {
        dp[times] = i;
        dfs(dp, times + 1, arr);
    }
}

int calc(int *dp, int *arr) {
    int cost = 0;
    int AA = 0, BB = 0, CC = 0;
    int memo[4] = {0};

    for (int i = 0; i < N; i++) {
        memo[dp[i]]++;
        if (dp[i] == 1) {
            AA += arr[i];
        } else if (dp[i] == 2) {
            BB += arr[i];
        } else if (dp[i] == 3) {
            CC += arr[i];
        }
    }

    cost += abs(A - AA) + abs(B - BB) + abs(C - CC);

    for (int i = 1; i < 4; i++) {
        int a = memo[i];
        if (a < 1) {
            cost += INF;
        } else {
            cost += (a - 1) * 10;
        }
    }

    return cost;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int abs(int a) {
    return a < 0 ? -a : a;
}
