#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int n;
    int k;
    int *as;
} Input;

typedef struct {
    int k;
    int answer;
    int isCalculate;
    int **lists;
} Calculator;

void dfs(int a, int pre, int *h, int **lists, int *answer);

int main() {
    Input input;
    input.n = 0;
    input.k = 0;
    input.as = NULL;

    scanf("%d %d", &input.n, &input.k);

    input.as = (int *)malloc(input.n * sizeof(int));
    for (int i = 0; i < input.n; i++) {
        scanf("%d", &input.as[i]);
        input.as[i]--;
    }

    Calculator calc;
    calc.k = input.k;
    calc.answer = 0;
    calc.isCalculate = 0;

    calc.lists = (int **)malloc(input.n * sizeof(int *));
    for (int i = 0; i < input.n; i++) {
        calc.lists[i] = (int *)malloc(input.n * sizeof(int));
        memset(calc.lists[i], 0, input.n * sizeof(int));
    }

    for (int i = 0; i < input.n; i++) {
        int j = input.as[i];
        if (0 < i) {
            calc.lists[j][i] = 1;
        } else if (0 < j) {
            calc.answer++;
        }
    }

    if (!calc.isCalculate) {
        int *h = (int *)malloc(input.n * sizeof(int));
        dfs(0, -1, h, calc.lists, &calc.answer);
        calc.isCalculate = 1;
        free(h);
    }

    printf("%d\n", calc.answer);

    for (int i = 0; i < input.n; i++) {
        free(calc.lists[i]);
    }
    free(calc.lists);
    free(input.as);

    return 0;
}

void dfs(int a, int pre, int *h, int **lists, int *answer) {
    h[a] = 0;

    for (int i = 0; i < input.n; i++) {
        if (lists[a][i]) {
            dfs(i, a, h, lists, answer);
            h[a] = (h[a] > h[i] + 1) ? h[a] : h[i] + 1;
        }
    }

    if (0 < pre && h[a] == input.k - 1) {
        h[a] = 0;
        (*answer)++;
    } else {
        h[a]++;
    }
}

