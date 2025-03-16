#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100
#define INF 10000

int N, A, B, C;
int arr[MAX_N];
int ans;

void dfs(int *dp, int times, int *arr);
int calc(int *dp, int *arr);

int main() {
    char input[100];
    fgets(input, sizeof(input), stdin);
    char *token = strtok(input, " ");
    int index = 0;
    while (token != NULL) {
        if (index == 0) N = atoi(token);
        else if (index == 1) A = atoi(token);
        else if (index == 2) B = atoi(token);
        else if (index == 3) C = atoi(token);
        token = strtok(NULL, " ");
        index++;
    }

    for (int i = 0; i < N; i++) {
        fgets(input, sizeof(input), stdin);
        arr[i] = atoi(input);
    }

    int dp[MAX_N];
    ans = INF;
    dfs(dp, 0, arr);

    printf("%d\n", ans);
    return 0;
}

void dfs(int *dp, int times, int *arr) {
    if (times >= N) {
        int cost = calc(dp, arr);
        if (cost < ans) ans = cost;
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
        if (dp[i] == 1) AA += arr[i];
        else if (dp[i] == 2) BB += arr[i];
        else if (dp[i] == 3) CC += arr[i];
    }

    cost += abs(A - AA) + abs(B - BB) + abs(C - CC);

    for (int i = 1; i < 4; i++) {
        if (memo[i] < 1) {
            cost += INF;
        } else {
            cost += (memo[i] - 1) * 10;
        }
    }

    return cost;
}

int abs(int a) {
    return a < 0 ? -a : a;
}
