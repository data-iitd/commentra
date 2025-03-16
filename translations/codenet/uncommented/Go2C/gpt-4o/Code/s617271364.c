#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int N, A, B, C, ans;
int *arr;

void dfs(int *dp, int times);
int calc(int *dp);
int min(int a, int b);
int abs(int a);
char* nextLine();

int main() {
    char *line = nextLine();
    sscanf(line, "%d %d %d %d", &N, &A, &B, &C);
    free(line);

    arr = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        line = nextLine();
        sscanf(line, "%d", &arr[i]);
        free(line);
    }

    int *dp = (int *)malloc(N * sizeof(int));
    ans = 10000;
    dfs(dp, 0);
    free(dp);
    free(arr);

    printf("%d\n", ans);
    return 0;
}

void dfs(int *dp, int times) {
    if (times >= N) {
        ans = min(ans, calc(dp));
        return;
    }

    for (int i = 0; i < 4; i++) {
        dp[times] = i;
        dfs(dp, times + 1);
    }
}

int calc(int *dp) {
    int cost = 0, AA = 0, BB = 0, CC = 0;
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
            cost += 10000;
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

char* nextLine() {
    size_t size = 0;
    char *line = NULL;
    getline(&line, &size, stdin);
    return line;
}
