
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

int main() {
    int n, k;
    int as[MAX_N];
    int answer = 0;
    int isCalculate = 0;
    int lists[MAX_N][MAX_N];

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < MAX_N; j++) {
            lists[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        int j = as[i];
        if (0 < i) {
            lists[j][i] = 1;
        } else if (0 < j) {
            answer++;
        }
    }

    if (0 == isCalculate) {
        dfs(0, -1, k, lists, &answer, &isCalculate);
    }

    printf("%d\n", answer);

    return 0;
}

void dfs(int a, int pre, int k, int lists[MAX_N][MAX_N], int *answer, int *isCalculate) {
    int h = 0;

    for (int i = 0; i < MAX_N; i++) {
        if (lists[a][i] == 1) {
            h = max(h, dfs(i, a, k, lists, answer, isCalculate));
        }
    }

    if (0 < pre && h == k - 1) {
        h = 0;
        (*answer)++;
    } else {
        h++;
    }

    return h;
}

