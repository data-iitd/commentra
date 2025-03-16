#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <assert.h>

#define MAX_N 1000000

typedef struct {
    int n;
    int k;
    int answer;
    bool isCalculate;
    int lists[MAX_N];
} Calculator;

int calculate(Calculator *c) {
    if (!c->isCalculate) {
        dfs(c, 0, 0);
        c->isCalculate = true;
    }
    return c->answer;
}

void dfs(Calculator *c, int a, int pre) {
    int h = 0;
    for (int i = 0; i < c->lists[a].n; i++) {
        h = max(h, dfs(c, c->lists[a].data[i], a));
    }
    if (0 < pre && h == c->k - 1) {
        h = 0;
        c->answer++;
    } else {
        h++;
    }
    return h;
}

int main(int argc, char *argv[]) {
    int n, k;
    int answer = 0;
    bool isCalculate = false;
    int lists[MAX_N];
    Calculator c;

    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int j;
        scanf("%d", &j);
        lists[i] = j - 1;
    }

    c.n = n;
    c.k = k;
    c.answer = answer;
    c.isCalculate = isCalculate;
    memcpy(c.lists, lists, sizeof(int) * n);

    answer = calculate(&c);
    printf("%d\n", answer);

    return 0;
}

